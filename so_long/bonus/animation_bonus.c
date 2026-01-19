#include "so_long_bonus.h"

static void	execute_enemy_step(t_game *g, int x, int y, int nx, int ny)
{
	char	enemy_char;

	enemy_char = g->map[y][x];
	g->map[y][x] = g->tile_map[y][x];
	g->tile_map[ny][nx] = g->map[ny][nx];
	g->map[ny][nx] = enemy_char;
	if (nx == g->player_x && ny == g->player_y)
		g->is_game_over = 2;
}

void	move_enemies_bonus(t_game *g)
{
	int x;
	int y = -1;
	int width = get_map_width(g->map);

	while (g->map[++y])
	{
		x = -1;
		while (g->map[y][++x])
		{
			if (g->map[y][x] == 'X' && x > 0 && g->map[y][x-1] != '1' 
				&& g->map[y][x-1] != 'X' && g->map[y][x-1] != 'H')
				execute_enemy_step(g, x, y, x - 1, y);
			else if (g->map[y][x] == 'X')
				g->map[y][x] = 'H';
			else if (g->map[y][x] == 'H' && x < width - 1 && g->map[y][x+1] != '1'
				&& g->map[y][x+1] != 'X' && g->map[y][x+1] != 'H')
			{
				execute_enemy_step(g, x, y, x + 1, y);
				x++; 
			}
			else if (g->map[y][x] == 'H')
				g->map[y][x] = 'X';
		}
	}
}

int	animation_loop_bonus(t_game *g)
{
	static int delay = 0;

	if (delay++ < 15000)
	{
		if (g->is_game_over) draw_map_bonus(g);
		return (0);
	}
	delay = 0;
	if (!g->is_game_over)
		move_enemies_bonus(g);
	draw_map_bonus(g);
	return (0);
}