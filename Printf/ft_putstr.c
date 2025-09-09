/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkyaw <lkyaw@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/09 15:02:23 by lkyaw             #+#    #+#             */
/*   Updated: 2025/09/09 17:59:00 by lkyaw            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_count(void)
{
	static int	count = 0;

	count++;
	return (count);
}

void	ft_putchar(int i)
{
	char		c;

	c = i;
	write(1, &c, 1);
	ft_count();
}

void	ft_putstr(char *str)
{
	int	i;

	i = 0;
	if (!str)
	{
		ft_putstr("(null)");
		return ;
	}
	while (str[i])
	{
		ft_putchar(str[i]);
		i++;
	}
}
