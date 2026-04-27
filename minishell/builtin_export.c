#include "minishell.h"

static int	is_valid_env_key(char *key)
{
	int	i;

	i = 0;
	if (!key || (!ft_isalpha(key[0]) && key[0] != '_'))
		return (0);
	while (key[i] && key[i] != '=')
	{
		if (!ft_isalnum(key[i]) && key[i] != '_')
			return (0);
		i++;
	}
	return (1);
}

static void	process_export_arg(t_env **env, char *arg)
{
	char	*sep;
	char	*key;
	char	*val;

	sep = ft_strchr(arg, '=');
	if (!sep)
	{
		if (!get_env_value(arg, *env))
			set_env_value(env, arg, NULL);
		return ;
	}
	key = ft_substr(arg, 0, sep - arg);
	val = ft_strdup(sep + 1);
	set_env_value(env, key, val);
	free(key);
	free(val);
}

int	mini_export(char **args, t_env **env)
{
	int i;
	int status;

	i = 1;
	status = 0;
	if (!args[1])
		return (0);
	while (args[i])
	{
		if (!is_valid_env_key(args[i]))
		{
			ft_putstr_fd("minishell: export: `", 2);
			ft_putstr_fd(args[i], 2);
			ft_putendl_fd("': not a valid identifier", 2);
			status = 1;
		}
		else
			process_export_arg(env, args[i]);
		i++;
	}
	return (status);
}