/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkyaw <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/30 15:30:53 by lkyaw             #+#    #+#             */
/*   Updated: 2025/08/30 15:31:20 by lkyaw            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <stdio.h>
#include "libft.h"

char	*ft_strdup(const char *src)
{
	int		i;
	int		j;
	char	*arr;

	i = 0;
	j = ft_strlen(src);
	arr = (char *)malloc(sizeof(char) * (j + 1));
	if (arr == NULL)
		return (NULL);
	while (src[i])
	{
		arr[i] = src[i];
		i++;
	}
	arr[i] = '\0';
	return (arr);
}
/*
int	main(void)
{
	char *str = "ggwp";
	char *copy = ft_strdup(str);
	printf("%s\n", copy);
	free(copy);
	return (0);
}*/
