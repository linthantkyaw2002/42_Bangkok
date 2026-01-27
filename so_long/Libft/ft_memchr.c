/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkyaw <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/30 14:02:55 by lkyaw             #+#    #+#             */
/*   Updated: 2025/08/30 14:20:11 by lkyaw            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <stdio.h>
#include "libft.h"

void	*ft_memchr(const void *s, int c, unsigned long n)
{
	const char		*p;
	unsigned long	i;
	char			j;

	i = 0;
	p = s;
	j = c;
	while (i < n)
	{
		if (p[i] == j)
			return ((void *)(p + i));
		i++;
	}
	return (NULL);
}
/*
int	main(void)
{
	char	str[] = "helloworld";
	char	*p;

	p = ft_memchr(str, 'e', 7);
	printf("%s\n", p);
}*/
