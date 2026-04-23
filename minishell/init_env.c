#include "minishell.h"

char *get_var_name(char *str, int *i)
{
        int start;

        start = *i;
        while (str[*i] && (ft_isalnum(str[*i]) || str[*i] == '_'))
                (*i)++;
        return (ft_substr(str, start, *i - start));
}

char *get_env_value(char *key, t_env *env)
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

static t_env	*create_env_node(char *env_str)
{
	t_env	*new;
	char	*sep;

	new = malloc(sizeof(t_env));
	if (!new)
		return (NULL);
	sep = ft_strchr(env_str, '=');
	if (!sep)
	{
		new->key = ft_strdup(env_str);
		new->value = NULL;
	}
	else
	{
		new->key = ft_substr(env_str, 0, sep - env_str);
		new->value = ft_strdup(sep + 1);
	}
	new->next = NULL;
	return (new);
}

t_env	*init_env(char **envp)
{
	t_env	*head;
	t_env	*curr;
	int		i;

	head = NULL;
	i = 0;
	while (envp && envp[i])
	{
		if (!head)
		{
			head = create_env_node(envp[i]);
			curr = head;
		}
		else
		{
			curr->next = create_env_node(envp[i]);
			if (curr->next)
				curr = curr->next;
		}
		i++;
	}
	return (head);
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
		if (ft_strncmp(curr->key, key, ft_strlen(key) + 1) == 0)
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