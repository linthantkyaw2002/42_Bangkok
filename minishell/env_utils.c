#include "minishell.h"

char	*get_var_name(char *str, int *i)
{
	int	start;

	start = *i;
	while (str[*i] && (ft_isalnum(str[*i]) || str[*i] == '_'))
		(*i)++;
	return (ft_substr(str, start, *i - start));
}

char	*get_env_value(char *key, t_env *env)
{
	if (!key || !*key || !env)
		return (NULL);
	while (env)
	{
		if (env->key && ft_strcmp(env->key, key) == 0)
			return (env->value);
		env = env->next;
	}
	return (NULL);
}

static t_env	*create_env_kv(char *key, char *value)
{
	t_env	*new;

	new = malloc(sizeof(t_env));
	if (!new)
		return (NULL);
	new->key = ft_strdup(key);
	new->value = NULL;
	if (value)
		new->value = ft_strdup(value);
	new->next = NULL;
	return (new);
}

void	set_env_value(t_env **env, char *key, char *value)
{
	t_env	*curr;

	curr = *env;
	while (curr)
	{
		if (ft_strcmp(curr->key, key) == 0)
		{
			free(curr->value);
			curr->value = NULL;
			if (value)
				curr->value = ft_strdup(value);
			return ;
		}
		if (!curr->next)
			break ;
		curr = curr->next;
	}
	if (curr)
		curr->next = create_env_kv(key, value);
	else
		*env = create_env_kv(key, value);
}

void	increment_shlvl(t_env **env)
{
	char *current_val;
	char *new_val;
	int lvl;

	current_val = get_env_value("SHLVL", *env);
	if (current_val)
		lvl = ft_atoi(current_val) + 1;
	else
		lvl = 1;
	new_val = ft_itoa(lvl);
	if (new_val)
	{
		set_env_value(env, "SHLVL", new_val);
		free(new_val);
	}
}