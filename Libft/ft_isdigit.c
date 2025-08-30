/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkyaw <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/27 15:18:24 by lkyaw             #+#    #+#             */
/*   Updated: 2025/08/27 15:24:21 by lkyaw            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <stdio.h>
#include "libft.h"

int	ft_isdigit(int c)
{
	return (c >= '0' && c <= '9');
}
/*
int	main(void)
{
	char	c = '0';
	char	i = 'a';
	char	j = '\\';

	printf("%d\n", ft_isdigit(c));
	printf("%d\n", ft_isdigit(i));
	printf("%d\n", ft_isdigit(j));
}*/
