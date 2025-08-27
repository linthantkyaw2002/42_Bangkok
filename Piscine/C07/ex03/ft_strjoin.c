/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkyaw <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/28 17:38:28 by lkyaw             #+#    #+#             */
/*   Updated: 2025/07/28 18:23:32 by lkyaw            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_strlen(char	*str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*ft_strcat(char *dest, char *src)
{
	int	i;
	int	n;

	i = 0;
	while (dest[i])
		i++;
	n = 0;
	while (src[n])
	{
		dest[n + i] = src[n];
		n++;
	}
	dest[n + i] = '\0';
	return (dest);
}

int	total_len(int size, char **strs, char *sep)
{
	int	t;
	int	i;

	i = 0;
	t = 0;
	while (i < size)
	{
		t += ft_strlen(strs[i]);
		i++;
	}
	t += ft_strlen(sep) * (size - 1);
	return (t);
}

char	*ft_strjoin(int size, char **strs, char *sep)
{
	int		i;
	char	*arr;

	if (size == 0)
	{
		arr = (char *)malloc(1);
		if (arr)
			arr[0] = '\0';
		return (arr);
	}
	arr = (char *)malloc((total_len(size, strs, sep)) * sizeof(char));
	if (!arr)
		return (NULL);
	arr[0] = '\0';
	i = 0;
	while (i < size)
	{
		ft_strcat(arr, strs[i]);
		if (i < size -1)
			ft_strcat(arr, sep);
		i++;
	}
	return (arr);
}
