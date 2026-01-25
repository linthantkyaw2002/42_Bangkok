/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animation_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkyaw <lkyaw@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/25 15:34:20 by lkyaw             #+#    #+#             */
/*   Updated: 2026/01/25 15:34:20 by lkyaw            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

/*check exit should be opened or not*/
static void	check_exit_proximity(t_game *g)
{
	int	x;
	int	y;

	if (g->collect_count != 0)
	{
		g->exit_open = 0;
		return ;
	}
	y = -1;
	while (g->map[++y])
	{
		x = -1;
		while (g->map[y][++x])
		{
			if (g->map[y][x] == 'E')
			{
				if (ft_abs(g->player_x - x) <= 1 && ft_abs(g->player_y
						- y) <= 1)
					g->exit_open = 1;
				else
					g->exit_open = 0;
				return ;
			}
		}
	}
}

/*nx = (x + 1) || (x - 1), e_char = X || H
two map top map (frontend), bottom title_map (P and X not included)
swaping elenmts between them create the effect*/
static void	enemy_step(t_game *g, int x, int y, int dir)
{
	char	e_char;
	int		nx;

	nx = x + dir;
	e_char = g->map[y][x];
	g->map[y][x] = g->tile_map[y][x];
	g->tile_map[y][nx] = g->map[y][nx];
	g->map[y][nx] = e_char;
	if (nx == g->player_x && y == g->player_y)
		g->is_game_over = 2;
}

/*switching between left(X) and right(H) enemies*/
static void	handle_enemy_logic(t_game *g, int x, int y, int w)
{
	if (g->map[y][x] == 'X')
	{
		if (x > 0 && (g->map[y][x - 1] == '0' || g->map[y][x - 1] == 'C'
				|| g->map[y][x - 1] == 'E'))
			enemy_step(g, x, y, -1);
		else
			g->map[y][x] = 'H';
	}
	else if (g->map[y][x] == 'H')
	{
		if (x < w - 1 && (g->map[y][x + 1] == '0' || g->map[y][x + 1] == 'C'
				|| g->map[y][x + 1] == 'E'))
			enemy_step(g, x, y, 1);
		else
			g->map[y][x] = 'X';
	}
}

/*if (x < w - 1 && g->map[y][x + 1] == 'H')
prevents same enemy from moving twice
loop dir -> right & enemy dir -> right*/
void	move_enemies_bonus(t_game *g)
{
	int	x;
	int	y;
	int	w;

	y = -1;
	w = get_map_width(g->map);
	while (g->map[++y])
	{
		x = -1;
		while (g->map[y][++x])
		{
			if (g->map[y][x] == 'X' || g->map[y][x] == 'H')
			{
				handle_enemy_logic(g, x, y, w);
				if (x < w - 1 && g->map[y][x + 1] == 'H')
					x++;
			}
		}
	}
}

int	animation_loop_bonus(t_game *g)
{
	static int	delay = 0;
	static int	end_timer = 0;

	if (g->is_game_over == 1 && ++end_timer > 500)
		close_game_bonus(g);
	if (g->is_game_over)
		return (draw_map_bonus(g), 0);
	end_timer = 0;
	check_exit_proximity(g);
	update_anim(g->anim_collect);
	update_anim(g->player_l);
	update_anim(g->player_r);
	update_anim(g->enemy_l);
	update_anim(g->enemy_r);
	update_exit_anim(g);
	if (delay++ < ENEMY_SPEED)
		return (draw_map_bonus(g), 0);
	delay = 0;
	move_enemies_bonus(g);
	return (draw_map_bonus(g), 0);
}
