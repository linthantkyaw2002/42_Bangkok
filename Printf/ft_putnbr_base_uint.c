/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base_uint.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkyaw <lkyaw@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/09 15:43:27 by lkyaw             #+#    #+#             */
/*   Updated: 2025/09/09 17:34:30 by lkyaw            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putnbr_base_uint_print(unsigned int n, char *base, int basecount)
{
	if (n >= (unsigned int)basecount)
		ft_putnbr_base_uint_print(n / basecount, base, basecount);
	ft_putchar(base[n % basecount]);
}

void	ft_putnbr_base_uint(unsigned int n, char *base)
{
	int	basecount;

	basecount = base_valid(base);
	if (basecount == 0)
		return ;
	ft_putnbr_base_uint_print(n, base, basecount);
}
