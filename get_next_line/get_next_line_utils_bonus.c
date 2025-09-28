/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkyaw <lkyaw@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/28 13:58:40 by lkyaw             #+#    #+#             */
/*   Updated: 2025/09/28 14:30:02 by lkyaw            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i])
		i++;
	return (i);
}

int	ft_strchr_index(const char *s, int c)
{
	int		i;
	char	j;

	i = 0;
	j = (char)c;
	if (!s)
		return (-1);
	while (s[i])
	{
		if (s[i] == j)
			return (i);
		i++;
	}
	return (-1);
}

char	*ft_strdup(const char *src)
{
	size_t	len;
	char	*arr;
	size_t	i;

	i = 0;
	len = ft_strlen(src);
	arr = malloc(len + 1);
	if (!arr)
		return (NULL);
	while (src[i])
	{
		arr[i] = src[i];
		i++;
	}
	arr[i] = '\0';
	return (arr);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*str;
	size_t	i;
	size_t	s_len;

	s_len = ft_strlen(s);
	if (!s || start >= s_len || len == 0)
		return (ft_strdup(""));
	if (len > s_len - start)
		len = (s_len - start);
	str = malloc(len + 1);
	if (!str)
		return (NULL);
	i = 0;
	while (i < len)
	{
		str[i] = s[start + i];
		i++;
	}
	str[i] = '\0';
	return (str);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*str;
	int		i;
	int		j;

	if (!s1)
		s1 = ft_strdup("");
	if (!s1 || !s2)
		return (NULL);
	str = malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	if (!str)
		return (NULL);
	i = -1;
	while (s1[++i])
		str[i] = s1[i];
	j = -1;
	while (s2[++j])
		str[j + i] = s2[j];
	str[j + i] = '\0';
	free(s1);
	return (str);
}
