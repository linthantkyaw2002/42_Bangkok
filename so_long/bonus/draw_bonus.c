/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkyaw <lkyaw@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/25 20:23:16 by lkyaw             #+#    #+#             */
/*   Updated: 2026/01/25 20:23:16 by lkyaw            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

/* Renders movement count and end-game messages directly to the window */
void	render_text_bonus(t_game *g)
{
	char	*moves;

	moves = ft_itoa(g->moves);
	if (moves)
	{
		mlx_string_put(g->mlx, g->win, 20, 20, 0xFFFFFF, "Steps: ");
		mlx_string_put(g->mlx, g->win, 70, 20, 0xFFFFFF, moves);
		free(moves);
	}
	if (g->is_game_over == 1)
		mlx_string_put(g->mlx, g->win, g->width / 2 - 30, g->height / 2,
			0x00FF00, "VICTORY!");
	else if (g->is_game_over == 2)
		mlx_string_put(g->mlx, g->win, g->width / 2 - 30, g->height / 2,
			0xFF0000, "GAME OVER! Press 'R' to restart");
}

/* Draws background-layer elements like collectibles and exits */
static void	draw_back_tile(t_game *g, int x, int y)
{
	if (g->map[y][x] == 'C' || g->tile_map[y][x] == 'C')
		draw_tile(g, &g->anim_collect->frames[g->anim_collect->current], x, y);
	else if ((g->map[y][x] == 'E' || g->tile_map[y][x] == 'E')
		&& g->collect_count == 0)
		draw_tile(g, &g->exit_anim->frames[g->exit_anim->current], x, y);
}

/* Draws active entities like the player and patrolling enemies */
static void	draw_entities(t_game *g, int x, int y)
{
	t_anim	*p_anim;

	if (g->map[y][x] == 'X')
		draw_tile(g, &g->enemy_l->frames[g->enemy_l->current], x, y);
	else if (g->map[y][x] == 'H')
		draw_tile(g, &g->enemy_r->frames[g->enemy_r->current], x, y);
	if (x == g->player_x && y == g->player_y)
	{
		if (g->player_dir == 0)
			p_anim = g->player_l;
		else
			p_anim = g->player_r;
		draw_tile(g, &p_anim->frames[p_anim->current], x, y);
	}
}

/* Main drawing function called by the loop hook */
int	draw_map_bonus(t_game *g)
{
	int	x;
	int	y;

	y = -1;
	while (g->map[++y])
	{
		x = -1;
		while (g->map[y][++x])
		{
			draw_tile(g, &g->floor, x, y);
			if (g->map[y][x] == '1')
				draw_tile(g, &g->wall, x, y);
			else
			{
				draw_back_tile(g, x, y);
				draw_entities(g, x, y);
			}
		}
	}
	mlx_put_image_to_window(g->mlx, g->win, g->canvas.ptr, 0, 0);
	render_text_bonus(g);
	return (0);
}

void	load_textures_bonus(t_game *g)
{
	load_img(g, &g->floor, "textures/floor.xpm");
	load_img(g, &g->wall, "textures/wall.xpm");
	g->canvas.ptr = mlx_new_image(g->mlx, g->width, g->height);
	if (!g->canvas.ptr)
		error_exit("Error: Failed to create canvas");
	g->canvas.addr = mlx_get_data_addr(g->canvas.ptr, &g->canvas.bits_per_pixel,
			&g->canvas.line_length, &g->canvas.endian);
}
