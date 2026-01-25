/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_validation_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkyaw <lkyaw@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/25 15:43:48 by lkyaw             #+#    #+#             */
/*   Updated: 2026/01/25 15:43:48 by lkyaw            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "so_long_bonus.h"

static void	fill_bonus(char **map, int x, int y, t_check *check)
{
	if (y < 0 || x < 0 || !map[y] || !map[y][x] || map[y][x] == '1'
		|| map[y][x] == 'V' || map[y][x] == 'X' || map[y][x] == 'H')
		return ;
	if (map[y][x] == 'C')
		check->c_found++;
	if (map[y][x] == 'E')
		check->e_found = 1;
	map[y][x] = 'V';
	fill_bonus(map, x + 1, y, check);
	fill_bonus(map, x - 1, y, check);
	fill_bonus(map, x, y + 1, check);
	fill_bonus(map, x, y - 1, check);
}

static void	validate_path_bonus(char **map)
{
	char	**temp;
	t_check	check;
	int		total_c;
	int		i;
	int		j;

	total_c = 0;
	check.c_found = 0;
	check.e_found = 0;
	temp = copy_map(map);
	i = -1;
	while (map[++i])
	{
		j = -1;
		while (map[i][++j])
		{
			if (map[i][j] == 'C')
				total_c++;
			if (map[i][j] == 'P')
				fill_bonus(temp, j, i, &check);
		}
	}
	free_map(temp);
	if (check.e_found == 0 || check.c_found != total_c)
		error_exit("Error: No valid path to Exit or Collectibles");
}

static void	count_elements_bonus(char **map, int *p, int *e, int *c)
{
	int	i;
	int	j;

	i = -1;
	while (map[++i])
	{
		j = -1;
		while (map[i][++j])
		{
			if (map[i][j] == 'P')
				(*p)++;
			else if (map[i][j] == 'E')
				(*e)++;
			else if (map[i][j] == 'C')
				(*c)++;
			else if (map[i][j] != '0' && map[i][j] != '1' && map[i][j] != 'X'
				&& map[i][j] != 'H')
				error_exit("Error: Invalid character in bonus map");
		}
	}
}

void	validate_map_bonus(char **map)
{
	int	p;
	int	e;
	int	c;

	p = 0;
	e = 0;
	c = 0;
	if (!map || !map[0])
		error_exit(NULL);
	check_rectangular(map);
	check_walls(map);
	count_elements_bonus(map, &p, &e, &c);
	if (p != 1 || e != 1 || c < 1)
		error_exit("Error: Invalid map configuration");
	validate_path_bonus(map);
}

int	close_game_bonus(t_game *g)
{
	if (g->floor.ptr)
		mlx_destroy_image(g->mlx, g->floor.ptr);
	if (g->wall.ptr)
		mlx_destroy_image(g->mlx, g->wall.ptr);
	if (g->canvas.ptr)
		mlx_destroy_image(g->mlx, g->canvas.ptr);
	free_anim(g, g->player_l);
	free_anim(g, g->player_r);
	free_anim(g, g->anim_collect);
	free_anim(g, g->enemy_l);
	free_anim(g, g->enemy_r);
	free_anim(g, g->exit_anim);
	if (g->map)
		free_map(g->map);
	if (g->tile_map)
		free_map(g->tile_map);
	if (g->win)
		mlx_destroy_window(g->mlx, g->win);
	if (g->mlx)
	{
		mlx_destroy_display(g->mlx);
		free(g->mlx);
	}
	exit(0);
	return (0);
}
