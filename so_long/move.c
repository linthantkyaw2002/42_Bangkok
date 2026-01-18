/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkyaw <lkyaw@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/18 22:47:35 by lkyaw             #+#    #+#             */
/*   Updated: 2026/01/18 22:47:35 by lkyaw            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "so_long.h"

static void	success_exit(t_game *g, int x, int y)
{
	g->player_x = x;
	g->player_y = y;
	draw_map(g);
	mlx_string_put(g->mlx, g->win, g->width / 2 - 30, g->height / 2,
		0x00FF00, "YOU WIN!");
	mlx_do_sync(g->mlx);
	usleep(3000000);
	close_game(g);
}

void	execute_move(t_game *g, int new_x, int new_y)
{
	char	target;

	target = g->map[new_y][new_x];
	if (target == '1')
		return ;
	if (target == 'E' && g->collect_count == 0)
	{
		success_exit(g, new_x, new_y);
		return ;
	}
	if (target == 'C')
	{
		g->collect_count--;
		g->map[new_y][new_x] = '0';
	}
	g->player_x = new_x;
	g->player_y = new_y;
	g->moves++;
	ft_putnbr_fd(g->moves, 1);
	ft_putchar_fd('\n', 1);
	draw_map(g);
}

int	handle_keypress(int keysym, t_game *game)
{
	if (keysym == 65307)
		close_game(game);
	if (keysym == 119 || keysym == 65362)
		execute_move(game, game->player_x, game->player_y - 1);
	if (keysym == 115 || keysym == 65364)
		execute_move(game, game->player_x, game->player_y + 1);
	if (keysym == 97 || keysym == 65361)
		execute_move(game, game->player_x - 1, game->player_y);
	if (keysym == 100 || keysym == 65363)
		execute_move(game, game->player_x + 1, game->player_y);
	return (0);
}
