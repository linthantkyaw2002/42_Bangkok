/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_redirection.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkyaw <lkyaw@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/29 21:24:01 by lkyaw             #+#    #+#             */
/*   Updated: 2026/04/29 21:24:01 by lkyaw            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/* ************************************************************************** */
/* */
/* :::      ::::::::   */
/* handle_redirection.c                               :+:      :+:    :+:   */
/* +:+ +:+         +:+     */
/* By: lkyaw <lkyaw@student.42.fr>                +#+  +:+       +#+        */
/* +#+#+#+#+#+   +#+           */
/* Created: 2026/04/29 21:24:01 by lkyaw             #+#    #+#             */
/* Updated: 2026/04/30 22:45:00 by lkyaw            ###   ########.fr       */
/* */
/* ************************************************************************** */

#include "minishell.h"

static void	handle_file(t_cmd *cmd, t_token *op, char *file)
{
	if (op->type == TOKEN_REDIRECT_IN)
	{
		if (cmd->infile >= 0)
			close(cmd->infile);
		cmd->infile = open(file, O_RDONLY);
		if (cmd->infile == -1)
			cmd->error = 1;
	}
	else
	{
		if (cmd->outfile >= 0)
			close(cmd->outfile);
		if (op->type == TOKEN_REDIRECT_OUT)
			cmd->outfile = open(file, O_CREAT | O_WRONLY | O_TRUNC, 0644);
		else
			cmd->outfile = open(file, O_CREAT | O_WRONLY | O_APPEND, 0644);
		if (cmd->outfile == -1)
			cmd->error = 1;
	}
	if (cmd->error)
		perror(file);
}

static void	dispatch_redir(t_cmd *cmd, t_token *op, char *clean, t_shell *sh)
{
	if (op->type == TOKEN_HEREDOC)
	{
		cmd->infile = read_heredoc(clean, sh, has_quotes(op->next->value));
		if (cmd->infile == -1 && g_signal_received == SIGINT)
			cmd->error = 1;
	}
	else
		handle_file(cmd, op, clean);
}

void	handle_redirection(t_cmd *cmd, t_token **tokens, t_shell *shell)
{
	t_token	*op;
	char	*clean;

	op = *tokens;
	if (!op || !op->next)
		return ;
	if (op->next->type == TOKEN_AMBIGUOUS)
	{
		ft_putstr_fd("minishell: ", 2);
		ft_putstr_fd(op->next->value, 2);
		ft_putendl_fd(": ambiguous redirect", 2);
		cmd->error = 1;
	}
	clean = strip_quotes(op->next->value);
	if (!cmd->error)
		dispatch_redir(cmd, op, clean, shell);
	free(clean);
	*tokens = op->next;
}

static void	print_error_exit(char *cmd, char *msg, int code)
{
	ft_putstr_fd("minishell: ", 2);
	ft_putstr_fd(cmd, 2);
	ft_putstr_fd(": ", 2);
	ft_putendl_fd(msg, 2);
	exit(code);
}

void	handle_exec_error(char *path, char *cmd_name)
{
	struct stat	path_stat;

	if (!path)
		print_error_exit(cmd_name, "command not found", 127);
	if (ft_strchr(cmd_name, '/') && access(path, F_OK) != 0)
		print_error_exit(cmd_name, "No such file or directory", 127);
	stat(path, &path_stat);
	if (S_ISDIR(path_stat.st_mode))
		print_error_exit(cmd_name, "Is a directory", 126);
	if (access(path, X_OK) != 0)
		print_error_exit(cmd_name, "Permission denied", 126);
	if (errno == ENOEXEC)
	{
		if (ft_strchr(cmd_name, '/'))
			exit(0);
		print_error_exit(cmd_name, "No such file or directory", 2);
	}
	if (errno == ENOENT)
		print_error_exit(cmd_name, "No such file or directory", 127);
	print_error_exit(cmd_name, "command not found", 127);
}
