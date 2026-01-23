#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <time.h>

int	ft_strlen(char *s)
{
	int i = 0;
	while (s[i])
		i++;
	return (i);
}

/* ** Path carver that moves from P toward a random target (ex, ey)
** ensures a valid path exists even if the exit is anywhere on the map.
*/
static void	carve_rich_path(char **map, int ex, int ey)
{
	int	x;
	int	y;

	x = 1;
	y = 1;
	map[y][x] = 'P';
	while (x != ex || y != ey)
	{
		// Move toward exit coordinates randomly (Horizontal or Vertical)
		if (x != ex && (rand() % 2 || y == ey))
			x += (x < ex) ? 1 : -1;
		else if (y != ey)
			y += (y < ey) ? 1 : -1;
		
		if (map[y][x] == '1' || map[y][x] == '0')
		{
			if (rand() % 10 < 3)
				map[y][x] = 'C';
			else
				map[y][x] = '0';
		}
	}
	map[ey][ex] = 'E';
}

static void	scatter_bonus_coins(char **map, int w, int h, int level)
{
	int i, j, chance;

	chance = 5 + (level * 2); 
	i = 1;
	while (i < h - 1)
	{
		j = 1;
		while (j < w - 1)
		{
			if (map[i][j] == '0' && (rand() % 100 < chance))
				map[i][j] = 'C';
			j++;
		}
		i++;
	}
}

static char	**init_map(int w, int h)
{
	char	**map;
	int		i, j;

	map = malloc(sizeof(char *) * (h + 1));
	i = 0;
	while (i < h)
	{
		map[i] = malloc(w + 1);
		j = 0;
		while (j < w)
			map[i][j++] = '1';
		map[i][j] = '\0';
		i++;
	}
	map[i] = NULL;
	return (map);
}

static void	open_map(char **map, int w, int h)
{
	int i, j;

	i = 1;
	while (i < h - 1)
	{
		j = 1;
		while (j < w - 1)
		{
			if (rand() % 100 > 80)
				map[i][j] = '1';
			else
				map[i][j] = '0';
			j++;
		}
		i++;
	}
}

int	main(int ac, char **av)
{
	int level, w, h, fd, i;
	int ex, ey;
	char **map;

	if (ac != 2) return (write(1, "Usage: ./gen [1-5]\n", 19), 1);
	level = av[1][0] - '0';
	w = 20 + (level - 1) * 10;
	h = 10 + (level - 1) * 5;
	srand(time(NULL));

	map = init_map(w, h);
	open_map(map, w, h);

	// RANDOM DOOR POSITION: Anywhere inside the inner walls
	// Ensures it's not the same spot as Player (1,1)
	ex = (rand() % (w - 2)) + 1;
	ey = (rand() % (h - 2)) + 1;
	if (ex == 1 && ey == 1) // Simple collision check with Player
		ex = w - 2;

	carve_rich_path(map, ex, ey);
	scatter_bonus_coins(map, w, h, level);

	fd = open("map.ber", O_WRONLY | O_CREAT | O_TRUNC, 0644);
	i = 0;
	while (map[i])
	{
		write(fd, map[i], ft_strlen(map[i]));
		write(fd, "\n", 1);
		free(map[i++]);
	}
	free(map);
	close(fd);
	write(1, "Randomized Exit map generated!\n", 31);
	return (0);
}