/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_exec_b.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkyaw <lkyaw@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/12 22:22:06 by lkyaw             #+#    #+#             */
/*   Updated: 2025/12/12 22:22:06 by lkyaw            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../checker_bonus.h"

/* strcmp function to compare two strings */
static int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s1[i] && s2[i])
	{
		if (s1[i] != s2[i])
			return ((unsigned char)s1[i] - (unsigned char)s2[i]);
		i++;
	}
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}

/* Check if the operation is valid */
static int	is_valid_op(char *line)
{
	return (!ft_strcmp(line, "sa\n") || !ft_strcmp(line, "sb\n")
		|| !ft_strcmp(line, "ss\n") || !ft_strcmp(line, "pa\n")
		|| !ft_strcmp(line, "pb\n") || !ft_strcmp(line, "ra\n")
		|| !ft_strcmp(line, "rb\n") || !ft_strcmp(line, "rr\n")
		|| !ft_strcmp(line, "rra\n") || !ft_strcmp(line, "rrb\n")
		|| !ft_strcmp(line, "rrr\n"));
}

/* Execute the operation on stacks a and b */
static void	exec_op2(char *line, t_stack **a, t_stack **b)
{
	if (!ft_strcmp(line, "rra\n"))
		rra_silent(a);
	else if (!ft_strcmp(line, "rrb\n"))
		rrb_silent(b);
	else if (!ft_strcmp(line, "rrr\n"))
		rrr_silent(a, b);
	else
		error_exit(a, b);
}

/* Main function to execute the operation */
void	exec_op(char *line, t_stack **a, t_stack **b)
{
	if (!is_valid_op(line))
		error_exit(a, b);
	if (!ft_strcmp(line, "sa\n"))
		sa_silent(a);
	else if (!ft_strcmp(line, "sb\n"))
		sb_silent(b);
	else if (!ft_strcmp(line, "ss\n"))
		ss_silent(a, b);
	else if (!ft_strcmp(line, "pa\n"))
		pa_silent(a, b);
	else if (!ft_strcmp(line, "pb\n"))
		pb_silent(a, b);
	else if (!ft_strcmp(line, "ra\n"))
		ra_silent(a);
	else if (!ft_strcmp(line, "rb\n"))
		rb_silent(b);
	else if (!ft_strcmp(line, "rr\n"))
		rr_silent(a, b);
	else
		exec_op2(line, a, b);
}
