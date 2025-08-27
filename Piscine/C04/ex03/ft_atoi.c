/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkyaw <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/17 13:33:01 by lkyaw             #+#    #+#             */
/*   Updated: 2025/07/17 16:14:10 by lkyaw            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <stdio.h>

int	s_to_i(char *str, int flag)
{
	int	i;
	int	power;
	int	r;

	i = 0;
	while (str[i])
		i++;
	i--;
	power = 1;
	r = 0;
	while (i >= 0)
	{
		r += (str[i] - '0') * power;
		power *= 10;
		i--;
	}
	if (flag % 2 == 0)
		return (r);
	else
		return (-r);
}

int	ft_atoi(char *str)
{
	int		i;
	int		flag;
	char	arr[100];
	int		j;

	i = 0;
	j = 0;
	flag = 0;
	while (((str[i] >= '\t' && str[i] <= '\r')) || str[i] == ' ')
		i++;
	while (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			flag++;
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
	char str[] = "    ---+--adc-2726";
	int i;

	i = ft_atoi(str);
	printf("string: %s\n", str);
	printf("int : %d", i);
}*/
