#include "minishell.h"
#include <stdlib.h>
#include <readline/readline.h>
#include <readline/history.h>

int	g_signal_received = 0;

// TEMPORARY DEBUG FUNCTION
void debug_print_cmds(t_cmd *cmd)
{
	int i;
	int cmd_num = 1;

	while (cmd)
	{
		printf("--- Command %d ---\n", cmd_num++);
		i = 0;
		if (cmd->args)
		{
			while (cmd->args[i])
			{
				printf("Arg[%d]: [%s]\n", i, cmd->args[i]);
				i++;
			}
		}
		printf("Infile FD: %d\n", cmd->infile);
		printf("Outfile FD: %d\n", cmd->outfile);
		cmd = cmd->next;
	}
}

static void	free_env(t_env *env)
{
	t_env	*tmp;

	while (env)
	{
		tmp = env->next;
		free(env->key);
		free(env->value);
		free(env);
		env = tmp;
	}
}

static void	init_shell(t_shell *shell, char **envp)
{
	shell->env = init_env(envp);
	shell->tokens = NULL;
	shell->last_exit = 0;
}

static void	process_line(char *input, t_shell *shell)
{
	t_cmd	*cmd_list;

	shell->tokens = tokenize(input);
	if (shell->tokens)
	{
		if (check_syntax(shell->tokens))
		{
			expand_list(shell);
			cmd_list = parse_tokens(shell->tokens);
			if (cmd_list)
			{
				debug_print_cmds(cmd_list);
				// execute_commands(cmd_list, shell);
				free_cmds(cmd_list);
			}
		}
		else
			shell->last_exit = 258;
		free_tokens(shell->tokens);
		shell->tokens = NULL;
	}
}

static char	*get_input(void)
{
	char	*input;
	int		len;

	if (isatty(STDIN_FILENO))
		return (readline("minishell$ "));
	input = get_next_line(STDIN_FILENO); // Assuming GNL is in your libft
	if (input)
	{
		len = ft_strlen(input);
		if (len > 0 && input[len - 1] == '\n')
			input[len - 1] = '\0';
	}
	return (input);
}

static void	shell_loop(t_shell *shell)
{
	char	*input;

	while (1)
	{
		input = get_input();
		if (!input)
		{
			if (isatty(STDIN_FILENO))
				write(STDOUT_FILENO, "exit\n", 5);
			break ;
		}
		if (isatty(STDIN_FILENO) && *input)
			add_history(input);
		process_line(input, shell);
		free(input);
	}
}
int	main(int argc, char **argv, char **envp)
{
	t_shell	shell;

	(void)argc;
	(void)argv;
	init_shell(&shell, envp);
	setup_signals();
	shell_loop(&shell);
	free_env(shell.env);
	rl_clear_history();
	return (shell.last_exit);
}