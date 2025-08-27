/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkyaw <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/23 16:30:06 by lkyaw             #+#    #+#             */
/*   Updated: 2025/07/28 22:09:35 by lkyaw            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <stdio.h>
#include <stdlib.h>

int	base_vaild(char *base)
{
	int	i;
	int	j;

	i = 0;
	while (base[i])
	{
		if (base[i] == '+' || base[i] == '-')
			return (0);
		if ((base[i] >= '\t' && base[i] <= '\r') || base[i] == ' ')
			return (0);
		j = i + 1;
		while (base[j])
		{
			if (base[i] == base[j])
				return (0);
			j++;
		}
		i++;
	}
	if (i >= 2)
		return (i);
	return (0);
}

int	is_in_base(char c, char *base)
{
	int	i;

	i = 0;
	while (base[i])
	{
		if (c == base[i])
			return (i);
		i++;
	}
	return (-1);
}

int	basecount(char *base)
{
	int	i;

	i = 0;
	while (base[i])
		i++;
	return (i);
}

int	b_to_i(char *str, int flag, char *base)
{
	int	i;
	int	power;
	int	r;

	i = 0;
	while (str[i])
		i++;
	power = 1;
	r = 0;
	i--;
	while (i >= 0)
	{
		r += is_in_base(str[i], base) * power;
		power *= basecount(base);
		i--;
	}
	if (flag % 2 == 0)
		return (r);
	else
		return (-r);
}

int	ft_atoi_base(char *str, char *base)
{
	int		i;
	int		flag;
	char	*arr;
	int		j;

	i = 0;
	j = 0;
	flag = 0;
	arr = malloc(basecount(str) + 1);
	if (!arr || !base_vaild(base))
		return (0);
	while (((str[i] >= '\t' && str[i] <= '\r')) || str[i] == ' ')
		i++;
	while (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			flag++;
		i++;
	}
	while (is_in_base(str[i], base) >= 0)
		arr[j++] = str[i++];
	arr[j] = '\0';
	i = b_to_i(arr, flag, base);
	return (i);
}
/*
int	main(void)
{
	char str[] = "     ----+-bcd-2726";
	char base[] = "abcdefghij";
	int	i = ft_atoi_base(str, base);
	printf("string: %s\n", str);
	printf("int   : %d\n", i);
}
*/
