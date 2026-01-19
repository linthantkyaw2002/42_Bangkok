#include "so_long_bonus.h"

static char	**init_tile_map(char **map)
{
	int		i;
	int		j;
	char	**tile_map;

	if (!map) return (NULL);
	i = 0;
	while (map[i]) i++;
	tile_map = malloc(sizeof(char *) * (i + 1));
	if (!tile_map) return (NULL);
	i = -1;
	while (map[++i])
	{
		tile_map[i] = ft_strdup(map[i]);
		j = -1;
		while (tile_map[i][++j])
			if (tile_map[i][j] == 'X' || tile_map[i][j] == 'H' || tile_map[i][j] == 'P')
				tile_map[i][j] = '0';
	}
	tile_map[i] = NULL;
	return (tile_map);
}

int	main(int ac, char **av)
{
	t_game	g;

	if (ac != 2) return (1);
	ft_memset(&g, 0, sizeof(t_game));
	g.map = load_map(av[1]);
	if (!g.map) return (1);
	g.tile_map = init_tile_map(g.map);
	validate_map_bonus(g.map);
	g.width = get_map_width(g.map) * 32;
	g.height = get_map_height(g.map) * 32;
	g.mlx = mlx_init();
	g.win = mlx_new_window(g.mlx, g.width, g.height, "so_long Bonus");
	load_textures(&g);
	load_img(&g, &g.enemy, "textures/enemy.xpm");
	init_game_state(&g);
	g.is_game_over = 0;
	draw_map_bonus(&g);
	mlx_hook(g.win, 2, 1L<<0, (int (*)())handle_keypress_bonus, &g);
	mlx_hook(g.win, 17, 0, close_game, &g);
	mlx_loop_hook(g.mlx, animation_loop_bonus, &g);
	mlx_loop(g.mlx);
	return (0);
}