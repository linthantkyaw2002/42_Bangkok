/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_keypress_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkyaw <lkyaw@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/25 15:39:15 by lkyaw             #+#    #+#             */
/*   Updated: 2026/01/25 15:39:15 by lkyaw            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

static void	handle_collectible(t_game *g, int nx, int ny)
{
	g->collect_count--;
	g->map[ny][nx] = '0';
	g->tile_map[ny][nx] = '0';
}

static void	check_move_result(t_game *g, char target)
{
	if (target == 'X' || target == 'H')
	{
		g->is_game_over = 2;
		ft_putstr_fd("GAME OVER! Press 'R' to restart\n", 1);
	}
	else if (target == 'E' && g->collect_count == 0)
	{
		g->is_game_over = 1;
		ft_putstr_fd("VICTORY! Closing soon...\n", 1);
	}
}

static void	execute_player_move(t_game *g, int nx, int ny)
{
	char	target;

	if (g->is_game_over)
		return ;
	target = g->map[ny][nx];
	if (target == '1')
		return ;
	if (target == 'C')
		handle_collectible(g, nx, ny);
	g->player_x = nx;
	g->player_y = ny;
	g->moves++;
	ft_putstr_fd("Moves: ", 1);
	ft_putnbr_fd(g->moves, 1);
	ft_putchar_fd('\n', 1);
	check_move_result(g, target);
}

int	handle_keypress_bonus(int keysym, t_game *g)
{
	if (keysym == 65307)
		close_game_bonus(g);
	if (keysym == 114)
		restart_game(g);
	if (g->is_game_over)
		return (0);
	if (keysym == 119 || keysym == 65362)
		execute_player_move(g, g->player_x, g->player_y - 1);
	else if (keysym == 115 || keysym == 65364)
		execute_player_move(g, g->player_x, g->player_y + 1);
	else if (keysym == 97 || keysym == 65361)
	{
		g->player_dir = 0;
		execute_player_move(g, g->player_x - 1, g->player_y);
	}
	else if (keysym == 100 || keysym == 65363)
	{
		g->player_dir = 1;
		execute_player_move(g, g->player_x + 1, g->player_y);
	}
	return (0);
}

void	restart_game(t_game *g)
{
	g->moves = 0;
	g->is_game_over = 0;
	g->player_dir = 1;
	free_map(g->map);
	free_map(g->tile_map);
	g->map = load_map(g->map_path);
	if (!g->map)
		error_exit("Error: Could not reload map");
	g->tile_map = init_tile_map(g->map);
	init_game_state(g);
	ft_putstr_fd("--- RESTARTED ---\n", 1);
}
