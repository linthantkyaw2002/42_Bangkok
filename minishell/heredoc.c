#include "minishell.h"

static char	*expand_heredoc_line(char *line, t_shell *shell)
{
	char	*res;
	char	*var;
	char	*val;
	int		i;

	res = ft_strdup("");
	i = 0;
	while (line[i])
	{
		if (line[i] == '$' && line[i + 1] && (ft_isalnum(line[i + 1]) || line[i
				+ 1] == '_' || line[i + 1] == '?'))
		{
			i++;
			if (line[i] == '?')
			{
				val = ft_itoa(shell->last_exit);
				res = append_str(res, val);
				free(val);
				i++;
			}
			else
			{
				var = get_var_name(line, &i);
				val = get_env_value(var, shell->env);
				free(var);
				if (val)
					res = append_str(res, val);
			}
		}
		else
			res = append_char(res, line[i++]);
	}
	return (res);
}

static void	heredoc_child(char *delimiter, t_shell *shell, int fd)
{
	char	*line;
	char	*expanded;

	signal(SIGINT, SIG_DFL);
	while (1)
	{
		line = readline("> ");
		if (!line || ft_strcmp(line, delimiter) == 0)
		{
			free(line);
			break ;
		}
		expanded = expand_heredoc_line(line, shell);
		ft_putendl_fd(expanded, fd);
		free(expanded);
		free(line);
	}
	close(fd);
	exit(0);
}

int	read_heredoc(char *delimiter, t_shell *shell)
{
	int fd;
	pid_t pid;
	int status;

	fd = open(".heredoc_tmp", O_CREAT | O_WRONLY | O_TRUNC, 0644);
	if (fd < 0)
		return (perror("minishell: heredoc"), -1);
	signal(SIGINT, SIG_IGN);
	pid = fork();
	if (pid == 0)
		heredoc_child(delimiter, shell, fd);
	waitpid(pid, &status, 0);
	setup_signals();
	close(fd);
	if (WIFSIGNALED(status) && WTERMSIG(status) == SIGINT)
	{
		shell->last_exit = 130;
		write(STDOUT_FILENO, "\n", 1);
		g_signal_received = SIGINT;
		return (-1);
	}
	return (open(".heredoc_tmp", O_RDONLY));
}