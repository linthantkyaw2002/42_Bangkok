/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_fill.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkyaw <lkyaw@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/18 22:38:21 by lkyaw             #+#    #+#             */
/*   Updated: 2026/01/18 22:38:21 by lkyaw            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "so_long.h"

//just indexes of p in 2d array
static void	find_player(char **map, int *x, int *y)
{
	int	i;
	int	j;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == 'P')
			{
				*y = i;
				*x = j;
				return ;
			}
			j++;
		}
		i++;
	}
	error_exit("Error: Player not found");
}

//count all collectibles on the map by 2d array
static int	count_all_collectibles(char **map)
{
	int	i;
	int	j;
	int	count;

	count = 0;
	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == 'C')
				count++;
			j++;
		}
		i++;
	}
	return (count);
}

//flood fill algorithm to mark reachable areas, c & e are counted on the way
static void	fill(char **map, int y, int x, t_check *check)
{
	if (y < 0 || x < 0 || map[y][x] == '1' || map[y][x] == 'V')
		return ;
	if (map[y][x] == 'C')
		check->c_found++;
	if (map[y][x] == 'E')
		check->e_found = 1;
	map[y][x] = 'V';
	fill(map, y + 1, x, check);
	fill(map, y - 1, x, check);
	fill(map, y, x + 1, check);
	fill(map, y, x - 1, check);
}

/* 2. Main function goes at the bottom so it "sees" everything above it */
void	flood_fill(char **map)
{
	char	**copy;
	int		x;
	int		y;
	int		total_c;
	t_check	check;

	total_c = count_all_collectibles(map);
	copy = copy_map(map);
	find_player(copy, &x, &y);
	check.c_found = 0;
	check.e_found = 0;
	fill(copy, y, x, &check);
	free_map(copy);
	if (check.e_found == 0 || check.c_found != total_c)
	{
		free_map(map);
		error_exit("Error: Invalid map pathing");
	}
}
