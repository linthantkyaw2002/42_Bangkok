/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand_list.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkyaw <lkyaw@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/30 21:07:15 by lkyaw             #+#    #+#             */
/*   Updated: 2026/04/30 21:07:15 by lkyaw            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static t_token	*insert_split_tokens(t_token *curr, char *exp)
{
	char	**arr;
	t_token	*new_n;
	int		i;

	arr = ft_split(exp, ' ');
	if (!arr || !arr[0])
		curr->value = ft_strdup("");
	else
		curr->value = ft_strdup(arr[0]);
	i = 1;
	while (arr && arr[0] && arr[i])
	{
		new_n = malloc(sizeof(t_token));
		new_n->value = ft_strdup(arr[i]);
		new_n->type = TOKEN_WORD;
		new_n->next = curr->next;
		curr->next = new_n;
		curr = new_n;
		i++;
	}
	i = 0;
	while (arr && arr[i])
		free(arr[i++]);
	return (free(arr), curr);
}

static t_token	*remove_token(t_shell *shell, t_token *tmp, t_token *prev)
{
	t_token	*next;

	next = tmp->next;
	if (prev)
		prev->next = next;
	else
		shell->tokens = next;
	free(tmp->value);
	free(tmp);
	return (next);
}

static t_token	*split_word(t_token *t, t_token **p, char *exp)
{
	free(t->value);
	t = insert_split_tokens(t, exp);
	free(exp);
	while (*p && (*p)->next != t->next)
		*p = (*p)->next;
	return (t->next);
}

static t_token	*process_expansion(t_shell *sh, t_token *t, t_token **p,
		char *ex)
{
	int	is_r;

	is_r = (*p && (*p)->type >= TOKEN_REDIRECT_IN
			&& (*p)->type <= TOKEN_APPEND);
	if (!has_quotes(t->value))
	{
		if (is_r && (ex[0] == '\0' || ft_strchr(ex, ' ')))
		{
			t->type = TOKEN_AMBIGUOUS;
			free(ex);
			*p = t;
			return (t->next);
		}
		else if (ex[0] == '\0' && t->type == TOKEN_WORD)
			return (free(ex), remove_token(sh, t, *p));
		else if (ft_strchr(ex, ' ') && t->type == TOKEN_WORD)
			return (split_word(t, p, ex));
	}
	free(t->value);
	t->value = ex;
	*p = t;
	return (t->next);
}

void	expand_list(t_shell *shell)
{
	t_token	*tmp;
	t_token	*prev;
	char	*exp;

	tmp = shell->tokens;
	prev = NULL;
	while (tmp)
	{
		if (prev && prev->type == TOKEN_HEREDOC)
		{
			prev = tmp;
			tmp = tmp->next;
			continue ;
		}
		exp = expand_string(tmp->value, shell);
		tmp = process_expansion(shell, tmp, &prev, exp);
	}
}
