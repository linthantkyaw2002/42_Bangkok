/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putptr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkyaw <lkyaw@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/09 17:42:00 by lkyaw             #+#    #+#             */
/*   Updated: 2025/09/09 19:12:21 by lkyaw            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putnbr_base_ulong_print(unsigned long n, char *base, int basecount)
{
	if (n >= (unsigned long)basecount)
		ft_putnbr_base_ulong_print(n / basecount, base, basecount);
	ft_putchar(base[n % basecount]);
}

void	ft_putnbr_base_ulong(unsigned long n, char *base)
{
	int	basecount;

	basecount = base_valid(base);
	if (basecount == 0)
		return ;
	ft_putnbr_base_ulong_print(n, base, basecount);
}

void	ft_putptr(unsigned long l)
{
	if (l == 0)
	{
		ft_putstr("(nil)");
		return ;
	}
	ft_putstr("0x");
	ft_putnbr_base_ulong(l, "0123456789abcdef");
}
