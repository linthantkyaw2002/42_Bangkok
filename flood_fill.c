#include "so_long.h"
#include "libft.h"

static void	error_exit(void)
{
	ft_putendl_fd("Error", 2);
	exit(1);
}

static char	**copy_map(char **map)
{
	char	**copy;
	int		i;

	i = 0;
	while (map[i])
		i++;
	copy = malloc(sizeof(char *) * (i + 1));
	if (!copy)
		error_exit();
	i = 0;
	while (map[i])
	{
		copy[i] = ft_strdup(map[i]);
		if (!copy[i])
			error_exit();
		i++;
	}
	copy[i] = NULL;
	return (copy);
}

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
	error_exit();
}

static void	fill(char **map, int y, int x, int *c, int *e)
{
	if (map[y][x] == '1' || map[y][x] == 'V')
		return ;
	if (map[y][x] == 'C')
		(*c)++;
	if (map[y][x] == 'E')
		(*e) = 1;
	map[y][x] = 'V';
	fill(map, y + 1, x, c, e);
	fill(map, y - 1, x, c, e);
	fill(map, y, x + 1, c, e);
	fill(map, y, x - 1, c, e);
}

void	flood_fill(char **map)
{
	char	**copy;
	int		x;
	int		y;
	int		c;
	int		e;

	copy = copy_map(map);
	find_player(copy, &x, &y);
	c = 0;
	e = 0;
	fill(copy, y, x, &c, &e);
	free_map(copy);
	if (c == 0 || e == 0)
		error_exit();
}
