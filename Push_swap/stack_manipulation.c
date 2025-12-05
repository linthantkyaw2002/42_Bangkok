/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_manipulation.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkyaw <lkyaw@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/03 14:47:14 by lkyaw             #+#    #+#             */
/*   Updated: 2025/12/05 10:55:11 by lkyaw            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* add node at the end of stack a */
void	stack_add_back(t_stack **stack, t_stack *new_node)
{
	t_stack	*tmp;

	if (!new_node)
		return ;
	if (!*stack)
	{
		*stack = new_node;
		return ;
	}
	tmp = *stack;
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = new_node;
}

/* add a node onto the top */
void	stack_add_front(t_stack **stack, t_stack *new_node)
{
	if (!new_node)
		return ;
	new_node->next = *stack;
	*stack = new_node;
}
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
