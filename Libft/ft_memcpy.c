/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkyaw <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/30 10:17:16 by lkyaw             #+#    #+#             */
/*   Updated: 2025/08/30 16:15:53 by lkyaw            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <stdio.h>
#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, unsigned long n)
{
	unsigned long	i;
	char			*d;
	const char		*s;

	if (!dest && !src)
		return (NULL);
	i = 0;
	d = dest;
	s = src;
	while (i < n)
	{
		*(d + i) = *(s + i);
		i++;
	}
	return (d);
}
/*
int	main(void)
{
	char	dest[10];
	char	src[20]= "adfoiadfafdsf";
	char	*p;

	p = ft_memcpy(dest, src, 5);
	p[5] = '\0';
	printf("%s\n", p);
}*/
