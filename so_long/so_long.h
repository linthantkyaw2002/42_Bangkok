#ifndef SO_LONG_H
# define SO_LONG_H

# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <mlx.h>

typedef struct s_img {
    void    *ptr;
    char    *addr;
    int     bits_per_pixel;
    int     line_length;
    int     endian;
    int     w;
    int     h;
} t_img;

typedef struct s_game {
    void    *mlx;
    void    *win;
    char    **map;
    int     width;
    int     height;
    t_img   floor;
    t_img   wall;
    t_img   collect;
    t_img   exit;
    t_img   player;
    t_img   canvas;
} t_game;

// Function Prototypes
char	**load_map(char *path);
void	free_map(char **map);
void	validate_map(char **map);
void	flood_fill(char **map);
int	    map_width(char **map);
int	    map_height_arr(char **map);

void    load_textures(t_game *game);
void    draw_map(t_game *game);
int     close_game(t_game *game);

#endif
