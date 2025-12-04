/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   indexing.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkyaw <lkyaw@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/03 15:10:00 by lkyaw             #+#    #+#             */
/*   Updated: 2025/12/03 15:10:00 by lkyaw            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* copy stack values into array */
static int	*copy_values(t_stack *a, int size)
{
	int	*arr;
	int	i;

	arr = malloc(sizeof(int) * size);
	if (!arr)
		return (NULL);
	i = 0;
	while (a)
	{
		arr[i++] = a->value;
		a = a->next;
	}
	return (arr);
}

/* bubble sort: small size, OK for push_swap */
static void	sort_array(int *arr, int size)
{
	int	i;
	int	tmp;
	int	swapped;

	swapped = 1;
	while (swapped)
	{
		swapped = 0;
		i = 0;
		while (i + 1 < size)
		{
			if (arr[i] > arr[i + 1])
			{
				tmp = arr[i];
				arr[i] = arr[i + 1];
				arr[i + 1] = tmp;
				swapped = 1;
			}
			i++;
		}
	}
}

/* assign index to each node based on sorted array */
static void	set_indexes(t_stack *a, int *arr, int size)
{
	int	i;

	while (a)
	{
		i = 0;
		while (i < size)
		{
			if (a->value == arr[i])
			{
				a->index = i;
				break ;
			}
			i++;
		}
		a = a->next;
	}
}

/* main public function */
void	assign_indexes(t_stack *a)
{
	int	size;
	int	*arr;

	size = stack_size(a);
	arr = copy_values(a, size);
	if (!arr)
		return ;
	sort_array(arr, size);
	set_indexes(a, arr, size);
	free(arr);
}
