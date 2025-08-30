/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkyaw <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/30 09:05:47 by lkyaw             #+#    #+#             */
/*   Updated: 2025/08/30 09:57:41 by lkyaw            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <stdio.h>
#include "libft.h"

void	*ft_memset(void *s, int c, unsigned long n)
{
	unsigned long	i;
	char			*p;

	p = s;
	i = 0;
	while (i < n)
	{
		*(p + i) = c;
		i++;
	}
	return ((void *)p);
}
/*
int	main(void)
{
	char	c = 'c';
	char	p[100];

	ft_memset(p, c, 8);
	printf("%s\n", p);
}*/
