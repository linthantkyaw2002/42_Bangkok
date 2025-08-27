/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkyaw <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/15 21:26:38 by lkyaw             #+#    #+#             */
/*   Updated: 2025/07/15 22:15:26 by lkyaw            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <unistd.h>

char	*ft_strcat(char *dest, char *src)
{
	int	i;
	int	n;

	i = 0;
	while (dest[i])
		i++;
	n = 0;
	while (src[n])
	{
		dest[n + i] = src[n];
		n++;
	}
	dest[n + i] = '\0';
	return (dest);
}
/*
int	main(void)
{
	char src[] = "dflkflkas";
	char dest[100] = "hello";

	write(1, ft_strcat(dest, src), 16);
}*/
