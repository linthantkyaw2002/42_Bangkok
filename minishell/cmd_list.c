/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_list.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkyaw <lkyaw@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/29 20:57:42 by lkyaw             #+#    #+#             */
/*   Updated: 2026/04/29 20:57:42 by lkyaw            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

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

static void	advance_token(t_token **tokens, t_cmd *cmd, t_shell *shell)
{
	if (!*tokens)
		return ;
	if ((*tokens)->type >= TOKEN_REDIRECT_IN
		&& (*tokens)->type <= TOKEN_HEREDOC)
		handle_redirection(cmd, tokens, shell);
	if (*tokens)
		*tokens = (*tokens)->next;
}

static int	handle_pipe(t_cmd **curr, t_token **tokens, t_cmd *head)
{
	if (*tokens && (*tokens)->type == TOKEN_PIPE)
	{
		(*curr)->next = new_cmd();
		if (!(*curr)->next)
		{
			free_cmds(head);
			return (0);
		}
		*curr = (*curr)->next;
		*tokens = (*tokens)->next;
	}
	return (1);
}

t_cmd	*parse_tokens(t_token *tokens, t_shell *shell)
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
			advance_token(&tokens, curr, shell);
		if (!handle_pipe(&curr, &tokens, head))
			return (NULL);
	}
	return (head);
}
