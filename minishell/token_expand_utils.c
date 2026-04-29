/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token_expand_utils.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkyaw <lkyaw@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/29 21:28:37 by lkyaw             #+#    #+#             */
/*   Updated: 2026/04/29 21:28:37 by lkyaw            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

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

int	is_quote(char c, int *in_single, int *in_double)
{
	if (c == '\'' && !(*in_double))
	{
		*in_single = !(*in_single);
		return (1);
	}
	if (c == '"' && !(*in_single))
	{
		*in_double = !(*in_double);
		return (1);
	}
	return (0);
}

char	*append_char(char *res, char c)
{
	char	*new;
	int		len;

	len = 0;
	if (res)
		len = ft_strlen(res);
	new = malloc(len + 2);
	if (!new)
	{
		free(res);
		return (NULL);
	}
	if (res)
		ft_memcpy(new, res, len);
	new[len] = c;
	new[len + 1] = '\0';
	free(res);
	return (new);
}

char	*append_str(char *res, const char *add)
{
	char	*new;
	int		len1;
	int		len2;

	len1 = 0;
	if (res)
		len1 = ft_strlen(res);
	len2 = 0;
	if (add)
		len2 = ft_strlen(add);
	new = malloc(len1 + len2 + 1);
	if (!new)
	{
		free(res);
		return (NULL);
	}
	if (res)
		ft_memcpy(new, res, len1);
	if (add)
		ft_memcpy(new + len1, add, len2);
	new[len1 + len2] = '\0';
	free(res);
	return (new);
}
