#include "so_long_bonus.h"

/* ** The recursive algorithm that marks reachable tiles. 
** Enemies ('X', 'H') and Walls ('1') are treated as obstacles.
*/
static void	fill_bonus(char **map, int x, int y, t_check *check)
{
	if (y < 0 || x < 0 || !map[y] || !map[y][x] 
		|| map[y][x] == '1' || map[y][x] == 'V'
		|| map[y][x] == 'X' || map[y][x] == 'H')
		return ;
	if (map[y][x] == 'C')
		check->c_found++;
	if (map[y][x] == 'E')
		check->e_found = 1;
	map[y][x] = 'V'; // Mark as visited
	fill_bonus(map, x + 1, y, check);
	fill_bonus(map, x - 1, y, check);
	fill_bonus(map, x, y + 1, check);
	fill_bonus(map, x, y - 1, check);
}

/* ** Creates a copy using your mandatory utility and checks if the 
** player can reach all C and E without hitting enemies or walls.
*/
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
	temp = copy_map(map); // Reusing mandatory copy_map
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
	free_map(temp); // Reusing mandatory free_map
	if (check.e_found == 0 || check.c_found != total_c)
	{
		free_map(map);
		error_exit("Error: No valid path to Exit or Collectibles");
	}
}

/* ** Main entry point for bonus validation.
** Reuses mandatory geometric checks.
*/
void	validate_map_bonus(char **map)
{
	int	i;
	int	j;
	int	p = 0;
	int	e = 0;
	int	c = 0;

	if (!map || !map[0])
		error_exit(NULL);
	check_rectangular(map); // Reusing mandatory
	check_walls(map);       // Reusing mandatory
	i = -1;
	while (map[++i])
	{
		j = -1;
		while (map[i][++j])
		{
			if (map[i][j] == 'P') p++;
			else if (map[i][j] == 'E') e++;
			else if (map[i][j] == 'C') c++;
			else if (map[i][j] != '0' && map[i][j] != '1' 
					&& map[i][j] != 'X' && map[i][j] != 'H')
				error_exit("Error: Invalid character in bonus map");
		}
	}
	if (p != 1 || e != 1 || c < 1)
		error_exit("Error: Invalid map configuration");
	validate_path_bonus(map);
}
