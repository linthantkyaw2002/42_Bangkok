/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkyaw <lkyaw@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/12 23:06:12 by lkyaw             #+#    #+#             */
/*   Updated: 2025/12/12 23:06:12 by lkyaw            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_BONUS_H
# define CHECKER_BONUS_H

# include "push_swap.h"
# include <limits.h>
# include <stdlib.h>
# include <unistd.h>

/* ================= PARSING ================= */

void	parse_args(int argc, char **argv, t_stack **a);
int		ps_atoi(const char *str, int *err);
int		has_duplicate(t_stack *stack, int value);
void	free_split(char **arr);

/* ================= STACK HELPERS ================= */

t_stack	*stack_new(int value);
t_stack	*stack_pop_front(t_stack **stack);
t_stack	*stack_pop_back(t_stack **stack);
void	stack_add_front(t_stack **stack, t_stack *node);
void	stack_add_back(t_stack **stack, t_stack *node);

/* ================= CHECKER OPS (SILENT) ================= */

void	sa_silent(t_stack **a);
void	sb_silent(t_stack **b);
void	ss_silent(t_stack **a, t_stack **b);

void	pa_silent(t_stack **a, t_stack **b);
void	pb_silent(t_stack **a, t_stack **b);

void	ra_silent(t_stack **a);
void	rb_silent(t_stack **b);
void	rr_silent(t_stack **a, t_stack **b);

void	rra_silent(t_stack **a);
void	rrb_silent(t_stack **b);
void	rrr_silent(t_stack **a, t_stack **b);

/* ================= CHECKER LOGIC ================= */

void	exec_op(char *line, t_stack **a, t_stack **b);
int		is_sorted(t_stack *a);

/* ================= ERROR / FREE ================= */

void	free_stack(t_stack **stack);
void	error_exit(t_stack **a, t_stack **b);

/* ================= UTILS ================= */

char	*get_next_line(int fd);
int		str_cmp(const char *s1, const char *s2);

#endif
