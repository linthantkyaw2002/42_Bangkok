#include "so_long_bonus.h"

static void	count_element_bonus(char c, int *p, int *e, int *c_count)
{
	if (c == 'P')
		(*p)++;
	else if (c == 'E')
		(*e)++;
	else if (c == 'C')
		(*c_count)++;
	else if (c == 'X' || c == 'H' || c == '0' || c == '1')
		return ;
	else
		error_exit("Error: Invalid character in map");
}

void	validate_map_bonus(char **map)
{
	int	i;
	int	j;
	int	p = 0;
	int	e = 0;
	int	c = 0;

	check_rectangular(map); // Reuse
	check_walls(map);       // Reuse
	i = -1;
	while (map[++i])
	{
		j = -1;
		while (map[i][++j])
			count_element_bonus(map[i][j], &p, &e, &c);
	}
	if (p != 1 || e != 1 || c < 1)
		error_exit("Error: Map elements invalid");
}