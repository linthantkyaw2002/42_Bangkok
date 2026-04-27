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

static char	*check_direct_path(char *cmd)
{
	if (ft_strchr(cmd, '/') && access(cmd, F_OK | X_OK) == 0)
		return (ft_strdup(cmd));
	return (NULL);
}

char	*get_cmd_path(char *cmd, t_env *env)
{
	char **paths;
	char *part;
	char *full;
	int i;

	full = check_direct_path(cmd);
	if (full)
		return (full);
	part = get_env_value("PATH", env);
	if (!part)
		return (NULL);
	paths = ft_split(part, ':');
	i = -1;
	while (paths && paths[++i])
	{
		part = ft_strjoin(paths[i], "/");
		full = ft_strjoin(part, cmd);
		free(part);
		if (access(full, F_OK | X_OK) == 0)
			return (free_split(paths), full);
		free(full);
	}
	free_split(paths);
	return (NULL);
}