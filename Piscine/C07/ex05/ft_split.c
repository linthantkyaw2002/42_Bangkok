/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkyaw <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/28 20:48:14 by lkyaw             #+#    #+#             */
/*   Updated: 2025/07/28 20:49:27 by lkyaw            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	is_in_charset(char c, char *charset)
{
	while (*charset)
	{
		if (c == *charset)
			return (1);
		charset++;
	}
	return (0);
}

int	count_words(char *str, char *charset)
{
	int	count;
	int	in_word;

	count = 0;
	in_word = 0;
	while (*str)
	{
		if (is_in_charset(*str, charset))
			in_word = 0;
		else if (!in_word)
		{
			count++;
			in_word = 1;
		}
		str++;
	}
	return (count);
}

int	get_word_len(char *str, char *charset)
{
	int	len;

	len = 0;
	while (str[len] && !is_in_charset(str[len], charset))
		len++;
	return (len);
}

char	*malloc_word(char *str, char *charset)
{
	int		len;
	int		i;
	char	*word;

	len = get_word_len(str, charset);
	word = malloc(len + 1);
	if (!word)
		return (NULL);
	i = 0;
	while (i < len)
	{
		word[i] = str[i];
		i++;
	}
	word[i] = '\0';
	return (word);
}

char	**ft_split(char *str, char *charset)
{
	char	**result;
	int		i;

	result = malloc((count_words(str, charset) + 1) * sizeof(char *));
	if (!result)
		return (NULL);
	i = 0;
	while (*str)
	{
		while (*str && is_in_charset(*str, charset))
			str++;
		if (*str)
		{
			result[i] = malloc_word(str, charset);
			if (!result[i])
				return (NULL);
			i++;
			str += get_word_len(str, charset);
		}
	}
	result[i] = NULL;
	return (result);
}
