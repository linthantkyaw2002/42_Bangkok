/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkyaw <lkyaw@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/03 13:50:27 by admin             #+#    #+#             */
/*   Updated: 2025/12/03 22:04:30 by lkyaw            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>

typedef struct s_stack
{
	int				value;
	int				index;
	struct s_stack	*next;
}					t_stack;

/* ft_atoi.c */
int					ft_atoi(const char *str);

/* build_stack.c */
t_stack				*stack_new(int value);
void				stack_add_back(t_stack **a, t_stack *new_node);
void				stack_add_front(t_stack **stack, t_stack *new_node);
t_stack				*build_stack(int ac, char **av);
void				free_stack(t_stack **stack);

/*stack_manipulation.c */
t_stack				*stack_pop_front(t_stack **stack);
t_stack				*stack_pop_back(t_stack **stack);
int					stack_size(t_stack *a);

/* indexing.c */
void				assign_indexes(t_stack *a);

/* pushing.c */
void				pa(t_stack **a, t_stack **b);
void				pb(t_stack **a, t_stack **b);
#endif