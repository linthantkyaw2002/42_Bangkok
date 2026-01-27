/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkyaw <lkyaw@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/25 15:23:43 by lkyaw             #+#    #+#             */
/*   Updated: 2026/01/25 15:23:43 by lkyaw            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

static void	init_enemy_anim(t_game *g)
{
	char	*el[8];
	char	*er[8];

	el[0] = "textures/enemy/enemyL0.xpm";
	el[1] = "textures/enemy/enemyL1.xpm";
	el[2] = "textures/enemy/enemyL2.xpm";
	el[3] = "textures/enemy/enemyL3.xpm";
	el[4] = "textures/enemy/enemyL4.xpm";
	el[5] = "textures/enemy/enemyL5.xpm";
	el[6] = "textures/enemy/enemyL6.xpm";
	el[7] = NULL;
	er[0] = "textures/enemy/enemyR0.xpm";
	er[1] = "textures/enemy/enemyR1.xpm";
	er[2] = "textures/enemy/enemyR2.xpm";
	er[3] = "textures/enemy/enemyR3.xpm";
	er[4] = "textures/enemy/enemyR4.xpm";
	er[5] = "textures/enemy/enemyR5.xpm";
	er[6] = "textures/enemy/enemyR6.xpm";
	er[7] = NULL;
	g->enemy_l = anim_create(g, el, ENEMY_ANIM_SPEED/get_speed_factor(g));
	g->enemy_r = anim_create(g, er, ENEMY_ANIM_SPEED/get_speed_factor(g));
}

static void	init_player_anim(t_game *g)
{
	char	*pl[7];
	char	*pr[7];

	pl[0] = "textures/player/playerL0.xpm";
	pl[1] = "textures/player/playerL1.xpm";
	pl[2] = "textures/player/playerL2.xpm";
	pl[3] = "textures/player/playerL3.xpm";
	pl[4] = "textures/player/playerL4.xpm";
	pl[5] = "textures/player/playerL5.xpm";
	pl[6] = NULL;
	pr[0] = "textures/player/playerR0.xpm";
	pr[1] = "textures/player/playerR1.xpm";
	pr[2] = "textures/player/playerR2.xpm";
	pr[3] = "textures/player/playerR3.xpm";
	pr[4] = "textures/player/playerR4.xpm";
	pr[5] = "textures/player/playerR5.xpm";
	pr[6] = NULL;
	g->player_l = anim_create(g, pl, PLAYER_ANIM_SPEED/get_speed_factor(g));
	g->player_r = anim_create(g, pr, PLAYER_ANIM_SPEED/get_speed_factor(g));
}

static void	init_animations_bonus(t_game *g)
{
	char	*c_p[6];
	char	*ex_p[4];

	c_p[0] = "textures/collect/coin0.xpm";
	c_p[1] = "textures/collect/coin1.xpm";
	c_p[2] = "textures/collect/coin2.xpm";
	c_p[3] = "textures/collect/coin3.xpm";
	c_p[4] = "textures/collect/coin4.xpm";
	c_p[5] = NULL;
	ex_p[0] = "textures/exit/exit0.xpm";
	ex_p[1] = "textures/exit/exit1.xpm";
	ex_p[2] = "textures/exit/exit2.xpm";
	ex_p[3] = NULL;
	g->anim_collect = anim_create(g, c_p, COLLECT_SPEED/get_speed_factor(g));
	g->exit_anim = anim_create(g, ex_p, COLLECT_SPEED/get_speed_factor(g));
	init_enemy_anim(g);
	init_player_anim(g);
}

/* make a copy of map without enemies and player */
char	**init_tile_map(char **map)
{
	int		i;
	int		j;
	char	**tile_map;

	i = get_map_height(map);
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
			if (tile_map[i][j] == 'X' || tile_map[i][j] == 'H'
				|| tile_map[i][j] == 'P')
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
		return (error_exit("Error: Invalid number of arguments"), 1);
	ft_memset(&g, 0, sizeof(t_game));
	g.map_path = av[1];
	g.map = load_map(av[1]);
	if (!g.map)
		return (error_exit("Error: Could not load map"), 1);
	g.tile_map = init_tile_map(g.map);
	validate_map_bonus(g.map);
	g.width = get_map_width(g.map) * 32;
	g.height = get_map_height(g.map) * 32;
	g.mlx = mlx_init();
	g.win = mlx_new_window(g.mlx, g.width, g.height, "so_long Bonus");
	load_textures_bonus(&g);
	init_animations_bonus(&g);
	g.player_dir = 1;
	init_game_state(&g);
	mlx_hook(g.win, 2, 1L << 0, (int (*)())handle_keypress_bonus, &g);
	mlx_hook(g.win, 17, 0, close_game_bonus, &g);
	mlx_loop_hook(g.mlx, animation_loop_bonus, &g);
	mlx_loop(g.mlx);
	return (0);
}
