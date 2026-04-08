t_cmd	*new_cmd(void)
{
	t_cmd	*cmd;

	cmd = malloc(sizeof(t_cmd));
	if (!cmd)
		return (NULL);
	cmd->args = NULL;
	cmd->infile = -1;
	cmd->outfile = -1;
	cmd->append = 0;
	cmd->heredoc = 0;
	cmd->next = NULL;
	return (cmd);
}

int	count_args(t_token *tokens)
{
	int	count;

	count = 0;
	while (tokens && tokens->type != TOKEN_PIPE)
	{
		if (tokens->type >= TOKEN_REDIRECT_IN
			&& tokens->type <= TOKEN_HEREDOC)
		{
			tokens = tokens->next;
			if (tokens)
				tokens = tokens->next;
			continue;
		}
		if (tokens->type == TOKEN_WORD)
			count++;
		tokens = tokens->next;
	}
	return (count);
}

void	fill_args(t_cmd *cmd, t_token *tokens)
{
	int	i;

	i = 0;
	while (tokens && tokens->type != TOKEN_PIPE)
	{
		if (tokens->type >= TOKEN_REDIRECT_IN
			&& tokens->type <= TOKEN_HEREDOC)
		{
			tokens = tokens->next;
			if (tokens)
				tokens = tokens->next;
			continue;
		}
		if (tokens->type == TOKEN_WORD)
			cmd->args[i++] = ft_strdup(tokens->value);
		tokens = tokens->next;
	}
	cmd->args[i] = NULL;
}

static int	allocate_and_fill(t_cmd *cmd, t_token *tokens)
{
	int	count;

	count = count_args(tokens);
	cmd->args = malloc(sizeof(char *) * (count + 1));
	if (!cmd->args)
		return (0);
	fill_args(cmd, tokens);
	return (1);
}

void	handle_redirection(t_cmd *cmd, t_token **tokens)
{
	t_token	*tmp;

	tmp = *tokens;
	if (!tmp || !tmp->next)
	{
		if (tmp)
			*tokens = tmp->next;
		return;
	}
	if (tmp->type == TOKEN_REDIRECT_IN)
		cmd->infile = open(tmp->next->value, O_RDONLY);
	else if (tmp->type == TOKEN_REDIRECT_OUT)
		cmd->outfile = open(tmp->next->value,
				O_CREAT | O_WRONLY | O_TRUNC, 0644);
	else if (tmp->type == TOKEN_APPEND)
		cmd->outfile = open(tmp->next->value,
				O_CREAT | O_WRONLY | O_APPEND, 0644);
	*tokens = tmp->next;
}

static void	free_cmds(t_cmd *head)
{
	t_cmd	*tmp;
	int		idx;

	while (head)
	{
		tmp = head->next;
		if (head->args)
		{
			idx = 0;
			while (head->args[idx])
				free(head->args[idx++]);
			free(head->args);
		}
		free(head);
		head = tmp;
	}
}


static void	advance_token(t_token **tokens, t_cmd *cmd)
{
	if (!*tokens)
		return;
	if ((*tokens)->type >= TOKEN_REDIRECT_IN
		&& (*tokens)->type <= TOKEN_HEREDOC)
		handle_redirection(cmd, tokens);
	if (*tokens)
		*tokens = (*tokens)->next;
}

t_cmd	*parse_tokens(t_token *tokens)
{
	t_cmd	*head;
	t_cmd	*curr;

	head = new_cmd();
	if (!head)
		return (NULL);
	curr = head;
	while (tokens)
	{
		if (!allocate_and_fill(curr, tokens))
		{
			free_cmds(head);
			return (NULL);
		}
		while (tokens && tokens->type != TOKEN_PIPE)
			advance_token(&tokens, curr);
		if (tokens && tokens->type == TOKEN_PIPE)
		{
			curr->next = new_cmd();
			if (!curr->next)
			{
				free_cmds(head);
				return (NULL);
			}
			curr = curr->next;
			tokens = tokens->next;
		}
	}
	return (head);
}
