#include "so_long.h"
#include "libft.h"

static void	error_exit(void)
{
	ft_putendl_fd("Error", 2);
	exit(1);
}

static int	map_height(char **map)
{
	int	i;

	i = 0;
	while (map[i])
		i++;
	return (i);
}


static void	check_rectangular(char **map)
{
	int	i;
	int	len;

	i = 0;
	len = ft_strlen(map[0]);
	while (map[i])
	{
		if ((int)ft_strlen(map[i]) != len)
			error_exit();
		i++;
	}
}

static void	check_walls(char **map)
{
	int	i;
	int	j;
	int	h;
	int	w;

	h = map_height(map);
	w = ft_strlen(map[0]);
	j = 0;
	while (j < w)
		if (map[0][j++] != '1')
			error_exit();
	j = 0;
	while (j < w)
		if (map[h - 1][j++] != '1')
			error_exit();
	i = 0;
	while (i < h)
	{
		if (map[i][0] != '1' || map[i][w - 1] != '1')
			error_exit();
		i++;
	}
}

static void	count_element(char c, int *p, int *e, int *c_count)
{
	if (c == 'P')
		(*p)++;
	else if (c == 'E')
		(*e)++;
	else if (c == 'C')
		(*c_count)++;
	else if (c != '0' && c != '1')
		error_exit();
}

static void	check_elements(char **map)
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
		error_exit();
}

void	validate_map(char **map)
{
	if (!map || !map[0])
		error_exit();
	check_rectangular(map);
	check_walls(map);
	check_elements(map);
}
