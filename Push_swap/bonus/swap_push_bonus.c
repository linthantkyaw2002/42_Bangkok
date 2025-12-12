/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_push_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkyaw <lkyaw@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/12 22:22:24 by lkyaw             #+#    #+#             */
/*   Updated: 2025/12/12 22:22:24 by lkyaw            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../checker_bonus.h"

/* swap top 2 of a */
void	sa_silent(t_stack **a)
{
	t_stack	*first;
	t_stack	*second;

	if (!a || !*a || !(*a)->next)
		return ;
	first = *a;
	second = first->next;
	first->next = second->next;
	second->next = first;
	*a = second;
}

/* swap top 2 of b */
void	sb_silent(t_stack **b)
{
	t_stack	*first;
	t_stack	*second;

	if (!b || !*b || !(*b)->next)
		return ;
	first = *b;
	second = first->next;
	first->next = second->next;
	second->next = first;
	*b = second;
}

void	ss_silent(t_stack **a, t_stack **b)
{
	sa_silent(a);
	sb_silent(b);
}

/* push top of b to a */
void	pa_silent(t_stack **a, t_stack **b)
{
	t_stack	*node;

	node = stack_pop_front(b);
	if (!node)
		return ;
	stack_add_front(a, node);
}

/* push top of a to b */
void	pb_silent(t_stack **a, t_stack **b)
{
	t_stack	*node;

	node = stack_pop_front(a);
	if (!node)
		return ;
	stack_add_front(b, node);
}
