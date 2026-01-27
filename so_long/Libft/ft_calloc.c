/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkyaw <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/30 15:33:46 by lkyaw             #+#    #+#             */
/*   Updated: 2025/08/30 21:01:01 by lkyaw            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <stdio.h>
//#include <stdlib.h>
#include "libft.h"

void	*ft_calloc(long nelem, long elsize)
{
	char			*array;
	unsigned int	n;
	unsigned int	i;

	if (nelem == 0 || elsize == 0)
		return ((void *)malloc(1));
	if (nelem < 0 || elsize < 0)
		return (NULL);
	i = 0;
	n = (unsigned int)nelem * (unsigned int)elsize;
	if (n / (unsigned int)elsize != (unsigned int)nelem)
		return (NULL);
	array = malloc(n);
	if (!array)
		return (NULL);
	while (i < n)
	{
		array[i] = 0;
		i++;
	}
	return ((void *)array);
}
/*
int	main(void)
{
	char	*p;

	p = calloc(10, 4);
	if (!p)
		return 1;
	for(int i; i < 10 * 4; i++)
		printf("%i", p[i]);
	free(p);
}*/
