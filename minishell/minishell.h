#ifndef MINISHELL_H
# define MINISHELL_H

#include "libft.h"
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <string.h>
# include <fcntl.h>
# include <sys/wait.h>
# include <signal.h>

// Add these to minishell.h
size_t	ft_strlen(const char *s);
char	*ft_strdup(const char *s1);
int		ft_strcmp(const char *s1, const char *s2);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
char	*ft_substr(char const *s, unsigned int start, size_t len);
char	*ft_strchr(const char *s, int c);
void	*ft_memcpy(void *dst, const void *src, size_t n);
char	*ft_itoa(int n);
int		ft_isspace(char c);
int		ft_isalnum(int c);
int		ft_isalpha(int c);

typedef struct s_env
{
	char			*key;
	char			*value;
	struct s_env	*next;
}	t_env;

typedef struct s_shell
{
    t_env   *env;
    int     last_exit;
}   t_shell;

typedef enum s_token_type
{
	TOKEN_WORD,
	TOKEN_PIPE,
	TOKEN_REDIRECT_IN,
	TOKEN_REDIRECT_OUT,
	TOKEN_APPEND,
	TOKEN_HEREDOC,
	TOKEN_EOF
}	t_token_type;

typedef struct s_token
{
	char			*value;
	t_token_type	type;
	struct s_token	*next;
}	t_token;

typedef struct s_expand
{
    char        *str;
    int         i;
    int         in_single;
    int         in_double;
    t_shell     *shell;
}   t_expand;

typedef struct s_cmd
{
	char			**args;
	int				infile;
	int				outfile;
	int				append;
	int				heredoc;
	struct s_cmd	*next;
}	t_cmd;

t_token	*tokenize(char *input);
char	*expand_string(char *str, t_shell *shell);
t_cmd	*parse_tokens(t_token *tokens);
void	add_back(t_token **list, t_token *new);
void	free_tokens(t_token *list);

#endif
