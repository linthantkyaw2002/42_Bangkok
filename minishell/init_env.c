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