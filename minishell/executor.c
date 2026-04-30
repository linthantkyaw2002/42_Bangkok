/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   executor.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkyaw <lkyaw@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/29 21:19:23 by lkyaw             #+#    #+#             */
/*   Updated: 2026/04/29 21:19:23 by lkyaw            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	handle_io(t_cmd *cmd, int prev_fd, int p_fd[2])
{
	if (cmd->infile >= 0)
		dup2(cmd->infile, STDIN_FILENO);
	else if (prev_fd != -1)
		dup2(prev_fd, STDIN_FILENO);
	if (cmd->outfile >= 0)
		dup2(cmd->outfile, STDOUT_FILENO);
	else if (cmd->next)
		dup2(p_fd[1], STDOUT_FILENO);
	if (prev_fd != -1)
		close(prev_fd);
	if (cmd->next)
	{
		close(p_fd[0]);
		close(p_fd[1]);
	}
	if (cmd->infile >= 0)
		close(cmd->infile);
	if (cmd->outfile >= 0)
		close(cmd->outfile);
}

static void	run_child(t_cmd *cmd, t_shell *sh, int prev_fd, int p_fd[2])
{
	char	*path;
	char	**envp;
	int		j;

	if (cmd->error)
		exit(1);
	signal(SIGINT, SIG_DFL);
	signal(SIGQUIT, SIG_DFL);
	handle_io(cmd, prev_fd, p_fd);
	if (!cmd->args || !cmd->args[0])
		exit(0);
	if (is_builtin(cmd->args))
		exit(exe_builtin(cmd->args, sh));
	path = get_cmd_path(cmd->args[0], sh->env);
	if (path)
	{
		envp = env_to_array(sh->env);
		execve(path, cmd->args, envp);
		j = -1;
		while (envp && envp[++j])
			free(envp[j]);
		free(envp);
	}
	handle_exec_error(path, cmd->args[0]);
}

static void	wait_pipeline(pid_t last_pid, t_shell *sh)
{
	int	status;

	waitpid(last_pid, &status, 0);
	while (wait(NULL) > 0)
		;
	if (WIFSIGNALED(status))
	{
		if (WTERMSIG(status) == SIGINT)
			write(STDOUT_FILENO, "\n", 1);
		else if (WTERMSIG(status) == SIGQUIT)
			ft_putstr_fd("Quit (core dumped)\n", 2);
		sh->last_exit = 128 + WTERMSIG(status);
	}
	else if (WIFEXITED(status))
		sh->last_exit = WEXITSTATUS(status);
	setup_signals();
}

static void	fork_commands(t_cmd *cmd, t_shell *sh)
{
	int		p_fd[2];
	int		prev_fd;
	pid_t	pid;

	prev_fd = -1;
	pid = -1;
	setup_execution_signals();
	while (cmd)
	{
		if (cmd->next)
			pipe(p_fd);
		pid = fork();
		if (pid == 0)
			run_child(cmd, sh, prev_fd, p_fd);
		if (prev_fd != -1)
			close(prev_fd);
		if (cmd->next)
		{
			close(p_fd[1]);
			prev_fd = p_fd[0];
		}
		cmd = cmd->next;
	}
	if (pid != -1)
		wait_pipeline(pid, sh);
}

void	execute_commands(t_cmd *cmd, t_shell *sh)
{
	int	fd[2];

	if (!cmd)
		return ;
	if (!cmd->next && cmd->error == 1)
	{
		sh->last_exit = 1;
		return ;
	}
	if (!cmd->next && is_builtin(cmd->args))
	{
		fd[0] = dup(STDIN_FILENO);
		fd[1] = dup(STDOUT_FILENO);
		handle_io(cmd, -1, NULL);
		sh->last_exit = exe_builtin(cmd->args, sh);
		dup2(fd[0], STDIN_FILENO);
		dup2(fd[1], STDOUT_FILENO);
		close(fd[0]);
		close(fd[1]);
		return ;
	}
	fork_commands(cmd, sh);
}
