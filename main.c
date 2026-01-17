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


int	close_win(void *param)
{
	(void)param;
	exit(0);
	return (0);
}

int	key_hook(int keycode, void *param)
{
	(void)param;
	if (keycode == 65307) // ESC
		exit(0);
	return (0);
}

int	main(void)
{
	void	*mlx;
	void	*win;
	void	*floor;
	void	*wall;
	int		w;
	int		h;
	int		x;
	int		y;

	mlx = mlx_init();
	if (!mlx)
		return (1);

	win = mlx_new_window(mlx, 320, 320, "Floor background test");
	if (!win)
		return (1);

	floor = mlx_xpm_file_to_image(mlx, "textures/floor.xpm", &w, &h);
	wall = mlx_xpm_file_to_image(mlx, "textures/wall.xpm", &w, &h);
	if (!floor || !wall)
		return (1);

	/* 1️⃣ draw floor everywhere (background) */
	y = 0;
	while (y < 10)
	{
		x = 0;
		while (x < 10)
		{
			mlx_put_image_to_window(mlx, win, floor, x * 32, y * 32);
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(mlx, win, floor, 0, 0);
	/* 2️⃣ draw wall on top */
	mlx_put_image_to_window(mlx, win, wall, 32, 32);
	/* close handlers */
	mlx_key_hook(win, key_hook, NULL);
	mlx_hook(win, DestroyNotify, 0, close_win, NULL);

	mlx_loop(mlx);
	return (0);
}

