/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkyaw <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/31 10:58:13 by lkyaw             #+#    #+#             */
/*   Updated: 2025/08/31 14:05:21 by lkyaw            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <stdio.h>
#include "libft.h"

int	ft_chrinstr(char const *str, int c)
{
	char	j;
	int		i;

	j = c;
	i = 0;
	while (str[i])
	{
		if (str[i] == j)
			return (c);
		i++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	int		start;
	int		end;
	int		len;
	char	*str;

	start = 0;
	while (ft_chrinstr(set, s1[start]))
		start++;
	end = ft_strlen(s1) - 1;
	while (ft_chrinstr(set, s1[end]))
		end--;
	len = (end - start) + 1;
	str = ft_substr(s1, start, len);
	return (str);
}
/*
int	main(void)
{
	char	*str= "   #$@@  @#$   ";
	char	*set= " $#@";

	printf("%s\n", ft_strtrim(str, set));
}*/
