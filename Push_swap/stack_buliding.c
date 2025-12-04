/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_buliding.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkyaw <lkyaw@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/03 14:47:09 by lkyaw             #+#    #+#             */
/*   Updated: 2025/12/03 22:27:49 by lkyaw            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* create new node */
t_stack	*stack_new(int value)
{
	t_stack	*node;

	node = (t_stack *)malloc(sizeof(t_stack));
	if (!node)
		return (NULL);
	node->value = value;
	node->index = -1;
	node->next = NULL;
	return (node);
}

/* add node at the end of stack a */
void	stack_add_back(t_stack **a, t_stack *new_node)
{
	t_stack	*tmp;

	if (!new_node)
		return ;
	if (!*a)
	{
		*a = new_node;
		return ;
	}
	tmp = *a;
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

/* build stack a from command line arguments */
t_stack	*build_stack(int ac, char **av)
{
	t_stack	*a;
	t_stack	*node;
	int		i;

	a = NULL;
	i = 1;
	while (i < ac)
	{
		node = stack_new(ft_atoi(av[i]));
		if (!node)
		{
			return (NULL);
		}
		stack_add_back(&a, node);
		i++;
	}
	return (a);
}

/* free the stack */
#include "push_swap.h"

void	free_stack(t_stack **stack)
{
	t_stack	*tmp;

	if (!stack)
		return ;
	while (*stack)
	{
		tmp = (*stack)->next;
		free(*stack);
		*stack = tmp;
	}
}
