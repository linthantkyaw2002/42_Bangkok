/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkyaw <lkyaw@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/29 21:26:49 by lkyaw             #+#    #+#             */
/*   Updated: 2026/04/29 21:26:49 by lkyaw            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include "libft.h"
# include <errno.h>
# include <fcntl.h>
# include <limits.h>
# include <readline/history.h>
# include <readline/readline.h>
# include <signal.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <sys/stat.h>
# include <sys/wait.h>
# include <unistd.h>

extern int	g_signal_received;

typedef struct s_env
{
	char			*key;
	char			*value;
	struct s_env	*next;
}					t_env;

typedef enum s_token_type
{
	TOKEN_WORD,
	TOKEN_PIPE,
	TOKEN_REDIRECT_IN,
	TOKEN_REDIRECT_OUT,
	TOKEN_APPEND,
	TOKEN_HEREDOC,
	TOKEN_EOF
}					t_token_type;

typedef struct s_token
{
	char			*value;
	t_token_type	type;
	struct s_token	*next;
}					t_token;

typedef struct s_shell
{
	t_env			*env;
	t_token			*tokens;
	int				last_exit;
}					t_shell;

typedef struct s_expand
{
	char			*str;
	int				i;
	int				in_single;
	int				in_double;
	t_shell			*shell;
}					t_expand;

typedef struct s_cmd
{
	char			**args;
	int				infile;
	int				outfile;
	int				error;
	struct s_cmd	*next;
}					t_cmd;

/* ==========================================
   2. FUNCTION PROTOTYPES
   ========================================== */

// Libft Utils (Assuming these aren't in libft.h)
int					ft_isspace(char c);
int					ft_strcmp(const char *s1, const char *s2);

// Signal Handling
void				setup_signals(void);
void				setup_execution_signals(void);

// Environment Management
t_env				*init_env(char **envp);
char				*get_var_name(char *str, int *i);
char				*get_env_value(char *key, t_env *env);
void				set_env_value(t_env **env, char *key, char *value);
void				increment_shlvl(t_env **env);
void				free_env(t_env *env);

// Lexical Analysis
t_token				*tokenize(char *input);
void				add_back(t_token **list, t_token *new);
void				free_tokens(t_token *list);
int					check_syntax(t_token *tokens);

// Expander
char				*expand_string(char *str, t_shell *shell);
void				expand_list(t_shell *shell);
int					is_quote(char c, int *in_single, int *in_double);
char				*append_char(char *res, char c);
char				*append_str(char *res, const char *add);
int					count_args(t_token *tokens);
void				fill_args(t_cmd *cmd, t_token *tokens);
void				handle_redirection(t_cmd *cmd, t_token **tokens,
						t_shell *shell);
t_cmd				*new_cmd(void);

// Parser
t_cmd				*parse_tokens(t_token *tokens, t_shell *shell);
void				free_cmds(t_cmd *head);
char				*read_byte_by_byte(void);

// Builtins
int					is_builtin(char **args);
int					exe_builtin(char **args, t_shell *sh);
int					mini_echo(char **args);
int					mini_pwd(void);
int					mini_cd(char **args, t_env **env);
int					mini_env(t_env *env);
int					mini_export(char **args, t_env **env);
int					mini_unset(char **args, t_env **env);
int					mini_exit(char **args, t_shell *sh);

// Executor
char				*get_cmd_path(char *cmd, t_env *env);
char				**env_to_array(t_env *env);
void				execute_commands(t_cmd *cmd_list, t_shell *sh);
int					read_heredoc(char *delimiter, t_shell *shell);
void				handle_exec_error(char *path, char *cmd_name);

#endif
