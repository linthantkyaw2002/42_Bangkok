/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkyaw <lkyaw@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/18 22:48:44 by lkyaw             #+#    #+#             */
/*   Updated: 2026/01/18 22:48:44 by lkyaw            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "so_long.h"

static void	load_img(t_game *g, t_img *img, char *path)
{
	img->ptr = mlx_xpm_file_to_image(g->mlx, path, &img->w, &img->h);
	if (!img->ptr)
	{
		ft_putendl_fd("Error: Failed to load texture", 2);
		exit(1);
	}
	img->addr = mlx_get_data_addr(img->ptr, &img->bits_per_pixel,
			&img->line_length, &img->endian);
}

void	load_textures(t_game *g)
{
	load_img(g, &g->floor, "textures/floor.xpm");
	load_img(g, &g->wall, "textures/wall.xpm");
	load_img(g, &g->collect, "textures/collect.xpm");
	load_img(g, &g->exit, "textures/exit.xpm");
	load_img(g, &g->player, "textures/player.xpm");
	g->canvas.ptr = mlx_new_image(g->mlx, g->width, g->height);
	g->canvas.addr = mlx_get_data_addr(g->canvas.ptr, &g->canvas.bits_per_pixel,
			&g->canvas.line_length, &g->canvas.endian);
}
