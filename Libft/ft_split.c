/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkyaw <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/31 14:24:36 by lkyaw             #+#    #+#             */
/*   Updated: 2025/08/31 16:00:36 by lkyaw            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <stdio.h>

int	ft_substrcount(char const *s, char c)
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

void	**ft_malword(char const *s, char c, char **arr)
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
		if (s[i] != c)
		{
			count++;
			in_word = 1;
		}
		if ((s[i] == c && in_word) || (s[i + 1] == '\0' && in_word))
		{
			arr[++index] = malloc(count + 1);
			if (!arr[index])
				return (NULL);
			count = 0;
			in_word = 0;
		}
	}
}

char	**ft_split(char const *s, char c)
{
	char	**arr;

	arr = (char **)malloc(ft_substrcount(s, c) + 1);
}
/*
int	main(void)
{
	char	*str= " fdsfdaf dfdaf   dfd aaa aa  ";
	char	c = ' ';

	printf("%d\n", ft_substrcount(str, c));
}*/
