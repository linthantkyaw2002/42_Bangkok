#include "so_long.h"
#include <mlx.h>
#include <X11/X.h>

int	close_game(t_game *game)
{
	free_map(game->map);
    // Add mlx_destroy_image for all textures here to get full marks
	mlx_destroy_window(game->mlx, game->win);
	exit(0);
	return (0);
}

int	main(int ac, char **av)
{
	t_game	game;

	if (ac != 2)
		return (1);
	game.map = load_map(av[1]);
	validate_map(game.map);
	flood_fill(game.map);

	game.width = map_width(game.map) * 32;
	game.height = map_height_arr(game.map) * 32;

	game.mlx = mlx_init();
	if (!game.mlx)
		return (1);
	game.win = mlx_new_window(game.mlx, game.width, game.height, "so_long");

	load_textures(&game);
	draw_map(&game);

	mlx_hook(game.win, 17, 0, close_game, &game);
	mlx_loop(game.mlx);
	return (0);
}
