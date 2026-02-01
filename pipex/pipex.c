/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkyaw <lkyaw@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/02 03:39:39 by lkyaw             #+#    #+#             */
/*   Updated: 2026/02/02 03:39:39 by lkyaw            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	free_tab(char **tab)
{
	int	i;

	i = 0;
	if (!tab)
		return ;
	while (tab[i])
		free(tab[i++]);
	free(tab);
}

static char	*get_cmd_path(char *cmd, char **paths)
{
	char	*tmp;
	char	*path;
	int		i;

	i = -1;
	while (paths[++i])
	{
		tmp = ft_strjoin(paths[i], "/");
		path = ft_strjoin(tmp, cmd);
		free(tmp);
		if (access(path, F_OK) == 0)
			return (path);
		free(path);
	}
	return (NULL);
}

char	*find_path(char *cmd, char **envp)
{
	char	**paths;
	char	*path;
	int		i;

	if (ft_strncmp(cmd, "/", 1) == 0 || ft_strncmp(cmd, "./", 2) == 0)
	{
		if (access(cmd, F_OK) == 0)
			return (ft_strjoin(cmd, ""));
		return (NULL);
	}
	i = 0;
	while (envp[i] && ft_strncmp(envp[i], "PATH=", 5) != 0)
		i++;
	if (!envp[i])
		return (NULL);
	paths = ft_split(envp[i] + 5, ':');
	if (!paths)
		return (NULL);
	path = get_cmd_path(cmd, paths);
	free_tab(paths);
	return (path);
}

void	exec_cmd(char *cmd, char **envp)
{
	char	**args;
	char	*path;

	args = ft_split(cmd, ' ');
	if (!args || !args[0])
	{
		free_tab(args);
		exit(127);
	}
	path = find_path(args[0], envp);
	if (!path)
	{
		write(2, args[0], ft_strlen(args[0]));
		write(2, ": command not found\n", 20);
		free_tab(args);
		exit(127);
	}
	if (execve(path, args, envp) == -1)
	{
		perror("execve");
		free(path);
		free_tab(args);
		exit(1);
	}
}
