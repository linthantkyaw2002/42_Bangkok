#include "so_long.h"
#include "libft.h"
#include <mlx.h>

static void	load_img(t_game *g, t_img *img, char *path)
{
	img->img = mlx_xpm_file_to_image(g->mlx, path, &img->w, &img->h);
	if (!img->img)
	{
		ft_putendl_fd("Error", 2);
		exit(1);
	}
}

void	load_textures(t_game *g)
{
	load_img(g, &g->wall, "textures/wall.xpm");
	load_img(g, &g->floor, "textures/floor.xpm");
	load_img(g, &g->player, "textures/player.xpm");
	load_img(g, &g->exit, "textures/exit.xpm");
	load_img(g, &g->collect, "textures/collect.xpm");
}
