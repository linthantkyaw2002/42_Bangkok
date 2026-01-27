/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkyaw <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/27 15:36:43 by lkyaw             #+#    #+#             */
/*   Updated: 2025/08/27 15:39:38 by lkyaw            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <stdio.h>
#include "libft.h"

int	ft_isalnum(int c)
{
	int	alpha;
	int	num;

	alpha = ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'));
	num = (c >= '0' && c <= '9');
	return (alpha || num);
}
/*
int	main(void)
{
	char	i = 'c';
	char	j = '0';
	char	y = '\\';

	printf("%d\n", ft_isalnum(i));
	printf("%d\n", ft_isalnum(j));
	printf("%d\n", ft_isalnum(y));
}*/
