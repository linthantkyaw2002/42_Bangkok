/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkyaw <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/10 17:34:00 by lkyaw             #+#    #+#             */
/*   Updated: 2025/07/10 18:09:12 by lkyaw            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putstr(char *str)
{
	int		array_size;
	char	*string;

	string = str;
	array_size = 0;
	while (*str++)
	{
		array_size++;
	}
	write(1, string, array_size);
}
