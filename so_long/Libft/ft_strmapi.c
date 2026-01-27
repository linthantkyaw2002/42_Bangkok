/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkyaw <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/01 12:38:02 by lkyaw             #+#    #+#             */
/*   Updated: 2025/09/01 12:47:35 by lkyaw            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <stdio.h>
#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	unsigned int	i;
	unsigned int	len;
	char			*arr;

	i = 0;
	len = (unsigned int)(ft_strlen(s));
	arr = malloc(len + 1);
	if (!arr)
		return (NULL);
	while (i < len)
	{
		arr[i] = f(i, s[i]);
		i++;
	}
	arr[i] = '\0';
	return (arr);
}

char	example(unsigned int i, char c)
{
	return (c + i);
}
/*
int	main(void)
{
	char	*str = "helloworld";

	printf("%s\n", ft_strmapi(str, example));
}*/
