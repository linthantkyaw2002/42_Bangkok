#ifndef SO_LONG_BONUS_H
# define SO_LONG_BONUS_H

# include "../so_long.h"
# include "../libft.h"

# define ENEMY_SPEED 100
# define PLAYER_ANIM_SPEED 10
# define ENEMY_ANIM_SPEED 10
# define COLLECT_SPEED 30
/* Added to t_game struct in your original so_long.h:
** char **tile_map; // To store what is UNDER enemies at specific (y, x)
*/

typedef struct s_anim
{
	t_img	*frames;
	int		frame_count;
	int		current;
	int		speed;
	int		tick;
}	t_anim;

t_anim	*anim_create(t_game *g, char **paths, int speed);
void	update_anim(t_anim *anim);
void	free_anim(t_game *g, t_anim *anim);
void	validate_map_bonus(char **map);
int		draw_map_bonus(t_game *g);
int		animation_loop_bonus(t_game *g);
void	move_enemies_bonus(t_game *g);
int		handle_keypress_bonus(int keysym, t_game *game);
void	update_exit_anim(t_game *g);

#endif