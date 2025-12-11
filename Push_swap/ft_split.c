/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkyaw <lkyaw@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/10 08:50:00 by lkyaw             #+#    #+#             */
/*   Updated: 2025/12/10 08:50:00 by lkyaw            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* Count the number of substrings separated by delimiter c */
static int	ft_substrcount(char const *s, char c)
{
	int	i;
	int	flag;
	int	count;

	i = 0;
	flag = 0;
	count = 0;
	while (s[i])
	{
		if (flag == 0 && s[i] != c)
		{
			count++;
			flag = 1;
		}
		else if (s[i] == c)
			flag = 0;
		i++;
	}
	return (count);
}

/* Free allocated memory in case of failure */
static void	ft_freearr(char **arr, int last)
{
	while (last >= 0)
		free(arr[last--]);
	free(arr);
}

/* Allocate memory for each substring */
static int	ft_malword(char const *s, char c, char **arr)
{
	int	i;
	int	index;
	int	count;
	int	in_word;

	i = -1;
	index = -1;
	count = 0;
	in_word = 0;
	while (s[++i])
	{
		if (s[i] != c && ++count > 0)
			in_word = 1;
		if ((s[i] == c && in_word) || (s[i + 1] == '\0' && in_word))
		{
			arr[++index] = malloc(count + 1);
			if (!(arr[index]))
				return (ft_freearr(arr, index - 1), 0);
			count = 0;
			in_word = 0;
		}
	}
	return (1);
}

/* Copy substrings into allocated memory */
static void	ft_subcpy(char const *s, char c, char **arr)
{
	int	i;
	int	j;
	int	index;

	i = 0;
	index = 0;
	while (s[i])
	{
		if (s[i] != c)
		{
			j = 0;
			while (s[i] && s[i] != c)
			{
				arr[index][j] = s[i++];
				j++;
			}
			arr[index][j] = '\0';
			index++;
		}
		else
			i++;
	}
}

/* Main split function */
char	**ft_split(char const *s, char c)
{
	char	**arr;
	int		strct;

	if (!s)
		return (NULL);
	strct = ft_substrcount(s, c);
	arr = (char **)malloc(sizeof(char *) * (strct + 1));
	if (!arr)
		return (NULL);
	if (!ft_malword(s, c, arr))
		return (NULL);
	ft_subcpy(s, c, arr);
	arr[strct] = NULL;
	return (arr);
}
