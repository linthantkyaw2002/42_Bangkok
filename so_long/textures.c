#include "so_long.h"
#include "libft.h"
#include <mlx.h>

//static void	load_img(t_game *g, t_img *img, char *path)
//{
//	img->img = mlx_xpm_file_to_image(g->mlx, path, &img->w, &img->h);
//	if (!img->img)
//	{
//		ft_putendl_fd("Error: failed to load texture", 2);
//		exit(1);
//	}
//	img->addr = mlx_get_data_addr(
//		img->img,
//		&img->bpp,
//		&img->line_len,
//		&img->endian
//	);
//	if (!img->addr)
//	{
//		ft_putendl_fd("Error: failed to get image data", 2);
//		exit(1);
//	}
//}
