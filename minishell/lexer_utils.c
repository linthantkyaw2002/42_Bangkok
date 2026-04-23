#include "minishell.h"

void	add_back(t_token **list, t_token *new)
{
	t_token	*tmp;

	if (!new)
		return ;
	if (!*list)
	{
		*list = new;
		return ;
	}
	tmp = *list;
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = new;
}

void	free_tokens(t_token *list)
{
	t_token	*tmp;

	while (list)
	{
		tmp = list->next;
		free(list->value);
		free(list);
		list = tmp;
	}
}

int	ft_isspace(char c)
{
	return (c == ' ' || (c >= 9 && c <= 13));
}

int	ft_strcmp(const char *s1, const char *s2)
{
	size_t	i;

	i = 0;
	while (s1[i] && s2[i] && s1[i] == s2[i])
		i++;
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}

static int	syntax_error(char *token_val)
{
	ft_putstr_fd("minishell: syntax error near unexpected token `", 2);
	ft_putstr_fd(token_val, 2);
	ft_putendl_fd("'", 2);
	return (0);
}

int	check_syntax(t_token *tokens)
{
	t_token	*prev;

	prev = NULL;
	while (tokens)
	{
		if (tokens->type == TOKEN_PIPE)
		{
			if (!prev || prev->type == TOKEN_PIPE || !tokens->next)
				return (syntax_error("|"));
		}
		else if (tokens->type >= TOKEN_REDIRECT_IN
			&& tokens->type <= TOKEN_HEREDOC)
		{
			if (!tokens->next)
				return (syntax_error("newline"));
			if (tokens->next->type != TOKEN_WORD)
				return (syntax_error(tokens->next->value));
		}
		prev = tokens;
		tokens = tokens->next;
	}
	return (1);
}