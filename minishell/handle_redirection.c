#include "minishell.h"

static void handle_out(t_cmd *cmd, t_token *op, t_token *file)
{
	if (cmd->outfile >= 0)
		close(cmd->outfile);
	if (op->type == TOKEN_REDIRECT_OUT)
		cmd->outfile = open(file->value, O_CREAT | O_WRONLY | O_TRUNC, 0644);
	else
		cmd->outfile = open(file->value, O_CREAT | O_WRONLY | O_APPEND, 0644);
	if (cmd->outfile == -1)
	{
		perror(file->value);
		cmd->error = 1;
	}
}

static void handle_in(t_cmd *cmd, t_token *op, t_token *file, t_shell *shell)
{
	if (cmd->infile >= 0)
		close(cmd->infile);
	if (op->type == TOKEN_REDIRECT_IN)
	{
		cmd->infile = open(file->value, O_RDONLY);
		if (cmd->infile == -1)
		{
			perror(file->value);
			cmd->error = 1;
		}
	}
	else if (op->type == TOKEN_HEREDOC)
	{
		cmd->infile = read_heredoc(file->value, shell);
		if (cmd->infile == -1 && g_signal_received == SIGINT)
			cmd->error = 1;
	}
}

void handle_redirection(t_cmd *cmd, t_token **tokens, t_shell *shell)
{
	t_token *op;
	t_token *file;

	op = *tokens;
	if (!op || !op->next)
		return;
	file = op->next;

	if (!cmd->error)
	{
		if (op->type == TOKEN_REDIRECT_OUT || op->type == TOKEN_APPEND)
			handle_out(cmd, op, file);
		else if (op->type == TOKEN_REDIRECT_IN || op->type == TOKEN_HEREDOC)
			handle_in(cmd, op, file, shell);
	}
	*tokens = file;
}

void	handle_exec_error(char *path, char *cmd_name)
{
	struct stat	path_stat;

	if (!path)
	{
		ft_putstr_fd("minishell: ", 2);
		ft_putstr_fd(cmd_name, 2);
		ft_putendl_fd(": command not found", 2);
		exit(127);
	}
	stat(path, &path_stat);
	if (S_ISDIR(path_stat.st_mode))
	{
		ft_putstr_fd("minishell: ", 2);
		ft_putstr_fd(cmd_name, 2);
		ft_putendl_fd(": Is a directory", 2);
		exit(126);
	}
	else if (errno == EACCES)
	{
		ft_putstr_fd("minishell: ", 2);
		ft_putstr_fd(cmd_name, 2);
		ft_putendl_fd(": Permission denied", 2);
		exit(126);
	}
	perror("minishell: execve");
	exit(127);
}
