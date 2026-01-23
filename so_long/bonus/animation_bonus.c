#include "so_long_bonus.h"

/* ** Restoration logic:
** 1. Put back whatever was under the enemy at its old position.
** 2. Store whatever is at the new target position into the shadow map.
** 3. Move the enemy and check for player collision.
*/
static void	check_exit_proximity(t_game *g)
{
	int	x;
	int	y;

	y = -1;
	while (g->map[++y])
	{
		x = -1;
		while (g->map[y][++x])
		{
			if (g->map[y][x] == 'E')
			{
				if (abs(g->player_x - x) <= 1 && abs(g->player_y - y) <= 1)
					g->exit_open = 1;
				else
					g->exit_open = 0;
				return ;
			}
		}
	}
}

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

/* ** Movement logic:
** Enemies can now move into '0', 'C', or 'E'.
** The tile_map preserves these items while the enemy is on top of them.
*/
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
			if (g->map[y][x] == 'X')
			{
				if (x > 0 && (g->map[y][x - 1] == '0' || g->map[y][x - 1] == 'C' 
					|| g->map[y][x - 1] == 'E'))
					execute_enemy_step(g, x, y, x - 1, y);
				else
					g->map[y][x] = 'H';
			}
			else if (g->map[y][x] == 'H')
			{
				if (x < width - 1 && (g->map[y][x + 1] == '0' 
					|| g->map[y][x + 1] == 'C' || g->map[y][x + 1] == 'E'))
				{
					execute_enemy_step(g, x, y, x + 1, y);
					x++; 
				}
				else
					g->map[y][x] = 'X';
			}
		}
	}
}

/* ** Loop logic:
** Redraws every frame so animations remain smooth.
** Updates animation frames independently of logical movement.
*/int	animation_loop_bonus(t_game *g)
{
	static int delay = 0;

	if (g->is_game_over)
	{
		draw_map_bonus(g);
		return (0);
	}
	/* Update all constant animations */
	update_anim(g->anim_collect);
	update_anim(g->enemy_l);
	update_anim(g->enemy_r);
	update_anim(g->player_l);
	update_anim(g->player_r);

	/* Update conditional exit animation */
	check_exit_proximity(g);
	update_exit_anim(g);

	if (delay++ < ENEMY_SPEED)
	{
		draw_map_bonus(g);
		return (0);
	}
	delay = 0;
	move_enemies_bonus(g);
	draw_map_bonus(g);
	return (0);
}