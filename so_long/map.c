#include "so_long.h"
#include "get_next_line/get_next_line.h"
#include "libft.h"

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

char	**load_map(char *path)
{
	char	**map;
	int		fd;
	int		i;
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
	i = 0;
	while (i < height)
	{
		map[i] = get_next_line(fd);
		if (!map[i])
			break ;
		map[i] = ft_strtrim(map[i], "\n\r");
		i++;
	}
	map[i] = NULL;
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
		i++;
	}
	free(map);
}
