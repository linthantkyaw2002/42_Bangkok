/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_manipulation.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkyaw <lkyaw@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/03 14:47:14 by lkyaw             #+#    #+#             */
/*   Updated: 2025/12/03 15:08:12 by lkyaw            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* remove and return the top node */
t_stack	*stack_pop_front(t_stack **stack)
{
	t_stack	*top;

	if (!stack || !*stack)
		return (NULL);
	top = *stack;
	*stack = (*stack)->next;
	top->next = NULL;
	return (top);
}

/* remove and return the last node */
t_stack	*stack_pop_back(t_stack **stack)
{
	t_stack	*prev;
	t_stack	*last;

	if (!stack || !*stack)
		return (NULL);
	if ((*stack)->next == NULL)
	{
		last = *stack;
		*stack = NULL;
		return (last);
	}
	prev = *stack;
	while (prev->next->next != NULL)
		prev = prev->next;
	last = prev->next;
	prev->next = NULL;
	return (last);
}

/* count how many nodes in stack a */
int	stack_size(t_stack *a)
{
	int	len;

	len = 0;
	while (a)
	{
		len++;
		a = a->next;
	}
	return (len);
}
