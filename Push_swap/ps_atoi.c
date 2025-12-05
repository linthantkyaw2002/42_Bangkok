/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkyaw <lkyaw@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/03 14:47:01 by lkyaw             #+#    #+#             */
/*   Updated: 2025/12/05 11:20:08 by lkyaw            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* check for whitespace characters */
static int	is_space(char c)
{
	return ((c >= '\t' && c <= '\r') || c == ' ');
}

/* check for digit characters */
static int	is_digit(char c)
{
	return (c >= '0' && c <= '9');
}

/* parse digits and handle overflow */
static long	parse_digits(const char *str, int *i, int sign, int *err)
{
	long	result;

	result = 0;
	while (is_digit(str[*i]))
	{
		result = result * 10 + (str[*i] - '0');
		if ((sign == 1 && result > INT_MAX)
			|| (sign == -1 && (-result) < INT_MIN))
		{
			*err = 1;
			return (0);
		}
		(*i)++;
	}
	return (result * sign);
}

/* convert string to integer with error checking */
int	ps_atoi(const char *str, int *err)
{
	int		i;
	int		sign;
	long	result;

	*err = 0;
	i = 0;
	sign = 1;
	while (is_space(str[i]))
		i++;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	if (!is_digit(str[i]))
	{
		*err = 1;
		return (0);
	}
	result = parse_digits(str, &i, sign, err);
	if (str[i] != '\0')
		*err = 1;
	return ((int)result);
}
