/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkyaw <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/15 22:16:47 by lkyaw             #+#    #+#             */
/*   Updated: 2025/07/15 23:16:32 by lkyaw            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <unistd.h>

char	*ft_strncat(char *dest, char *src, unsigned int nb)
{
	unsigned int	i;
	unsigned int	j;

	j = 0;
	while (dest[j])
		j++;
	i = 0;
	while (i < nb)
	{
		dest[j + i] = src[i];
		if (src[i] == '\0')
			break ;
		i++;
	}
	dest[j + i] = '\0';
	return (dest);
}
/*
int	main(void)
{
	char	*src= "fadkfaf";
	char	dest[80]= "hello";

	unsigned int nb = 4;

	write(1, ft_strncat(dest, src, nb), 15);
	write(1, "\n", 1);
	write(1, ft_strncat(dest, src, nb), 15);
}*/
