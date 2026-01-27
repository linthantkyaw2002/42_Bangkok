/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isascii.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkyaw <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/27 15:40:08 by lkyaw             #+#    #+#             */
/*   Updated: 2025/08/27 15:50:05 by lkyaw            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <stdio.h>
#include "libft.h"

int	ft_isascii(int c)
{
	return (c >= 0 && c <= 127);
}
/*
int	main(void)
{
	char	c = '\0' -1;
	char	i = '0';
	char	y = '\t';

	printf("%d\n", ft_isascii(c));
	printf("%d\n", ft_isascii(i));
	printf("%d\n", ft_isascii(y));
}*/
