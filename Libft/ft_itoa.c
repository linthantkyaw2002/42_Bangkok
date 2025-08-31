/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkyaw <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/27 15:52:37 by lkyaw             #+#    #+#             */
/*   Updated: 2025/08/27 16:25:53 by lkyaw            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
//#include <stdio.h>

int	ft_intcount(int n)
{
	int		i;
	long	num;

	i = 0;
	num = n;
	if (num <= 0)
		num = -num;
	if (n == 0)
		return (1);
	while (num > 0)
	{
		num /= 10;
		i++;
	}
	return (i);
}

char	*ft_itos_pos(int n)
{
	int		len;
	long	num;
	char	*arr;

	len = ft_intcount(n);
	arr = malloc(len + 1);
	if (!arr)
		return (NULL);
	num = n;
	arr[len] = '\0';
	while (len > 0)
	{
		arr[--len] = (num % 10) + '0';
		num /= 10;
	}
	return (arr);
}

char	*ft_itos_neg(int n)
{
	int		len;
	long	num;
	char	*arr;

	len = ft_intcount(n);
	arr = malloc(len + 2);
	if (!arr)
		return (NULL);
	num = -((long)n);
	arr[0] = '-';
	arr[len + 1] = '\0';
	while (len > 0)
	{
		arr[len--] = (num % 10) + '0';
		num /= 10;
	}
	return (arr);
}

char	*ft_itoa(int n)
{
	char	*arr;

	if (n == 0)
	{
		arr = malloc(2);
		if (!arr)
			return (NULL);
		arr[0] = '0';
		arr[1] = '\0';
		return (arr);
	}
	if (n < 0)
		return (ft_itos_neg(n));
	return (ft_itos_pos(n));
}
/*
int	main(void)
{
	char *arr;

	arr = ft_itoa(-312323312);
	printf("%s\n", arr);
	free(arr);
	arr = ft_itoa(0);
	printf("%s\n", arr);
	free(arr);
	arr = ft_itoa(2312332);
	printf("%s\n", arr);
	free(arr);
}*/