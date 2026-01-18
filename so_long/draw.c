#include "so_long.h"

static void	my_pixel_put(t_img *canvas, int x, int y, int color)
{
    // Skip transparency (0xFF000000 or 0x000000 depending on your XPM)
	if (color == (int)0xFF000000 || color == (int)0x000000)
		return ;
	char *dst = canvas->addr + (y * canvas->line_length + x * (canvas->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

static unsigned int	get_pixel_color(t_img *img, int x, int y)
{
	return (*(unsigned int *)(img->addr + (y * img->line_length + x * (img->bits_per_pixel / 8))));
}

static void	draw_tile(t_game *g, t_img *img, int x, int y)
{
	for (int i = 0; i < 32; i++)
	{
		for (int j = 0; j < 32; j++)
		{
			unsigned int color = get_pixel_color(img, j, i);
			my_pixel_put(&g->canvas, (x * 32) + j, (y * 32) + i, color);
		}
	}
}

void	draw_map(t_game *g)
{
	for (int y = 0; g->map[y]; y++)
	{
		for (int x = 0; g->map[y][x]; x++)
		{
			// Always draw floor first as background
			draw_tile(g, &g->floor, x, y);
			if (g->map[y][x] == '1')
				draw_tile(g, &g->wall, x, y);
			else if (g->map[y][x] == 'C')
				draw_tile(g, &g->collect, x, y);
			else if (g->map[y][x] == 'E')
				draw_tile(g, &g->exit, x, y);
			else if (g->map[y][x] == 'P')
				draw_tile(g, &g->player, x, y);
		}
	}
	mlx_put_image_to_window(g->mlx, g->win, g->canvas.ptr, 0, 0);
}
