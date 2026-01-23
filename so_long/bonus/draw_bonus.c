#include "so_long_bonus.h"

static void	render_text_bonus(t_game *g)
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
			0xFF0000, "GAME OVER!");
}

int	draw_map_bonus(t_game *g)
{
	int		x;
	int		y;
	t_anim	*p_anim;

	y = -1;
	while (g->map[++y])
	{
		x = -1;
		while (g->map[y][++x])
		{
			draw_tile(g, &g->floor, x, y);
			if (g->map[y][x] == '1')
				draw_tile(g, &g->wall, x, y);
			else if (g->map[y][x] == 'C')
				draw_tile(g, &g->anim_collect->frames[g->anim_collect->current], x, y);
			/* Only draw the exit if all collectibles are collected */
			else if (g->map[y][x] == 'E' && g->collect_count == 0)
				draw_tile(g, &g->exit_anim->frames[g->exit_anim->current], x, y);
			else if (g->map[y][x] == 'X' || g->map[y][x] == 'H')
			{
				if (g->tile_map[y][x] == 'C')
					draw_tile(g, &g->collect, x, y);
				/* Draw exit under enemy only if available */
				else if (g->tile_map[y][x] == 'E' && g->collect_count == 0)
					draw_tile(g, &g->exit_anim->frames[g->exit_anim->current], x, y);
				if (g->map[y][x] == 'X')
					draw_tile(g, &g->enemy_l->frames[g->enemy_l->current], x, y);
				else
					draw_tile(g, &g->enemy_r->frames[g->enemy_r->current], x, y);
			}
			if (x == g->player_x && y == g->player_y)
			{
				p_anim = (g->player_dir == 0) ? g->player_l : g->player_r;
				draw_tile(g, &p_anim->frames[p_anim->current], x, y);
			}
		}
	}
	mlx_put_image_to_window(g->mlx, g->win, g->canvas.ptr, 0, 0);
	render_text_bonus(g);
	return (0);
}