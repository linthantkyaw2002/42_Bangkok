/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkyaw <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/30 12:14:43 by lkyaw             #+#    #+#             */
/*   Updated: 2025/08/30 12:25:47 by lkyaw            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <stdio.h>
#include "libft.h"

unsigned long	ft_strlcat(char *dst, const char *src, unsigned long size)
{
	unsigned long	d_i;
	unsigned long	s_i;
	unsigned long	i;

	i = 0;
	d_i = 0;
	s_i = 0;
	while (d_i < size && dst[d_i])
		d_i++;
	while (src[s_i])
		s_i++;
	if (size <= d_i)
		return (size + s_i);
	while (src[i] && (d_i + i < size - 1))
	{
		dst[d_i + i] = src[i];
		i++;
	}
	dst[d_i + i] = '\0';
	return (d_i + s_i);
}
/*
int	main(void)
{
	char	str[] = "world";
	char	dest[11] = "hello";
	printf("%lu\n", ft_strlcat(dest, str, 8));
	printf("%s\n", dest);
}*/
