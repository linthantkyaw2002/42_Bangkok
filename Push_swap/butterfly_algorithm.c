/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   butterfly_algorithm.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkyaw <lkyaw@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/10 14:37:50 by lkyaw             #+#    #+#             */
/*   Updated: 2025/12/10 14:37:50 by lkyaw            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
** vars[0] = target
** vars[1] = pushed
*/

/* Handle the logic for pushing elements from A to B based on index */
static void	handle_push_logic(t_stack **a, t_stack **b, int chunk, int *vars)
{
	int	idx;

	idx = (*a)->index;
	if (idx <= vars[0])
	{
		pb(a, b);
		rb(b);
		vars[0]++;
		vars[1]++;
	}
	else if (idx <= vars[0] + chunk)
	{
		pb(a, b);
		vars[0]++;
		vars[1]++;
	}
	else
		ra(a);
}

/* Push elements from stack A to B in chunks */
static void	push_chunks_to_b(t_stack **a, t_stack **b, int size)
{
	int	chunk;
	int	vars[2];

	if (size <= 100)
		chunk = 15;
	else
		chunk = 30;
	vars[0] = 0;
	vars[1] = 0;
	while (vars[1] < size)
		handle_push_logic(a, b, chunk, vars);
}

/* Get the position of the maximum indexed node in stack B */
static int	get_max_pos(t_stack *b)
{
	int	max;
	int	pos;
	int	max_pos;

	if (!b)
		return (-1);
	max = b->index;
	pos = 0;
	max_pos = 0;
	while (b)
	{
		if (b->index > max)
		{
			max = b->index;
			max_pos = pos;
		}
		b = b->next;
		pos++;
	}
	return (max_pos);
}

/* Push all elements back from B to A in sorted order */
static void	push_back_to_a(t_stack **a, t_stack **b)
{
	int	size;
	int	max_pos;

	size = stack_size(*b);
	while (*b)
	{
		max_pos = get_max_pos(*b);
		if (max_pos <= size / 2)
		{
			while (max_pos-- > 0)
				rb(b);
		}
		else
		{
			max_pos = size - max_pos;
			while (max_pos-- > 0)
				rrb(b);
		}
		pa(a, b);
		size--;
	}
}

/* Main butterfly algorithm function */
void	butterfly(t_stack **a, t_stack **b)
{
	int	size;

	size = stack_size(*a);
	push_chunks_to_b(a, b, size);
	push_back_to_a(a, b);
}
