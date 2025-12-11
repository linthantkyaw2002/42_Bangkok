/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkyaw <lkyaw@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/05 12:31:11 by lkyaw             #+#    #+#             */
/*   Updated: 2025/12/11 12:12:28 by lkyaw            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <limits.h>
# include <stdlib.h>
# include <unistd.h>
# define TARGET 0
# define PUSHED 1

typedef struct s_stack
{
	int				value;
	int				index;
	struct s_stack	*next;
}					t_stack;

/* butterfly.c */
void				butterfly(t_stack **a, t_stack **b);

/* error_handling.c */
void				error_exit(t_stack **a, t_stack **b);
int					has_duplicate(t_stack *a, int value);
void				free_split(char **arr);

/* ft_split.c */
char				**ft_split(char const *s, char c);

/* indexing.c */
void				assign_indexes(t_stack *stack);

/* ps_atoi.c */
int					ps_atoi(const char *str, int *err);

/* rotate_reverse.c */
void				ra(t_stack **a);
void				rb(t_stack **b);
void				rra(t_stack **a);
void				rrb(t_stack **b);

/*sort_ff.c*/
void				sort_four(t_stack **a, t_stack **b);
void				sort_five(t_stack **a, t_stack **b);
/* sort.c */
int					is_sorted(t_stack *a);
void				sort_two(t_stack **a);
void				sort_three(t_stack **a);
void				sort(t_stack **a, t_stack **b);

/* stack_building.c */
t_stack				*stack_new(int value);
void				parse_args(int argc, char **argv, t_stack **a);
void				free_stack(t_stack **stack);

/* stack_manipulation.c */
void				stack_add_back(t_stack **stack, t_stack *new_node);
void				stack_add_front(t_stack **stack, t_stack *new_node);
t_stack				*stack_pop_front(t_stack **stack);
t_stack				*stack_pop_back(t_stack **stack);
int					stack_size(t_stack *a);

/* swap_push.c */
void				sa(t_stack **a);
void				pa(t_stack **a, t_stack **b);
void				pb(t_stack **a, t_stack **b);

#endif
