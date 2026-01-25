/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkyaw <lkyaw@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/25 15:59:59 by lkyaw             #+#    #+#             */
/*   Updated: 2026/01/25 15:59:59 by lkyaw            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_BONUS_H
# define SO_LONG_BONUS_H

# include "../libft.h"
# include "../so_long.h"

# define ENEMY_SPEED 100
# define PLAYER_ANIM_SPEED 10
# define ENEMY_ANIM_SPEED 10
# define COLLECT_SPEED 30

typedef struct s_anim
{
	t_img	*frames;
	int		frame_count;
	int		current;
	int		speed;
	int		tick;
}			t_anim;

/* Prototypes */
t_anim		*anim_create(t_game *g, char **paths, int speed);
void		update_anim(t_anim *anim);
void		free_anim(t_game *g, t_anim *anim);
void		validate_map_bonus(char **map);
int			draw_map_bonus(t_game *g);
void		move_enemies_bonus(t_game *g);
int			handle_keypress_bonus(int keysym, t_game *game);
void		update_exit_anim(t_game *g);
char		**init_tile_map(char **map);
void		restart_game(t_game *g);
int			animation_loop_bonus(t_game *g);
int			ft_abs(int n);
void		load_textures_bonus(t_game *g);
int			close_game_bonus(t_game *g);
void		render_text_bonus(t_game *g);

#endif