#include "so_long.h"
#include "libft.h"

int	map_width(char **map)
{
	return (ft_strlen(map[0]));
}

int	map_height_arr(char **map)
{
	int	i;

	i = 0;
	while (map[i])
		i++;
	return (i);
}
