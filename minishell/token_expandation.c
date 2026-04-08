#include "minishell.h"

int is_quote(char c, int *in_single, int *in_double)
{
        if (c == '\'' && !(*in_double))
        {
                *in_single = !(*in_single);
                return (1);
        }
        if (c == '"' && !(*in_single))
        {
                *in_double = !(*in_double);
                return (1);
        }
        return (0);
}

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

char *append_char(char *res, char c)
{
        char *new;
        int len;

        len = 0;
        if (res)
                len = ft_strlen(res);

        new = malloc(len + 2);
        if (!new)
        {
                free(res); // Caller will lost reference to old string on failure, so free it here to prevent memory leak
                return (NULL);
        }
        if (res)
                ft_memcpy(new, res, len);

        new[len] = c;
        new[len + 1] = '\0';
        free(res);
        return (new);
}

char *append_str(char *res, const char *add)
{
        char *new;
        int len1;
        int len2;

        len1 = 0;
        if (res)
                len1 = ft_strlen(res);
        len2 = 0;
        if (add)
                len2 = ft_strlen(add);
        new = malloc(len1 + len2 + 1);
        if (!new)
        {
                free(res); // Caller will lost reference to old string on failure, so free it here to prevent memory leak
                return (NULL);
        }
        if (res)
                ft_memcpy(new, res, len1);
        if (add)
                ft_memcpy(new + len1, add, len2);

        new[len1 + len2] = '\0';
        free(res);
        return (new);
}

char *handle_exit(char *res, int *i, int last_exit)
{
        char *val;
        char *tmp;

        val = ft_itoa(last_exit);
        if (!val)
                return (NULL);
        tmp = append_str(res, val);
        free(val);
        if (!tmp)
                return (NULL);
        (*i)++;
        return (tmp);
}

char *handle_dollar(char *res, t_expand *exp)
{
    char *var;
    char *val;

    if (!exp->str[exp->i + 1] ||
        (!ft_isalpha(exp->str[exp->i + 1]) &&
         exp->str[exp->i + 1] != '_' &&
         exp->str[exp->i + 1] != '?'))
    {
        exp->i++;
        return (append_char(res, '$'));
    }

    exp->i++;

    if (exp->str[exp->i] == '?')
        return (handle_exit(res, &exp->i, exp->shell->last_exit));

    var = get_var_name(exp->str, &exp->i);
    if (!var)
        return (NULL);

    val = get_env_value(var, exp->shell->env);
    free(var);

    if (!val)
        val = "";

    return (append_str(res, val));
}
/*
static int init_expand(char *str, char **res, int *i,
                       int *in_single, int *in_double)
{
        if (!str)
                return (0);
        *i = 0;
        *in_single = 0;
        *in_double = 0;
        *res = ft_strdup("");
        return (*res != NULL);
}*/

static char *process_expand_char(char *res, t_expand *exp)
{
    if (is_quote(exp->str[exp->i], &exp->in_single, &exp->in_double))
    {
        exp->i++;
        return (res);
    }
    if (exp->str[exp->i] == '$' && !exp->in_single)
        return (handle_dollar(res, exp));
    return (append_char(res, exp->str[exp->i++]));
}

char *expand_string(char *str, t_shell *shell)
{
    t_expand   exp;
    char       *res;
    char       *tmp;

    if (!str)
        return (NULL);
    exp.str = str;
    exp.i = 0;
    exp.in_single = 0;
    exp.in_double = 0;
    exp.shell = shell;
    res = ft_strdup("");
    if (!res)
        return (NULL);
    while (exp.str[exp.i])
    {
        tmp = process_expand_char(res, &exp);
        if (!tmp)
        {
            free(res);
            return (NULL);
        }
        res = tmp;
    }
    return (res);
}
