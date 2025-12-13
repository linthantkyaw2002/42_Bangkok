/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkyaw <lkyaw@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/12 22:22:12 by lkyaw             #+#    #+#             */
/*   Updated: 2025/12/12 22:22:12 by lkyaw            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../checker_bonus.h"

/* reverse rotate a */
void	rra_silent(t_stack **a)
{
	t_stack	*node;

	node = stack_pop_back(a);
	if (!node)
		return ;
	stack_add_front(a, node);
}

/* reverse rotate b */
void	rrb_silent(t_stack **b)
{
	t_stack	*node;

	node = stack_pop_back(b);
	if (!node)
		return ;
	stack_add_front(b, node);
}

/* reverse rotate both a and b */
void	rrr_silent(t_stack **a, t_stack **b)
{
	rra_silent(a);
	rrb_silent(b);
}
