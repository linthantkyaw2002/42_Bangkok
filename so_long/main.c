/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkyaw <lkyaw@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/18 22:42:39 by lkyaw             #+#    #+#             */
/*   Updated: 2026/01/18 22:42:39 by lkyaw            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include <X11/X.h>
#include <mlx.h>

int	main(int ac, char **av)
{
	t_game	game;

	if (ac != 2)
		return (1);
	game.map = load_map(av[1]);
	if (!game.map)
		return (1);
	validate_map(game.map);
	flood_fill(game.map);
	game.width = get_map_width(game.map) * 32;
	game.height = get_map_height(game.map) * 32;
	game.mlx = mlx_init();
	game.win = mlx_new_window(game.mlx, game.width, game.height, "so_long");
	load_textures(&game);
	init_game_state(&game);
	draw_map(&game);
	mlx_hook(game.win, KeyPress, KeyPressMask, handle_keypress, &game);
	mlx_hook(game.win, 17, 0, close_game, &game);
	mlx_loop(game.mlx);
	return (0);
}
