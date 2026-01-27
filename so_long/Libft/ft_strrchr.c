/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkyaw <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/30 13:22:26 by lkyaw             #+#    #+#             */
/*   Updated: 2025/08/30 13:45:55 by lkyaw            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <stdio.h>
#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int		i;
	char	*p;
	int		found;
	char	j;

	j = c;
	i = 0;
	found = 0;
	while (s[i])
	{
		if (s[i] == j)
		{
			p = (char *)(s + i);
			found++;
		}
		i++;
	}
	if (c == '\0')
		return ((char *)(s + i));
	if (j != '\0' && found > 0)
		return (p);
	else
		return (NULL);
}
/*
int	main(void)
{
	char	str[] = "hell\0oworld";
	char	*i;

	i = ft_strrchr(str, '\0');
	printf("%s\n", i+1);
}*/
