/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkyaw <lkyaw@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/29 20:51:35 by lkyaw             #+#    #+#             */
/*   Updated: 2026/04/29 20:51:35 by lkyaw            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	is_builtin(char **args)
{
	if (!args || !args[0])
		return (0);
	if (ft_strncmp(args[0], "echo", 5) == 0 || ft_strncmp(args[0], "cd", 3) == 0
		|| ft_strncmp(args[0], "pwd", 4) == 0 || ft_strncmp(args[0], "export",
			7) == 0 || ft_strncmp(args[0], "unset", 6) == 0
		|| ft_strncmp(args[0], "env", 4) == 0 || ft_strncmp(args[0], "exit",
			5) == 0)
		return (1);
	return (0);
}

int	exe_builtin(char **args, t_shell *sh)
{
	if (ft_strncmp(args[0], "echo", 5) == 0)
		return (mini_echo(args));
	if (ft_strncmp(args[0], "pwd", 4) == 0)
		return (mini_pwd());
	if (ft_strncmp(args[0], "cd", 3) == 0)
		return (mini_cd(args, &sh->env));
	if (ft_strncmp(args[0], "env", 4) == 0)
		return (mini_env(sh->env));
	if (ft_strncmp(args[0], "export", 7) == 0)
		return (mini_export(args, &sh->env));
	if (ft_strncmp(args[0], "unset", 6) == 0)
		return (mini_unset(args, &sh->env));
	if (ft_strncmp(args[0], "exit", 5) == 0)
		return (mini_exit(args, sh));
	return (0);
}
