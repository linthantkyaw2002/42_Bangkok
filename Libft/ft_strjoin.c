/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkyaw <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/31 10:40:01 by lkyaw             #+#    #+#             */
/*   Updated: 2025/08/31 10:56:40 by lkyaw            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <stdio.h>
#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*str;
	int		i;

	i = ft_strlen(s1) + ft_strlen(s2) + 1;
	str = (char *)malloc(i);
	if (!s1 || !s2 || !str)
		return (NULL);
	i = 0;
	while (s1[i])
	{
		str[i] = s1[i];
		i++;
	}
	i = 0;
	while (s2[i])
	{
		str[ft_strlen(s1) + i] = s2[i];
		i++;
	}
	str[ft_strlen(s1)+i] = '\0';
	return (str);
}
/*
int	main(void)
{
	char	*s1= "hello\n";
	char	*s2= "world";

	printf("%s\n", ft_strjoin(s1, s2));
}*/
