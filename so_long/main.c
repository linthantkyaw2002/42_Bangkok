#include "libft.h"
#include "so_long.h"
#include <mlx.h>
#include <X11/X.h>


//static int	close_game(t_game *game)
//{
//	mlx_destroy_window(game->mlx, game->win);
//	free_map(game->map);
//	exit(0);
//	return (0);
//}

//int	main(int ac, char **av)
//{
//	t_game	game;

//	if (ac != 2)
//		return (1);
//	game.map = load_map(av[1]);
//	validate_map(game.map);
//	flood_fill(game.map);
//	game.width = map_width(game.map) * 32;
//	game.height = map_height_arr(game.map) * 32;
//	game.mlx = mlx_init();
//	if (!game.mlx)
//		return (1);
//	game.win = mlx_new_window(game.mlx, game.width, game.height, "so_long");
//	mlx_hook(game.win, 17, 0, close_game, &game);
//	load_textures(&game);
//	draw_map(&game);
//	mlx_loop(game.mlx);
//}
#include <mlx.h>
#include <stdlib.h>
#include <X11/X.h>

int	close_win(void *p)
{
	(void)p;
	exit(0);
	return (0);
}

int	main(void)
{
	void	*mlx;
	void	*win;
	void	*floor;
	void	*overlay;
	int		w;
	int		h;

	mlx = mlx_init();
	if (!mlx)
		return (1);

	win = mlx_new_window(mlx, 320, 320, "XPM transparency test");
	if (!win)
		return (1);

	/* load floor from file */
	floor = mlx_xpm_file_to_image(
		mlx, "textures/floor.xpm", &w, &h
	);
	if (!floor)
		return (1);

	/* load transparent overlay FROM FILE */
	overlay = mlx_xpm_file_to_image(
		mlx, "textures/test.xpm", &w, &h
	);
	if (!overlay)
		return (1);

	/* draw floor first */
	mlx_put_image_to_window(mlx, win, floor, 0, 0);

	/* overlay transparent image */
	mlx_put_image_to_window(mlx, win, overlay, 0, 0);

	mlx_hook(win, DestroyNotify, 0, close_win, NULL);
	mlx_loop(mlx);
	return (0);
}
