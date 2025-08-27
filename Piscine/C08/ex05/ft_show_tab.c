/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_show_tab.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkyaw <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/30 23:07:29 by lkyaw             #+#    #+#             */
/*   Updated: 2025/07/30 23:19:02 by lkyaw            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "ft_stock_str.h"

void	ft_putstr(char *str)
{
	while (*str)
		write (1, str++, 1);
}

void	ft_putnbr(int nb)
{
	char	c;

	if (nb < 0)
	{
		write (1, "-", 1);
		nb = -nb;
	}
	if (nb > 9)
		ft_putnbr (nb / 10);
	c = nb % 10 + '0';
	write (1, &c, 1);
}

void	ft_show_tab(struct s_stock_str *ptr)
{
	int	i;

	i = 0;
	while (ptr[i].str != 0)
	{
		ft_putstr (ptr[i].str);
		write(1, "\n", 1);
		ft_putnbr (ptr[i].size);
		write(1, "\n", 1);
		ft_putstr (ptr[i].copy);
		write(1, "\n", 1);
		i++;
	}
}
