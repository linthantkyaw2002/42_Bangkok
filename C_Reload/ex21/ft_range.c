/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkyaw <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/26 16:42:33 by lkyaw             #+#    #+#             */
/*   Updated: 2025/08/26 16:42:46 by lkyaw            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
//#include <stdio.h>

int	*ft_range(int min, int max)
{
	int	i;
	int	*arr;

	arr = (int *)malloc(sizeof(int) * ((max - min) + 1));
	if (!arr || min >= max)
		return (NULL);
	i = 0;
	while (min < max)
	{
		arr[i] = min;
		min++;
		i++;
	}
	return (arr);
}
/*
int	main(void)
{
	int *range;
	int	i = 5;
	int	j = 10;

	range = ft_range(i, j);
	for(int i = 0; i < 5; i++)
		printf("%d ", range[i]);
	free(range);
	return 0;
}*/
