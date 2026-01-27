/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkyaw <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/30 09:49:20 by lkyaw             #+#    #+#             */
/*   Updated: 2025/08/30 10:10:57 by lkyaw            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <stdio.h>
#include "libft.h"

void	ft_bzero(void *s, unsigned long n)
{
	unsigned long	i;
	char			*p;

	i = 0;
	p = s;
	while (i < n)
	{
		*(p + i) = '\0';
		i++;
	}
}
/*
int	main(void)
{
	char	p[10] = {'a','5','4','2'};

	ft_bzero(p, 2);
	for(int i = 0; i < 10; i++)
	{
		if (p[i] == '\0')
			printf("%d:empty, ", i);
		else
			printf("%d:%c, ", i, p[i]);
	}
	printf("\n");
}*/
