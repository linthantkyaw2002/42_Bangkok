/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_ff.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkyaw <lkyaw@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/10 08:49:50 by lkyaw             #+#    #+#             */
/*   Updated: 2025/12/10 08:49:50 by lkyaw            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* Get the position of the minimum value node in stack A */
static int	get_min_pos(t_stack *a)
{
	int	min;
	int	pos;
	int	min_pos;

	if (!a)
		return (-1);
	min = a->value;
	pos = 0;
	min_pos = 0;
	while (a)
	{
		if (a->value < min)
		{
			min = a->value;
			min_pos = pos;
		}
		a = a->next;
		pos++;
	}
	return (min_pos);
}

/* Push the minimum value node from A to B */
static void	push_min_to_b(t_stack **a, t_stack **b)
{
	int	min_pos;
	int	size;

	size = stack_size(*a);
	min_pos = get_min_pos(*a);
	if (min_pos <= size / 2)
	{
		while (min_pos-- > 0)
			ra(a);
	}
	else
	{
		min_pos = size - min_pos;
		while (min_pos-- > 0)
			rra(a);
	}
	pb(a, b);
}

/* Sort stack with four elements */
void	sort_four(t_stack **a, t_stack **b)
{
	push_min_to_b(a, b);
	sort_three(a);
	pa(a, b);
}

/* Sort stack with five elements */
void	sort_five(t_stack **a, t_stack **b)
{
	push_min_to_b(a, b);
	push_min_to_b(a, b);
	sort_three(a);
	pa(a, b);
	pa(a, b);
}
