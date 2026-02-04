/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkyaw <lkyaw@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/02 03:14:59 by lkyaw             #+#    #+#             */
/*   Updated: 2026/02/02 03:14:59 by lkyaw            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static void	child_process(char *cmd, char **envp)
{
	int		fd[2];
	pid_t	pid;

	if (pipe(fd) == -1)
		error_exit("pipe");
	pid = fork();
	if (pid == -1)
		error_exit("fork");
	if (pid == 0)
	{
		close(fd[0]);
		if (dup2(fd[1], STDOUT_FILENO) == -1)
			error_exit("dup2");
		close(fd[1]);
		exec_cmd(cmd, envp);
	}
	else
	{
		close(fd[1]);
		if (dup2(fd[0], STDIN_FILENO) == -1)
			error_exit("dup2");
		close(fd[0]);
	}
}

static void	init_heredoc(char **av, int ac, int *i, int *outfile)
{
	int	hdoc_fd;

	*i = 3;
	*outfile = open(av[ac - 1], O_WRONLY | O_CREAT | O_APPEND, 0644);
	hdoc_fd = here_doc(av[2]);
	dup2(hdoc_fd, STDIN_FILENO);
	close(hdoc_fd);
}

static void	handle_files(int ac, char **av, int *i, int *outfile)
{
	int	infile;

	if (ft_strncmp(av[1], "here_doc", 8) == 0)
		init_heredoc(av, ac, i, outfile);
	else
	{
		*i = 2;
		infile = open(av[1], O_RDONLY);
		if (infile < 0)
		{
			perror(av[1]);
			infile = open("/dev/null", O_RDONLY);
		}
		if (infile >= 0)
		{
			dup2(infile, STDIN_FILENO);
			close(infile);
		}
		*outfile = open(av[ac - 1], O_WRONLY | O_CREAT | O_TRUNC, 0644);
	}
	if (*outfile < 0)
		perror(av[ac - 1]);
}

static void	last_process(char *cmd, char **envp, int outfile)
{
	if (outfile < 0)
		exit(1);
	if (outfile >= 0)
	{
		dup2(outfile, STDOUT_FILENO);
		close(outfile);
	}
	exec_cmd(cmd, envp);
}

int	main(int ac, char **av, char **envp)
{
	int		i;
	int		outfile;
	pid_t	last_pid;
	int		status;

	if (ac < 5)
		return (1);
	handle_files(ac, av, &i, &outfile);
	while (i < ac - 2)
		child_process(av[i++], envp);
	last_pid = fork();
	if (last_pid == -1)
		error_exit("fork");
	if (last_pid == 0)
		last_process(av[ac - 2], envp, outfile);
	if (outfile >= 0)
		close(outfile);
	close(STDIN_FILENO);
	waitpid(last_pid, &status, 0);
	while (wait(NULL) > 0)
		;
	if (WIFEXITED(status))
		return (WEXITSTATUS(status));
	return (WIFSIGNALED(status) * (128 + WTERMSIG(status))
		+ !WIFSIGNALED(status));
}
