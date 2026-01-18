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

void	init_player_pos(t_game *game)
{
	int	x;
	int	y;

	y = 0;
	game->collect_count = 0;
	while (game->map[y])
	{
		x = 0;
		while (game->map[y][x])
		{
			if (game->map[y][x] == 'P')
			{
				game->player_x = x;
				game->player_y = y;
			}
			if (game->map[y][x] == 'C')
				game->collect_count++;
			x++;
		}
		y++;
	}
}

void	execute_move(t_game *g, int new_x, int new_y)
{
	char	target;

	target = g->map[new_y][new_x];
	if (target == '1')
		return ;
	if (target == 'E' && g->collect_count == 0)
		close_game(g);
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
	if (keysym == 119)
		execute_move(game, game->player_x, game->player_y - 1);
	if (keysym == 115)
		execute_move(game, game->player_x, game->player_y + 1);
	if (keysym == 97)
		execute_move(game, game->player_x - 1, game->player_y);
	if (keysym == 100)
		execute_move(game, game->player_x + 1, game->player_y);
	return (0);
}
