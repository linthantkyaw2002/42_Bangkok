/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkyaw <lkyaw@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/18 22:38:02 by lkyaw             #+#    #+#             */
/*   Updated: 2026/01/18 22:38:02 by lkyaw            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "so_long.h"

static void	render_move_count(t_game *g)
{
	char	*moves_str;

	moves_str = ft_itoa(g->moves);
	if (moves_str)
	{
		mlx_string_put(g->mlx, g->win, 10, 20, 0xFFFFFF, "Steps: ");
		mlx_string_put(g->mlx, g->win, 60, 20, 0xFFFFFF, moves_str);
		free(moves_str);
	}
}

/*(img->addr + (y * img->line_length + x * (img->bits_per_pixel / 8))))
from this you get start point
and type casting is how many bytes to read*/
static unsigned int	get_pixel_color(t_img *img, int j, int i)
{
	return (*(unsigned int *)(img->addr + (i * img->line_length + j
			* (img->bits_per_pixel / 8))));
}

//dst is destination address in canvas where we want to put the pixel color
static void	my_pixel_put(t_img *canvas, int j, int i, int color)
{
	char	*dst;

	if (color == (int)0xFF000000 || color == (int)0x000000)
		return ;
	dst = canvas->addr + (i * canvas->line_length + j * (canvas->bits_per_pixel
				/ 8));
	*(unsigned int *)dst = color;
}

//x and y are tile coordinates, not pixel coordinates
static void	draw_tile(t_game *g, t_img *img, int x, int y)
{
	int	i;
	int	j;

	i = 0;
	while (i < 32)
	{
		j = 0;
		while (j < 32)
		{
			my_pixel_put(&g->canvas, (x * 32) + j, (y * 32) + i,
				get_pixel_color(img, j, i));
			j++;
		}
		i++;
	}
}

void	draw_map(t_game *g)
{
	int	x;
	int	y;

	y = 0;
	while (g->map[y])
	{
		x = 0;
		while (g->map[y][x])
		{
			draw_tile(g, &g->floor, x, y);
			if (g->map[y][x] == '1')
				draw_tile(g, &g->wall, x, y);
			else if (g->map[y][x] == 'C')
				draw_tile(g, &g->collect, x, y);
			else if (g->map[y][x] == 'E' && g->collect_count == 0)
				draw_tile(g, &g->exit, x, y);
			if (x == g->player_x && y == g->player_y)
				draw_tile(g, &g->player, x, y);
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(g->mlx, g->win, g->canvas.ptr, 0, 0);
	render_move_count(g);
}
