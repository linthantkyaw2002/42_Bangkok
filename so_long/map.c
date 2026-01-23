/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkyaw <lkyaw@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/18 22:46:14 by lkyaw             #+#    #+#             */
/*   Updated: 2026/01/18 22:46:14 by lkyaw            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line/get_next_line.h"
#include "libft.h"
#include "so_long.h"

static int	file_height(char *path)
{
	int		fd;
	int		height;
	char	*line;

	height = 0;
	fd = open(path, O_RDONLY);
	if (fd < 0)
		return (-1);
	line = get_next_line(fd);
	while (line)
	{
		height++;
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
	return (height);
}

/* Helper to read lines from FD into the map array */
static void	read_map_lines(int fd, char **map, int height)
{
	int		i;
	char	*temp;

	i = 0;
	while (i < height)
	{
		temp = get_next_line(fd);
		if (temp)
		{
			map[i] = ft_strtrim(temp, "\n\r");
			free(temp);
		}
		i++;
	}
	map[i] = NULL;
	temp = get_next_line(fd);
	if (temp)
		free(temp);
}

char	**load_map(char *path)
{
	char	**map;
	int		fd;
	int		height;

	height = file_height(path);
	if (height <= 0)
		return (NULL);
	map = malloc(sizeof(char *) * (height + 1));
	if (!map)
		return (NULL);
	fd = open(path, O_RDONLY);
	if (fd < 0)
	{
		free(map);
		return (NULL);
	}
	read_map_lines(fd, map, height);
	close(fd);
	return (map);
}

void	free_map(char **map)
{
	int	i;

	if (!map)
		return ;
	i = 0;
	while (map[i])
	{
		free(map[i]);
		map[i] = NULL;
		i++;
	}
	free(map);
}
