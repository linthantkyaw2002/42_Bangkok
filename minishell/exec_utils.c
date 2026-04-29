/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkyaw <lkyaw@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/29 20:59:07 by lkyaw             #+#    #+#             */
/*   Updated: 2026/04/29 20:59:07 by lkyaw            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	env_list_size(t_env *env)
{
	int	i;

	i = 0;
	while (env)
	{
		i++;
		env = env->next;
	}
	return (i);
}

char	**env_to_array(t_env *env)
{
	char	**arr;
	int		i;
	char	*tmp;

	arr = malloc(sizeof(char *) * (env_list_size(env) + 1));
	if (!arr)
		return (NULL);
	i = 0;
	while (env)
	{
		if (env->value)
		{
			tmp = ft_strjoin(env->key, "=");
			arr[i] = ft_strjoin(tmp, env->value);
			free(tmp);
		}
		else
			arr[i] = ft_strdup(env->key);
		i++;
		env = env->next;
	}
	arr[i] = NULL;
	return (arr);
}

static void	free_split(char **split)
{
	int	i;

	i = 0;
	if (!split)
		return ;
	while (split[i])
		free(split[i++]);
	free(split);
}

static char	*find_valid_path(char **paths, char *cmd)
{
	char	*part;
	char	*full;
	int		i;

	i = -1;
	while (paths && paths[++i])
	{
		part = ft_strjoin(paths[i], "/");
		full = ft_strjoin(part, cmd);
		free(part);
		if (access(full, F_OK | X_OK) == 0)
			return (full);
		free(full);
	}
	return (NULL);
}

char	*get_cmd_path(char *cmd, t_env *env)
{
	char	**paths;
	char	*part;
	char	*full;

	if (!cmd || cmd[0] == '\0')
		return (NULL);
	if (ft_strchr(cmd, '/'))
		return (ft_strdup(cmd));
	part = get_env_value("PATH", env);
	if (!part)
		return (NULL);
	paths = ft_split(part, ':');
	full = find_valid_path(paths, cmd);
	free_split(paths);
	return (full);
}
