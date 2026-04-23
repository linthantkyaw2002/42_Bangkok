#include "minishell.h"

int	mini_env(t_env *env)
{
	while (env)
	{
		if (env->value)
		{
			ft_putstr_fd(env->key, 1);
			write(1, "=", 1);
			ft_putendl_fd(env->value, 1);
		}
		env = env->next;
	}
	return (0);
}

static void	remove_node(t_env **env, t_env *curr, t_env *prev)
{
	if (prev)
		prev->next = curr->next;
	else
		*env = curr->next;
	free(curr->key);
	free(curr->value);
	free(curr);
}

int	mini_unset(char **args, t_env **env)
{
	t_env	*curr;
	t_env	*prev;
	int		i;

	i = 0;
	while (args[++i])
	{
		curr = *env;
		prev = NULL;
		while (curr)
		{
			if (ft_strncmp(curr->key, args[i], ft_strlen(args[i]) + 1) == 0)
			{
				remove_node(env, curr, prev);
				break ;
			}
			prev = curr;
			curr = curr->next;
		}
	}
	return (0);
}