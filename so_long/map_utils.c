/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkyaw <lkyaw@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/18 22:43:43 by lkyaw             #+#    #+#             */
/*   Updated: 2026/01/18 22:43:43 by lkyaw            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "so_long.h"

// Initialize game state: find player position, collect count, move count
void	init_game_state(t_game *g)
{
	int	x;
	int	y;

	g->collect_count = 0;
	g->moves = 0;
	y = 0;
	while (g->map[y])
	{
		x = 0;
		while (g->map[y][x])
		{
			if (g->map[y][x] == 'P')
			{
				g->player_x = x;
				g->player_y = y;
			}
			else if (g->map[y][x] == 'C')
				g->collect_count++;
			x++;
		}
		y++;
	}
}

/* error exit for the whole project */
void	error_exit(char *message)
{
	if (message)
		ft_putendl_fd(message, 2);
	else
		ft_putendl_fd("Error", 2);
	exit(1);
}

/* Unified height function */
int	get_map_height(char **map)
{
	int	i;

	i = 0;
	while (map[i])
		i++;
	return (i);
}

/* Unified width function */
int	get_map_width(char **map)
{
	if (!map || !map[0])
		return (0);
	return (ft_strlen(map[0]));
}

/* copying for flood_fill or other logic */
char	**copy_map(char **map)
{
	char	**copy;
	int		height;
	int		i;

	height = get_map_height(map);
	copy = malloc(sizeof(char *) * (height + 1));
	if (!copy)
		error_exit("Error: Malloc failed in copy_map");
	i = 0;
	while (map[i])
	{
		copy[i] = ft_strdup(map[i]);
		if (!copy[i])
			error_exit("Error: Strdup failed in copy_map");
		i++;
	}
	copy[i] = NULL;
	return (copy);
}
