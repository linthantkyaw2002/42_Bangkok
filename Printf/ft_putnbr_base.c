/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkyaw <lkyaw@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/09 14:55:29 by lkyaw             #+#    #+#             */
/*   Updated: 2025/09/09 17:21:58 by lkyaw            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	base_valid(char *base)
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

void	ft_putnbr_base_recursive(long n, char *base, int basecount)
{
	if (n >= basecount)
		ft_putnbr_base_recursive(n / basecount, base, basecount);
	ft_putchar(base[n % basecount]);
}

void	ft_putnbr_base(int nbr, char *base)
{
	long	n;
	int		basecount;

	basecount = base_valid(base);
	if (basecount == 0)
		return ;
	n = nbr;
	if (n < 0)
	{
		ft_putchar('-');
		n = -n;
	}
	ft_putnbr_base_recursive(n, base, basecount);
}
