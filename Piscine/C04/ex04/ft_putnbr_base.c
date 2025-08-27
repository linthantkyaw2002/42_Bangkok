/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkyaw <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/23 17:56:29 by lkyaw             #+#    #+#             */
/*   Updated: 2025/07/23 20:05:02 by lkyaw            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	print_base(long n, char *base, int basecount)
{
	char	arr[34];
	int		i;

	i = 0;
	if (basecount <= 0)
		return ;
	if (n == 0)
	{
		write(1, &base[0], 1);
		return ;
	}
	while (n > 0)
	{
		arr[i++] = base[n % basecount];
		n = n / basecount;
	}
	while (--i >= 0)
		write(1, &arr[i], 1);
}

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
	else
		return (0);
}

void	ft_putnbr_base(int nbr, char *base)
{
	long	n;
	int		basecount;

	basecount = base_vaild(base);
	if (basecount == 0)
		return ;
	n = nbr;
	if (n < 0)
	{
		write(1, "-", 1);
		n = -n;
	}
	print_base(n, base, basecount);
}
/*
int	main(void)
{
	int  i = 123;
	char 	*d = "abcdef";
	char	*b = "0123456789";
	char	*h = "0123456789ABCDEF";
	char	*o = "01234567";
	ft_putnbr_base(i, d);
	write(1, "\n", 1);
	ft_putnbr_base(i, b);
	write(1, "\n", 1);
	ft_putnbr_base(i, h);
	write(1, "\n", 1);
	ft_putnbr_base(i, o); 

}*/
