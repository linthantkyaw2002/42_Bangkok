/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animation_factor.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkyaw <lkyaw@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/28 03:33:04 by lkyaw             #+#    #+#             */
/*   Updated: 2026/01/28 03:33:04 by lkyaw            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

int	get_speed_factor(t_game *g)
{
	int	current_area;
	int	reference_area;

	current_area = get_map_width(g->map) * get_map_height(g->map);
	reference_area = 200;
	return (current_area / reference_area);
}
