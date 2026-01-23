#include "so_long_bonus.h"

static void	execute_player_move(t_game *g, int nx, int ny)
{
	char	target;

	if (g->is_game_over)
		return ;
	target = g->map[ny][nx];
	if (target == '1')
		return ;
	if (target == 'X' || target == 'H')
	{
		g->is_game_over = 2;
		return ;
	}
	if (target == 'C')
	{
		g->collect_count--;
		g->map[ny][nx] = '0';
		g->tile_map[ny][nx] = '0';
	}
	g->player_x = nx;
	g->player_y = ny;
	g->moves++;
	if (target == 'E' && g->collect_count == 0)
		g->is_game_over = 1;
	draw_map_bonus(g);
}

int	handle_keypress_bonus(int keysym, t_game *g)
{
	if (keysym == 65307)
		close_game(g);
	if (keysym == 119 || keysym == 65362) // Up
		execute_player_move(g, g->player_x, g->player_y - 1);
	else if (keysym == 115 || keysym == 65364) // Down
		execute_player_move(g, g->player_x, g->player_y + 1);
	else if (keysym == 97 || keysym == 65361) // Left
	{
		g->player_dir = 0;
		execute_player_move(g, g->player_x - 1, g->player_y);
	}
	else if (keysym == 100 || keysym == 65363) // Right
	{
		g->player_dir = 1;
		execute_player_move(g, g->player_x + 1, g->player_y);
	}
	return (0);
}