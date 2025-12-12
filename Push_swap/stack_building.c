/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_building.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkyaw <lkyaw@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/10 08:50:34 by lkyaw             #+#    #+#             */
/*   Updated: 2025/12/12 23:10:26 by lkyaw            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "./checker_bonus.h"

/* Create a new stack node */
t_stack	*stack_new(int value)
{
	t_stack	*node;

	node = malloc(sizeof(t_stack));
	if (!node)
		return (NULL);
	node->value = value;
	node->index = -1;
	node->next = NULL;
	return (node);
}

/* Process a single token into the stack */
static void	process_token(const char *s, t_stack **a)
{
	int		err;
	int		value;
	t_stack	*node;

	value = ps_atoi(s, &err);
	if (err || has_duplicate(*a, value))
		error_exit(a, NULL);
	node = stack_new(value);
	if (!node)
		error_exit(a, NULL);
	stack_add_back(a, node);
}

/* Process each argument which may contain multiple numbers */
static void	process_arg(char *arg, t_stack **a)
{
	char	**tokens;
	int		i;

	tokens = ft_split(arg, ' ');
	if (!tokens)
		error_exit(a, NULL);
	if (!tokens[0])
	{
		free_split(tokens);
		error_exit(a, NULL);
	}
	i = 0;
	while (tokens[i])
	{
		process_token(tokens[i], a);
		i++;
	}
	free_split(tokens);
}

/* Parse all command-line arguments into the stack */
void	parse_args(int argc, char **argv, t_stack **a)
{
	int	i;

	i = 1;
	while (i < argc)
	{
		if (argv[i][0] == '\0')
			error_exit(a, NULL);
		process_arg(argv[i], a);
		i++;
	}
}
