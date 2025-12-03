/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: admin <admin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/03 13:50:27 by admin             #+#    #+#             */
/*   Updated: 2025/12/03 14:39:53 by admin            ###   ########.fr       */
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
int					stack_size(t_stack *a);
t_stack				*build_stack(int ac, char **av);

#endif