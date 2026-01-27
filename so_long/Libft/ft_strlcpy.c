/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkyaw <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/30 11:57:12 by lkyaw             #+#    #+#             */
/*   Updated: 2025/08/30 18:21:34 by lkyaw            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <stdio.h>
#include "libft.h"

unsigned long	ft_strlcpy(char *dst, const char *src, unsigned long size)
{
	unsigned long	i;

	i = 0;
	if (size > 0)
	{
		while (src[i] && i < size -1)
		{
			dst[i] = src[i];
			i++;
		}
		dst[i] = '\0';
	}
	i = 0;
	while (src[i])
		i++;
	return (i);
}
/*
int	main(void)
{
	char	*src = "";
	char	dest[10];

	printf("length:%lu\n", ft_strlcpy(dest, src, 4));
}*/
