/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkyaw <lkyaw@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/07 12:15:04 by lkyaw             #+#    #+#             */
/*   Updated: 2025/09/09 19:12:10 by lkyaw            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	handle_format(char c, va_list args)
{
	if (c == '\0')
		return ;
	else if (c == 'c')
		ft_putchar(va_arg(args, int));
	else if (c == 's')
		ft_putstr(va_arg(args, char *));
	else if (c == 'p')
		ft_putptr((unsigned long)va_arg(args, void *));
	else if (c == 'd' || c == 'i')
		ft_putnbr_base(va_arg(args, int), "0123456789");
	else if (c == 'u')
		ft_putnbr_base_uint(va_arg(args, unsigned int), "0123456789");
	else if (c == 'x')
		ft_putnbr_base_uint(va_arg(args, unsigned int),
			"0123456789abcdef");
	else if (c == 'X')
		ft_putnbr_base_uint(va_arg(args, unsigned int),
			"0123456789ABCDEF");
	else if (c == '%')
		ft_putchar('%');
	else
	{
		ft_putchar('%');
		ft_putchar(c);
	}
}

int	ft_printf(const char *str, ...)
{
	va_list	args;
	int		i;

	ft_count(1);
	va_start(args, str);
	i = -1;
	while (str[++i])
	{
		if (str[i] == '%')
		{
			if (str[i + 1])
			{
				i++;
				handle_format(str[i], args);
			}
			else
				break ;
		}
		else
			ft_putchar(str[i]);
	}
	va_end(args);
	i = ft_count(0) - 1;
	return (i);
}
