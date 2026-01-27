/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkyaw <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/30 12:59:18 by lkyaw             #+#    #+#             */
/*   Updated: 2025/08/30 19:04:35 by lkyaw            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <stdio.h>
#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	int		i;
	char	j;

	j = c;
	i = 0;
	while (s[i])
	{
		if (s[i] == j)
			return ((char *)(s + i));
		i++;
	}
	if (j == '\0')
		return ((char *)(s + i));
	return (NULL);
}
/*
int	main(void)
{
	char	str[]= "hellsloworld";
	char	*i;

	i = ft_strchr(str, '0' + 256);
	printf("%s\n", i);
}*/
