/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkyaw <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/14 17:12:07 by lkyaw             #+#    #+#             */
/*   Updated: 2025/07/14 18:28:23 by lkyaw            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <unistd.h>

unsigned int	ft_strlcpy(char *dest, char *src, unsigned int size)
{
	unsigned int	i;

	i = 0;
	if (size > 0)
	{
		while (src[i] && i < size -1)
		{
			dest[i] = src[i];
			i++;
		}
		dest[i] = '\0';
	}
	i = 0;
	while (src[i])
		i++;
	return (i);
}
/*
int	main(void)
{
	char *src= "he\nlld";
	char dest[5];
	int i = 5;
	char j;

	j = ft_strlcpy(dest, src, i) + '0';
	write(1, dest, i -1);
	write(1, "\n", 1);
	write(1, &j, 1); 
	return (0);
}*/
