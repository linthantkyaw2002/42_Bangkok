#include "so_long.h"
#include <mlx.h>

static void	draw_floor(t_game *g)
{
	int	y;
	int	x;

	y = 0;
	while (g->map[y])
	{
		x = 0;
		while (g->map[y][x])
		{
			mlx_put_image_to_window(
				g->mlx, g->win, g->floor.img, x * 32, y * 32);
			x++;
		}
		y++;
	}
}

static void	draw_objects(t_game *g, char target)
{
	int	y;
	int	x;

	y = 0;
	while (g->map[y])
	{
		x = 0;
		while (g->map[y][x])
		{
			if (g->map[y][x] == target)
			{
				if (target == '1')
					mlx_put_image_to_window(g->mlx, g->win,
						g->wall.img, x * 32, y * 32);
				else if (target == 'C')
					mlx_put_image_to_window(g->mlx, g->win,
						g->collect.img, x * 32, y * 32);
				else if (target == 'E')
					mlx_put_image_to_window(g->mlx, g->win,
						g->exit.img, x * 32, y * 32);
				else if (target == 'P')
					mlx_put_image_to_window(g->mlx, g->win,
						g->player.img, x * 32, y * 32);
			}
			x++;
		}
		y++;
	}
}

void	draw_map(t_game *g)
{
	draw_floor(g);        // layer 0
	draw_objects(g, '1'); // layer 1: walls
	draw_objects(g, 'C'); // layer 2: collectibles
	draw_objects(g, 'E'); // layer 3: exit
	draw_objects(g, 'P'); // layer 4: player (TOP)
}
