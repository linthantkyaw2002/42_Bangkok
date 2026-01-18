/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkyaw <lkyaw@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/18 22:48:22 by lkyaw             #+#    #+#             */
/*   Updated: 2026/01/18 22:48:22 by lkyaw            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <fcntl.h>
# include <mlx.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_check
{
	int	c_found;
	int	e_found;
}	t_check;

typedef struct s_img
{
	void	*ptr;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
	int		w;
	int		h;
}			t_img;

typedef struct s_game
{
	void	*mlx;
	void	*win;
	char	**map;
	int		width;
	int		height;
	int		player_x;
	int		player_y;
	int		collect_count;
	int		moves;
	t_img	floor;
	t_img	wall;
	t_img	collect;
	t_img	exit;
	t_img	player;
	t_img	canvas;
}			t_game;

void		error_exit(char *message);
int			get_map_height(char **map);
int			get_map_width(char **map);
char		**copy_map(char **map);
int			handle_keypress(int keysym, t_game *game);
char		**load_map(char *path);
void		free_map(char **map);
void		validate_map(char **map);
void		flood_fill(char **map);
void		init_game_state(t_game *game);
void		load_textures(t_game *game);
void		draw_map(t_game *game);
int			close_game(t_game *game);

#endif
