/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkyaw <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/16 00:02:40 by lkyaw             #+#    #+#             */
/*   Updated: 2025/07/16 02:55:32 by lkyaw            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <stdio.h>

unsigned int	ft_strlcat(char *dest, char *src, unsigned int size)
{
	unsigned int	d_i;
	unsigned int	s_i;
	unsigned int	i;

	i = 0;
	d_i = 0;
	s_i = 0;
	while (d_i < size && dest[d_i])
		d_i++;
	while (src[s_i])
		s_i++;
	if (size <= d_i)
		return (size + s_i);
	while (src[i] && (d_i + i < size - 1))
	{
		dest[d_i + i] = src[i];
		i++;
	}
	dest[d_i + i] = '\0';
	return (d_i + s_i);
}
/*
int	main(void)
{
	unsigned int size = 15;
	char str[]= "world";
	char dest[10]= "heel";

	printf("%d\n", ft_strlcat(str, dest, size));
}*/
