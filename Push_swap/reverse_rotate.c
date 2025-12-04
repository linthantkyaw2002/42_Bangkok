#include "push_swap.h"

/* rra: last element of a becomes first */
void	rra(t_stack **a)
{
	t_stack	*node;

	node = stack_pop_back(a);
	if (!node)
		return ;
	stack_add_front(a, node);
	write(1, "rra\n", 4);
}

/* rrb: last element of b becomes first */
void	rrb(t_stack **b)
{
	t_stack	*node;

	node = stack_pop_back(b);
	if (!node)
		return ;
	stack_add_front(b, node);
	write(1, "rrb\n", 4);
}

/* rrr: reverse rotate both a and b */
void	rrr(t_stack **a, t_stack **b)
{
	t_stack	*node_a;
	t_stack	*node_b;

	node_a = stack_pop_back(a);
	node_b = stack_pop_back(b);
	if (node_a)
		stack_add_front(a, node_a);
	if (node_b)
		stack_add_front(b, node_b);
	write(1, "rrr\n", 4);
}
