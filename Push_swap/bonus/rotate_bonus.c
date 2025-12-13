/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkyaw <lkyaw@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/12 22:22:18 by lkyaw             #+#    #+#             */
/*   Updated: 2025/12/12 22:22:18 by lkyaw            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../checker_bonus.h"

/* rotate a */
void	ra_silent(t_stack **a)
{
	t_stack	*node;

	node = stack_pop_front(a);
	if (!node)
		return ;
	stack_add_back(a, node);
}

/* rotate b */
void	rb_silent(t_stack **b)
{
	t_stack	*node;

	node = stack_pop_front(b);
	if (!node)
		return ;
	stack_add_back(b, node);
}

/* rotate both a and b */
void	rr_silent(t_stack **a, t_stack **b)
{
	ra_silent(a);
	rb_silent(b);
}
