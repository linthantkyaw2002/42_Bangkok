#include "push_swap.h"

/* rotate stack a: first element becomes last */
void	ra(t_stack **a)
{
	t_stack	*node;

	node = stack_pop_front(a);
	if (!node)
		return ;
	stack_add_back(a, node);
	write(1, "ra\n", 3);
}

/* rotate stack b: first element becomes last */
void	rb(t_stack **b)
{
	t_stack	*node;

	node = stack_pop_front(b);
	if (!node)
		return ;
	stack_add_back(b, node);
	write(1, "rb\n", 3);
}

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
