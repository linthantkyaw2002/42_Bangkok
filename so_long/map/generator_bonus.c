#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <time.h>

/* Simple strlen for write operations */
int	ft_strlen(char *s)
{
	int i = 0;
	while (s[i])
		i++;
	return (i);
}

/* Original path carver to ensure P can always reach E */
static void	carve_rich_path(char **map, int ex, int ey)
{
	int	x = 1;
	int	y = 1;

	map[y][x] = 'P';
	while (x != ex || y != ey)
	{
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

/* Updated scatter logic for Bonus: Places coins then enemies (X) based on ratio */
static void	scatter_entities(char **map, int w, int h, int level, int enemy_ratio)
{
	int i, j, chance, coin_count = 0;

	// 1. Scatter Coins
	chance = 5 + (level * 2); 
	for (i = 1; i < h - 1; i++)
	{
		for (j = 1; j < w - 1; j++)
		{
			if (map[i][j] == '0' && (rand() % 100 < chance))
			{
				map[i][j] = 'C';
				coin_count++;
			}
		}
	}

	// 2. Scatter Enemies based on ratio argument
	// Logic: (coins * ratio) / 10. If ratio is 5, it's 50% of coin count.
	int target_enemies = (coin_count * enemy_ratio) / 10;
	int enemies_placed = 0;
	while (enemies_placed < target_enemies)
	{
		i = (rand() % (h - 2)) + 1;
		j = (rand() % (w - 2)) + 1;
		if (map[i][j] == '0') 
		{
			map[i][j] = 'X';
			enemies_placed++;
		}
		if (enemies_placed > (w * h) / 3) break; // Overflow protection
	}
}

static char	**init_map(int w, int h)
{
	char	**map;
	int		i, j;

	map = malloc(sizeof(char *) * (h + 1));
	for (i = 0; i < h; i++)
	{
		map[i] = malloc(w + 1);
		for (j = 0; j < w; j++)
			map[i][j] = '1';
		map[i][j] = '\0';
	}
	map[i] = NULL;
	return (map);
}

static void	open_map(char **map, int w, int h)
{
	for (int i = 1; i < h - 1; i++)
	{
		for (int j = 1; j < w - 1; j++)
		{
			if (rand() % 100 > 80)
				map[i][j] = '1';
			else
				map[i][j] = '0';
		}
	}
}

int	main(int ac, char **av)
{
	int level, enemy_ratio, w, h, fd, i;
	int ex, ey;
	char **map;
	char *filename;

	if (ac < 3)
	{
		write(1, "Usage: ./gen [level] [ratio] [filename.ber]\n", 44);
		return (1);
	}

	level = (av[1][0] - '0');
	enemy_ratio = (av[2][0] - '0');
	filename = (ac == 4) ? av[3] : "map_bonus.ber";
	
	w = 20 + (level - 1) * 10;
	h = 10 + (level - 1) * 5;
	srand(time(NULL));

	map = init_map(w, h);
	open_map(map, w, h);

	ex = (rand() % (w - 2)) + 1;
	ey = (rand() % (h - 2)) + 1;
	if (ex == 1 && ey == 1) ex = w - 2;

	carve_rich_path(map, ex, ey);
	scatter_entities(map, w, h, level, enemy_ratio);

	fd = open(filename, O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (fd < 0) return (write(1, "Error opening file\n", 19), 1);

	i = 0;
	while (map[i])
	{
		write(fd, map[i], ft_strlen(map[i]));
		write(fd, "\n", 1);
		free(map[i++]);
	}
	free(map);
	close(fd);

	write(1, "Map generated: ", 15);
	write(1, filename, ft_strlen(filename));
	write(1, "\n", 1);
	return (0);
}