#include <stdlib.h>
#include "libft.h"
#include "minishell.h"

int     is_quote(char c, int *in_single, int *in_double)
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

char    *get_var_name(char *str, int *i)
{
        int     start;

        start = *i;
        while (str[*i] && (ft_isalnum(str[*i]) || str[*i] == '_'))
                (*i)++;
        return (ft_substr(str, start, *i - start));
}

char    *handle_dollar(char *str, int *i, char *res,
                        t_env *env, int last_exit)
{
        char    *var;
        char    *val;

        (*i)++;
        if (str[*i] == '?')
                return (handle_exit(res, i, last_exit));
        var = get_var_name(str, i);
        if (!var)
                return (NULL);
        val = get_env_value(var, env);
        free(var);
        if (!val)
                val = "";
        return (append_str(res, val));
}

char    *handle_exit(char *res, int *i, int last_exit)
{
        char    *val;
        char    *tmp;

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

char    *append_char(char *res, char c)
{
        char    *new;
        int     len;

        len = res ? ft_strlen(res) : 0;
        new = malloc(len + 2);
        if (!new)
        {
                free(res);
                return (NULL);
        }
        if (res)
                ft_memcpy(new, res, len);
        new[len] = c;
        new[len + 1] = '\0';
        free(res);
        return (new);
}

char    *append_str(char *res, const char *add)
{
        char    *new;
        int     len1;
        int     len2;

        len1 = res ? ft_strlen(res) : 0;
        len2 = add ? ft_strlen(add) : 0;
        new = malloc(len1 + len2 + 1);
        if (!new)
        {
                free(res);
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

static int  init_expand(char *str, char **res, int *i,
                        int *in_single, int *in_double)
{
        if (!str)
                return (0);
        *i = 0;
        *in_single = 0;
        *in_double = 0;
        *res = ft_strdup("");
        return (*res != NULL);
}

static char *process_expand_char(char *res, char *str, int *i,
                        int *in_single, int *in_double,
                        t_env *env, int last_exit)
{
        if (is_quote(str[*i], in_single, in_double))
        {
                (*i)++;
                return (res);
        }
        if (str[*i] == '$' && !*in_single)
                return (handle_dollar(str, i, res, env, last_exit));
        return (append_char(res, str[(*i)++]));
}

char    *expand_string(char *str, t_env *env, int last_exit)
{
        int     i;
        int     in_single;
        int     in_double;
        char    *res;

        if (!init_expand(str, &res, &i, &in_single, &in_double))
                return (NULL);
        while (str[i])
        {
                res = process_expand_char(res, str, &i,
                        &in_single, &in_double, env, last_exit);
                if (!res)
                        return (NULL);
        }
        return (res);
}
