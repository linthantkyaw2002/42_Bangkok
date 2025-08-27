/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_non_printable.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkyaw <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/14 18:18:36 by lkyaw             #+#    #+#             */
/*   Updated: 2025/07/15 15:15:42 by lkyaw            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	print_hex(unsigned char c)
{
	char	*hex;

	hex = "0123456789abcdef";
	write(1, "\\", 1);
	write(1, &hex[c / 16], 1);
	write(1, &hex[c % 16], 1);
}

void	ft_putstr_non_printable(char *str)
{
	int				i;
	unsigned char	c;

	i = 0;
	while (str[i])
	{
		c = (unsigned char)str[i];
		if (str[i] >= 32 && str[i] <= 126)
			write(1, &str[i], 1);
		else
			print_hex(c);
		i++;
	}
}
/*
int	main(void)
{
	char *c;

	c = "g\tgg\ndfs22\\";
	ft_putstr_non_printable(c);
}*/
