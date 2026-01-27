/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkyaw <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/30 15:14:46 by lkyaw             #+#    #+#             */
/*   Updated: 2025/08/30 17:55:57 by lkyaw            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <stdio.h>
#include "libft.h"

int	s_to_i(char *arr, int flag)
{
	int	i;
	int	power;
	int	r;

	i = 0;
	while (arr[i])
		i++;
	i--;
	power = 1;
	r = 0;
	while (i >= 0)
	{
		r += (arr[i] - '0') * power;
		power *= 10;
		i--;
	}
	return (r * flag);
}

int	ft_atoi(const char *str)
{
	int		i;
	int		flag;
	char	arr[100];
	int		j;

	i = 0;
	j = 0;
	flag = 1;
	while (((str[i] >= '\t' && str[i] <= '\r')) || str[i] == ' ')
		i++;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			flag = -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		arr[j] = str[i];
		i++;
		j++;
	}
	arr [j] = '\0';
	return ((s_to_i(arr, flag)));
}
/*
int	main(void)
{
	char str[] = "    +2726adfa";
	int i;

	i = ft_atoi(str);
	printf("string: %s\n", str);
	printf("int : %d", i);
}*/
