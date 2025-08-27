/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strs_to_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkyaw <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/30 23:07:00 by lkyaw             #+#    #+#             */
/*   Updated: 2025/07/30 23:07:04 by lkyaw            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_stock_str.h"

unsigned int	ft_strlen(char *str)
{
	unsigned int	index;

	index = 0;
	while (str[index] != '\0')
	{
		index++;
	}
	return (index);
}

char	*ft_strdup(char *src)
{
	char	*dest;
	int		idx;

	idx = 0;
	dest = (char *)malloc((sizeof(char) * ft_strlen(src)) + 1);
	if (!dest)
		return (0);
	while (src[idx])
	{
		dest[idx] = src[idx];
		idx++;
	}
	dest[idx] = '\0';
	return (dest);
}

struct s_stock_str	*ft_strs_to_tab(int ac, char **av)
{
	struct s_stock_str	*temp;
	int					idx;

	temp = malloc(sizeof(struct s_stock_str) * (ac + 1));
	if (!temp)
		return (NULL);
	idx = 0;
	while (idx < ac)
	{
		temp[idx].size = ft_strlen(av[idx]);
		temp[idx].str = av[idx];
		temp[idx].copy = ft_strdup(av[idx]);
		idx++;
	}
	temp[idx].str = 0;
	temp[idx].copy = 0;
	return (temp);
}
