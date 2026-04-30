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

int	check_syntax(t_token *t)
{
	t_token	*p;

	p = NULL;
	while (t)
	{
		if ((t->type == TOKEN_PIPE && (!p || p->type == TOKEN_PIPE
					|| !t->next)) || (t->type >= TOKEN_REDIRECT_IN
				&& t->type <= TOKEN_HEREDOC
				&& (!t->next || t->next->type != TOKEN_WORD)))
		{
			ft_putstr_fd("minishell: syntax error near unexpected token `", 2);
			if (t->type == TOKEN_PIPE)
				ft_putstr_fd("|", 2);
			else if (!t->next)
				ft_putstr_fd("newline", 2);
			else
				ft_putstr_fd(t->next->value, 2);
			ft_putendl_fd("'", 2);
			return (0);
		}
		p = t;
		t = t->next;
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

char	*strip_quotes(char *str)
{
	char	*res;
	int		i;
	int		j;

	if (!str)
		return (NULL);
	res = malloc(sizeof(char) * (ft_strlen(str) + 1));
	if (!res)
		return (NULL);
	i = 0;
	j = 0;
	while (str[i])
	{
		if (str[i] != '\'' && str[i] != '\"')
			res[j++] = str[i];
		i++;
	}
	res[j] = '\0';
	return (res);
}
