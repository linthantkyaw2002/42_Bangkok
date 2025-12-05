#include "push_swap.h"

/* Main function */
int	main(int argc, char **argv)
{
	t_stack	*a;
	t_stack	*b;

	a = NULL;
	b = NULL;
	if (argc < 2)
		return (0);
	parse_args(argc, argv, &a);
	sort(&a, &b);
	free_stack(&a);
	free_stack(&b);
	return (0);
}

