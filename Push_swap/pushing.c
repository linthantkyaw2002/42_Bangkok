#include "push_swap.h"

/* push the top node from stack b to stack a */
void	pa(t_stack **a, t_stack **b)
{
	t_stack	*node;

	node = stack_pop_front(b);
	if (!node)
		return ;
	stack_add_front(a, node);
	write(1, "pa\n", 3);
}

/* push the top node from stack a to stack b */
void	pb(t_stack **a, t_stack **b)
{
	t_stack	*node;

	node = stack_pop_front(a);
	if (!node)
		return ;
	stack_add_front(b, node);
	write(1, "pb\n", 3);
}