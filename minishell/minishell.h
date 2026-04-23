#ifndef MINISHELL_H
# define MINISHELL_H

#include "./get_next_line/get_next_line.h"
# include "libft.h"
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <string.h>
# include <fcntl.h>
# include <sys/wait.h>
# include <signal.h>
# include <readline/readline.h>
# include <readline/history.h>

extern int g_signal_received;

/* ==========================================
   1. DATA STRUCTURES (Must be defined first)
   ========================================== */

typedef struct s_env
{
	char			*key;
	char			*value;
	struct s_env	*next;
}	t_env;

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

typedef struct s_shell
{
	t_env	*env;
	t_token	*tokens;
	int		last_exit;
}	t_shell;

typedef struct s_expand
{
	char	*str;
	int		i;
	int		in_single;
	int		in_double;
	t_shell	*shell;
}	t_expand;

typedef struct s_cmd
{
	char			**args;
	int				infile;
	int				outfile;
	int				append;
	int				heredoc;
	struct s_cmd	*next;
}	t_cmd;


/* ==========================================
   2. FUNCTION PROTOTYPES
   ========================================== */

// Libft Utils (Assuming these aren't in libft.h)
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

// Signal Handling
void	setup_signals(void);

// Environment Management
t_env	*init_env(char **envp);
char	*get_var_name(char *str, int *i);
char	*get_env_value(char *key, t_env *env);
void	set_env_value(t_env **env, char *key, char *value);

// Lexical Analysis
t_token	*tokenize(char *input);
void	add_back(t_token **list, t_token *new);
void	free_tokens(t_token *list);
int	check_syntax(t_token *tokens);

// Expander
char	*expand_string(char *str, t_shell *shell);
void	expand_list(t_shell *shell);
int		is_quote(char c, int *in_single, int *in_double);
char	*append_char(char *res, char c);
char	*append_str(char *res, const char *add);

// Parser
t_cmd	*parse_tokens(t_token *tokens);
void	free_cmds(t_cmd *head);

// Builtins
int	is_builtin(char **args);
int	exe_builtin(char **args, t_shell *sh);
int	mini_echo(char **args);
int	mini_pwd(void);
int	mini_cd(char **args, t_env *env);
int	mini_env(t_env *env);
int	mini_export(char **args, t_env **env);
int	mini_unset(char **args, t_env **env);
int	mini_exit(char **args, t_shell *sh);

#endif