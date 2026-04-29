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
	char	**real_args;
	int		i;

	signal(SIGINT, SIG_DFL);
	signal(SIGQUIT, SIG_DFL);
	handle_io(cmd, prev_fd, p_fd);
	if (!cmd->args || !cmd->args[0])
		exit(0);
	i = 0;
	while (cmd->args[i] && cmd->args[i][0] == '\0')
		i++;
	if (!cmd->args[i])
		exit(0);
	real_args = &cmd->args[i];
	if (is_builtin(real_args))
		exit(exe_builtin(real_args, sh));
	path = get_cmd_path(real_args[0], sh->env);
	if (path)
		execve(path, real_args, env_to_array(sh->env));
	handle_exec_error(path, real_args[0]);
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
		if (cmd->error == 0)
		{
			pid = fork();
			if (pid == 0)
				run_child(cmd, sh, prev_fd, p_fd);
		}
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

void	execute_commands(t_cmd *cmd_list, t_shell *sh)
{
	int		saved_stdin;
	int		saved_stdout;
	t_cmd	*last;

	if (!cmd_list)
		return ;
	if (!cmd_list->next && cmd_list->error == 1)
	{
		sh->last_exit = 1;
		return ;
	}
	if (!cmd_list->next && cmd_list->args && is_builtin(cmd_list->args))
	{
		saved_stdin = dup(STDIN_FILENO);
		saved_stdout = dup(STDOUT_FILENO);
		handle_io(cmd_list, -1, NULL);
		sh->last_exit = exe_builtin(cmd_list->args, sh);
		dup2(saved_stdin, STDIN_FILENO);
		dup2(saved_stdout, STDOUT_FILENO);
		close(saved_stdin);
		close(saved_stdout);
		return ;
	}
	fork_commands(cmd_list, sh);
	last = cmd_list;
	while (last->next)
		last = last->next;
	if (last->error == 1)
		sh->last_exit = 1;
}
