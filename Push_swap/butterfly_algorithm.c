#include "push_swap.h"

static void	handle_push_logic(t_stack **a, t_stack **b,
			int chunk, int *target, int *pushed)
{
	int	idx;

	idx = (*a)->index;
	if (idx <= *target)
	{
		pb(a, b);
		rb(b);
		(*target)++;
		(*pushed)++;
	}
	else if (idx <= *target + chunk)
	{
		pb(a, b);
		(*target)++;
		(*pushed)++;
	}
	else
		ra(a);
}

static void	push_chunks_to_b(t_stack **a, t_stack **b, int size)
{
	int	chunk;
	int	pushed;
	int	target;

	if (size <= 100)
		chunk = 15;
	else
		chunk = 30;
	pushed = 0;
	target = 0;
	while (pushed < size)
		handle_push_logic(a, b, chunk, &target, &pushed);
}

static int	get_max_pos(t_stack *b)
{
	int	max;
	int	pos;
	int	max_pos;

	if (!b)
		return (-1);
	max = b->index;
	pos = 0;
	max_pos = 0;
	while (b)
	{
		if (b->index > max)
		{
			max = b->index;
			max_pos = pos;
		}
		b = b->next;
		pos++;
	}
	return (max_pos);
}

static void	push_back_to_a(t_stack **a, t_stack **b)
{
	int	size;
	int	max_pos;

	size = stack_size(*b);
	while (*b)
	{
		max_pos = get_max_pos(*b);
		if (max_pos <= size / 2)
		{
			while (max_pos-- > 0)
				rb(b);
		}
		else
		{
			max_pos = size - max_pos;
			while (max_pos-- > 0)
				rrb(b);
		}
		pa(a, b);
		size--;
	}
}

void	butterfly(t_stack **a, t_stack **b)
{
	int	size;

	size = stack_size(*a);
	if (size <= 3)
		return ;
	push_chunks_to_b(a, b, size);
	push_back_to_a(a, b);
}
