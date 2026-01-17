#ifndef SO_LONG_H
# define SO_LONG_H

# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>

typedef struct s_img
{
	void	*img;
	int		w;
	int		h;
}	t_img;

typedef struct s_game
{
	void	*mlx;
	void	*win;
	char	**map;
	int		width;
	int		height;
	t_img	wall;
	t_img	floor;
	t_img	player;
	t_img	exit;
	t_img	collect;
}	t_game;


char	**load_map(char *path);
void	free_map(char **map);
void	validate_map(char **map);
void	flood_fill(char **map);
int	map_width(char **map);
int	map_height_arr(char **map);
void	load_textures(t_game *game);
void	draw_map(t_game *game);

#endif
