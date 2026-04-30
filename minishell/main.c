/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkyaw <lkyaw@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/29 21:40:38 by lkyaw             #+#    #+#             */
/*   Updated: 2026/04/30 20:19:22 by lkyaw            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include <limits.h>
#include <readline/history.h>
#include <readline/readline.h>
#include <stdlib.h>

int			g_signal_received = 0;

static void	init_shell(t_shell *shell, char **envp)
{
	shell->env = init_env(envp);
	increment_shlvl(&shell->env);
	shell->tokens = NULL;
	shell->last_exit = 0;
}

static void	process_line(char *input, t_shell *shell)
{
	t_cmd	*cmd_list;

	g_signal_received = 0;
	shell->tokens = tokenize(input);
	if (shell->tokens)
	{
		if (check_syntax(shell->tokens))
		{
			expand_list(shell);
			cmd_list = parse_tokens(shell->tokens, shell);
			if (cmd_list)
			{
				if (g_signal_received != SIGINT)
					execute_commands(cmd_list, shell);
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
	input = read_byte_by_byte();
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
