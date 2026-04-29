/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand_list.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkyaw <lkyaw@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/29 21:23:43 by lkyaw             #+#    #+#             */
/*   Updated: 2026/04/29 21:23:43 by lkyaw            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	has_quotes(char *str)
{
	while (*str)
	{
		if (*str == '\'' || *str == '\"')
			return (1);
		str++;
	}
	return (0);
}

static void	free_arr(char **arr)
{
	int	i;

	i = 0;
	if (!arr)
		return ;
	while (arr[i])
		free(arr[i++]);
	free(arr);
}

static t_token	*insert_split_tokens(t_token *curr, char *expanded)
{
	char	**arr;
	t_token	*new_node;
	int		i;

	arr = ft_split(expanded, ' ');
	if (!arr || !arr[0])
	{
		curr->value = ft_strdup("");
		free_arr(arr);
		return (curr);
	}
	curr->value = ft_strdup(arr[0]);
	i = 1;
	while (arr[i])
	{
		new_node = malloc(sizeof(t_token));
		new_node->value = ft_strdup(arr[i]);
		new_node->type = TOKEN_WORD;
		new_node->next = curr->next;
		curr->next = new_node;
		curr = new_node;
		i++;
	}
	free_arr(arr);
	return (curr);
}

void	expand_list(t_shell *shell)
{
	t_token	*tmp;
	char	*expanded;

	tmp = shell->tokens;
	while (tmp)
	{
		expanded = expand_string(tmp->value, shell);
		if (!has_quotes(tmp->value) && expanded && ft_strchr(expanded, ' '))
		{
			free(tmp->value);
			tmp = insert_split_tokens(tmp, expanded);
			free(expanded);
		}
		else
		{
			free(tmp->value);
			tmp->value = expanded;
		}
		tmp = tmp->next;
	}
}
