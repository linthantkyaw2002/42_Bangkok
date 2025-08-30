/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkyaw <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/30 14:20:53 by lkyaw             #+#    #+#             */
/*   Updated: 2025/08/30 14:33:22 by lkyaw            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <stdio.h>
#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, unsigned long n)
{
	unsigned long			i;
	const unsigned char		*p1;
	const unsigned char		*p2;

	i = 0;
	p1 = (const unsigned char *)s1;
	p2 = (const unsigned char *)s2;
	while (i < n)
	{
		if (p1[i] != p2[i])
			return (p1[i] - p2[i]);
		i++;
	}
	return (0);
}
/*
int	main(void)
{
	char	*str = "hello";
	char	*str1 = "hell0";

	printf("%d\n", ft_memcmp(str, str1, 4));
	printf("%d\n", ft_memcmp(str, str1, 5));
}*/
