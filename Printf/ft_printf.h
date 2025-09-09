/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkyaw <lkyaw@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/09 16:27:16 by lkyaw             #+#    #+#             */
/*   Updated: 2025/09/09 17:43:09 by lkyaw            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>

int		ft_printf(const char *str, ...);
int		base_valid(char *base);
void	ft_putchar(int i);
void	ft_putstr(char *str);
int		ft_count(void);
void	ft_putnbr_base_uint(unsigned int n, char *base);
void	ft_putnbr_base(int nbr, char *base);
void	ft_putptr(unsigned long l);

#endif