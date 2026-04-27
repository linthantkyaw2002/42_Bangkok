#include "minishell.h"

static void	handle_out(t_cmd *cmd, t_token *op, t_token *file)
{
	if (cmd->outfile >= 0)
		close(cmd->outfile);
	if (op->type == TOKEN_REDIRECT_OUT)
		cmd->outfile = open(file->value, O_CREAT | O_WRONLY | O_TRUNC, 0644);
	else
		cmd->outfile = open(file->value, O_CREAT | O_WRONLY | O_APPEND, 0644);
	if (cmd->outfile == -1)
		perror(file->value);
}

static void	handle_in(t_cmd *cmd, t_token *op, t_token *file, t_shell *shell)
{
	if (cmd->infile >= 0)
		close(cmd->infile);
	if (op->type == TOKEN_REDIRECT_IN)
	{
		cmd->infile = open(file->value, O_RDONLY);
		if (cmd->infile == -1)
			perror(file->value);
	}
	else if (op->type == TOKEN_HEREDOC)
		cmd->infile = read_heredoc(file->value, shell);
}

void	handle_redirection(t_cmd *cmd, t_token **tokens, t_shell *shell)
{
	t_token	*op;
	t_token	*file;

	op = *tokens;
	if (!op || !op->next)
		return ;
	file = op->next;
	if (op->type == TOKEN_REDIRECT_OUT || op->type == TOKEN_APPEND)
		handle_out(cmd, op, file);
	else if (op->type == TOKEN_REDIRECT_IN || op->type == TOKEN_HEREDOC)
		handle_in(cmd, op, file, shell);
	*tokens = file;
}
