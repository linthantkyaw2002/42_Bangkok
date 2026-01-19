#ifndef SO_LONG_BONUS_H
# define SO_LONG_BONUS_H

# include "../so_long.h"
# include "../libft.h"

/* Added to t_game struct in your original so_long.h:
** char **tile_map; // To store what is UNDER enemies at specific (y, x)
*/

void	validate_map_bonus(char **map);
int		draw_map_bonus(t_game *g);
int		animation_loop_bonus(t_game *g);
void	move_enemies_bonus(t_game *g);
int		handle_keypress_bonus(int keysym, t_game *game);

#endif