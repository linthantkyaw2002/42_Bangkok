/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkyaw <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/23 17:56:29 by lkyaw             #+#    #+#             */
/*   Updated: 2025/07/28 22:13:52 by lkyaw            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
//#include <stdio.h>

int	ft_atoi_base(char *str, char *base);
int	base_vaild(char *base);
int	basecount(char *base);

char	*ft_rev_char_tab(char *arr)
{
	int		i;
	char	temp;
	int		size;

	size = 0;
	while (arr[size])
		size++;
	size--;
	i = 0;
	while (i < size)
	{
		temp = arr[i];
		arr[i] = arr[size];
		arr[size] = temp;
		i++;
		size--;
	}
	return (arr);
}

char	*print_base(long n, char *base, int basecount)
{
	char	*arr;
	int		i;

	arr = malloc(35);
	if (!arr)
		return (0);
	i = 0;
	if (basecount <= 0)
		return (0);
	if (n == 0)
	{
		arr[0] = base[0];
		arr[1] = '\0';
		return (arr);
	}
	while (n > 0)
	{
		arr[i++] = base[n % basecount];
		n = n / basecount;
	}
	arr[i] = '\0';
	return (ft_rev_char_tab(arr));
}

char	*ft_putnbr_base(int nbr, char *base)
{
	long	n;
	int		basecount;

	basecount = base_vaild(base);
	if (basecount == 0)
		return (0);
	n = nbr;
	return (print_base(n, base, basecount));
}

char	*ft_strcat(char *src)
{
	int		i;
	int		n;
	char	*arr;

	n = 0;
	i = basecount(src);
	arr = (char *)malloc(i + 2);
	arr[0] = '-';
	while (src[n])
	{
		arr[1 + n] = src[n];
		n++;
	}
	arr[n + 1] = '\0';
	return (arr);
}

char	*ft_convert_base(char *nbr, char *base_form, char *base_to)
{
	int	i;

	if (base_vaild(base_form) && base_vaild(base_to))
	{
		i = ft_atoi_base(nbr, base_form);
		if (i > 0)
			return (ft_putnbr_base(i, base_to));
		if (i < 0)
		{
			i = -i;
			return (ft_strcat(ft_putnbr_base(i, base_to)));
		}
	}
	return (0);
}
/*
int	main(void)
{
	char    *i = "-----+-123abcd";
	char 	*d = "abcdef";
	char	*b = "0123456789";

	printf("%s\n",ft_convert_base(i, b, d));
	return (0);
}*/
