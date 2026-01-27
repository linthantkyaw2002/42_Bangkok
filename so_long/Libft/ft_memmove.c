/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkyaw <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/30 10:32:20 by lkyaw             #+#    #+#             */
/*   Updated: 2025/08/30 16:16:31 by lkyaw            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <stdio.h>
#include "libft.h"

void	*ft_memmove(void *dest, const void *src, unsigned long n)
{
	unsigned long	i;
	char			*d;
	const char		*s;
	char			temp[100];

	i = 0;
	d = dest;
	s = src;
	if (!dest && !src)
		return (NULL);
	while (i < n)
	{
		temp[i] = s[i];
		i++;
	}
	i = 0;
	while (i < n)
	{
		d[i] = temp[i];
		i++;
	}
	return (d);
}
/*
int	main(void)
{
	char	src[10]= "dsafadf";
	char	dest[10];
	char	*p;

	p = ft_memmove(dest, src, 5);
	p[5] = '\0';
	printf("%s\n", p);
}*/
