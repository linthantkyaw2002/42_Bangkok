/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkyaw <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/30 16:34:59 by lkyaw             #+#    #+#             */
/*   Updated: 2025/08/30 16:35:25 by lkyaw            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <stdio.h>
#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, unsigned long len)
{
	unsigned long	i;
	unsigned long	j;

	i = 0;
	j = 0;
	if (little[0] == '\0')
		return ((char *)(big));
	while (big[i] && i < len)
	{
		if (big[i] == little[j])
		{
			j++;
			if (little[j] == '\0')
				return ((char *)(&big[i - j + 1]));
		}
		else
		{
			i = i - j;
			j = 0;
		}
		i++;
	}
	return (NULL);
}
/*
int	main(void)
{
	char	str[] = "hllelloword";
	char	find[] = "";
	
	printf("%s\n", ft_strnstr(str, find, 3)); 
}*/
