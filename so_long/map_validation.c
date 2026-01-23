/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_validation.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkyaw <lkyaw@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/18 22:44:32 by lkyaw             #+#    #+#             */
/*   Updated: 2026/01/18 22:44:32 by lkyaw            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line/get_next_line.h"
#include "libft.h"
#include "so_long.h"

<<<<<<< HEAD
//if length of 1st line != length of any other line -> error
void	check_rectangular(char **map)
=======
static void	check_rectangular(char **map)
>>>>>>> parent of 96dfda3 (Memory Leak, error check ready for Mandatory)
{
	int	i;
	int	len;

	i = 0;
	len = ft_strlen(map[0]);
	while (map[i])
	{
		if ((int)ft_strlen(map[i]) != len)
			error_exit(NULL);
		i++;
	}
}

<<<<<<< HEAD
/*map is now rectangular, 1st row(0,0-w), 
last row (h-1,0-w), 1st col(0-h, 0), last col(0-h,w-1) must be '1'*/
void	check_walls(char **map)
=======
static void	check_walls(char **map)
>>>>>>> parent of 96dfda3 (Memory Leak, error check ready for Mandatory)
{
	int	i;
	int	j;
	int	h;
	int	w;

	h = get_map_height(map);
	w = get_map_width(map);
	j = 0;
	while (j < w)
		if (map[0][j++] != '1')
			error_exit(NULL);
	j = 0;
	while (j < w)
		if (map[h - 1][j++] != '1')
			error_exit(NULL);
	i = 0;
	while (i < h)
	{
		if (map[i][0] != '1' || map[i][w - 1] != '1')
			error_exit(NULL);
		i++;
	}
}

<<<<<<< HEAD
//how many P, E, C? in map
void	count_element(char c, int *p, int *e, int *c_count)
=======
static void	count_element(char c, int *p, int *e, int *c_count)
>>>>>>> parent of 96dfda3 (Memory Leak, error check ready for Mandatory)
{
	if (c == 'P')
		(*p)++;
	else if (c == 'E')
		(*e)++;
	else if (c == 'C')
		(*c_count)++;
	else if (c != '0' && c != '1')
		error_exit(NULL);
}

void	check_elements(char **map)
{
	int	i;
	int	j;
	int	p;
	int	e;
	int	c;

	p = 0;
	e = 0;
	c = 0;
	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			count_element(map[i][j], &p, &e, &c);
			j++;
		}
		i++;
	}
	if (p != 1 || e != 1 || c < 1)
		error_exit(NULL);
}

void	validate_map(char **map)
{
	if (!map || !map[0])
		error_exit(NULL);
	check_rectangular(map);
	check_walls(map);
	check_elements(map);
}
