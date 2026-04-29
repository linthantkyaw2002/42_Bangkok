/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_list_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkyaw <lkyaw@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/29 20:57:12 by lkyaw             #+#    #+#             */
/*   Updated: 2026/04/29 20:57:12 by lkyaw            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_cmd	*new_cmd(void)
{
	t_cmd	*cmd;

	cmd = malloc(sizeof(t_cmd));
	if (!cmd)
		return (NULL);
	cmd->args = NULL;
	cmd->infile = -1;
	cmd->outfile = -1;
	cmd->error = 0;
	cmd->next = NULL;
	return (cmd);
}

int	count_args(t_token *tokens)
{
	int	count;

	count = 0;
	while (tokens && tokens->type != TOKEN_PIPE)
	{
		if (tokens->type >= TOKEN_REDIRECT_IN && tokens->type <= TOKEN_HEREDOC)
		{
			tokens = tokens->next;
			if (tokens)
				tokens = tokens->next;
			continue ;
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
		if (tokens->type >= TOKEN_REDIRECT_IN && tokens->type <= TOKEN_HEREDOC)
		{
			tokens = tokens->next;
			if (tokens)
				tokens = tokens->next;
			continue ;
		}
		if (tokens->type == TOKEN_WORD)
			cmd->args[i++] = ft_strdup(tokens->value);
		tokens = tokens->next;
	}
	cmd->args[i] = NULL;
}

void	free_cmds(t_cmd *head)
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
