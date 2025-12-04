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

/* rotate both stacks a and b at the same time */
void	rr(t_stack **a, t_stack **b)
{
	t_stack	*node_a;
	t_stack	*node_b;

	node_a = stack_pop_front(a);
	node_b = stack_pop_front(b);
	if (node_a)
		stack_add_back(a, node_a);
	if (node_b)
		stack_add_back(b, node_b);
	write(1, "rr\n", 3);
}
