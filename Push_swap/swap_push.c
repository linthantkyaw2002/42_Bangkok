#include "push_swap.h"

/* Swaps the first two elements of stack a */
void	sa(t_stack **a)
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
	write(1, "sa\n", 3);
}

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
	t_stack *node;

	node = stack_pop_front(a);
	if (!node)
		return ;
	stack_add_front(b, node);
	write(1, "pb\n", 3);
}