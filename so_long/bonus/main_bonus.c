/* ************************************************************************** */
/* */
/* :::      ::::::::   */
/* main_bonus.c                                       :+:      :+:    :+:   */
/* +:+ +:+         +:+     */
/* By: lkyaw <lkyaw@student.42.fr>                +#+  +:+       +#+        */
/* +#+#+#+#+#+   +#+           */
/* Created: 2026/01/24 00:45:00 by lkyaw             #+#    #+#             */
/* Updated: 2026/01/24 00:45:00 by lkyaw            ###   ########.fr       */
/* */
/* ************************************************************************** */

#include "so_long_bonus.h"

/* ** Define the asset paths for the collectible animation.
** This uses your NULL-terminated string array logic.
*/
static char	*g_collect_paths[] = {"textures/collect/coin0.xpm",
		"textures/collect/coin1.xpm", "textures/collect/coin2.xpm",
		"textures/collect/coin3.xpm", "textures/collect/coin4.xpm", NULL};

static char	*g_enemy_l_paths[] = {"textures/enemy/enemyL0.xpm",
		"textures/enemy/enemyL1.xpm", "textures/enemy/enemyL2.xpm",
		"textures/enemy/enemyL3.xpm", "textures/enemy/enemyL4.xpm",
		"textures/enemy/enemyL5.xpm", "textures/enemy/enemyL6.xpm", NULL};
static char	*g_enemy_r_paths[] = {"textures/enemy/enemyR0.xpm",
		"textures/enemy/enemyR1.xpm", "textures/enemy/enemyR2.xpm",
		"textures/enemy/enemyR3.xpm", "textures/enemy/enemyR4.xpm",
		"textures/enemy/enemyR5.xpm", "textures/enemy/enemyR6.xpm", NULL};
static char	*g_p_l_paths[] = {"textures/player/playerL0.xpm",
		"textures/player/playerL1.xpm", "textures/player/playerL2.xpm",
		"textures/player/playerL3.xpm", "textures/player/playerL4.xpm",
		"textures/player/playerL5.xpm", NULL};
static char	*g_p_r_paths[] = {"textures/player/playerR0.xpm",
		"textures/player/playerR1.xpm", "textures/player/playerR2.xpm",
		"textures/player/playerR3.xpm", "textures/player/playerR4.xpm",
		"textures/player/playerR5.xpm", NULL};
static char	*g_exit_paths[] = {"textures/exit/exit0.xpm",
		"textures/exit/exit1.xpm", "textures/exit/exit2.xpm", NULL};
/* ** Creates the shadow map (tile_map) to store what's under moving entities.
** Replaces P, X, and H with '0' to keep the floor clean.
*/static char	**init_tile_map(char **map)
{
	int		i;
	int		j;
	char	**tile_map;

	i = 0;
	while (map[i])
		i++;
	tile_map = malloc(sizeof(char *) * (i + 1));
	if (!tile_map)
		return (NULL);
	i = -1;
	while (map[++i])
	{
		tile_map[i] = ft_strdup(map[i]);
		j = -1;
		while (tile_map[i][++j])
		{
			if (tile_map[i][j] == 'X' || tile_map[i][j] == 'H' || tile_map[i][j] == 'P')
				tile_map[i][j] = '0';
		}
	}
	tile_map[i] = NULL;
	return (tile_map);
}

int	main(int ac, char **av)
{
	t_game	g;

	if (ac != 2)
		return (1);
	ft_memset(&g, 0, sizeof(t_game));
	g.map = load_map(av[1]);
	if (!g.map)
		return (1);
	g.tile_map = init_tile_map(g.map);
	validate_map_bonus(g.map);
	g.width = get_map_width(g.map) * 32;
	g.height = get_map_height(g.map) * 32;
	g.mlx = mlx_init();
	g.win = mlx_new_window(g.mlx, g.width, g.height, "so_long Bonus");
	load_textures(&g);
	g.anim_collect = anim_create(&g, g_collect_paths, COLLECT_SPEED);
	g.player_l = anim_create(&g, g_p_l_paths, 12);
	g.player_r = anim_create(&g, g_p_r_paths, 12);
	g.enemy_l = anim_create(&g, g_enemy_l_paths, 10);
	g.enemy_r = anim_create(&g, g_enemy_r_paths, 10);
	g.exit_anim = anim_create(&g, g_exit_paths, 15);
	g.player_dir = 1;
	init_game_state(&g);
	mlx_hook(g.win, 2, 1L << 0, (int (*)())handle_keypress_bonus, &g);
	mlx_hook(g.win, 17, 0, close_game, &g);
	mlx_loop_hook(g.mlx, animation_loop_bonus, &g);
	mlx_loop(g.mlx);
	return (0);
}