/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkyaw <lkyaw@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/02 03:11:14 by lkyaw             #+#    #+#             */
/*   Updated: 2026/02/02 03:11:14 by lkyaw            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	here_doc(char *limiter)
{
	int		fd[2];
	char	*line;
	char	*tmp;

	if (pipe(fd) == -1)
		error_exit("pipe");
	tmp = ft_strjoin(limiter, "\n");
	while (1)
	{
		write(1, "heredoc> ", 9);
		line = get_next_line(0);
		if (!line || (ft_strncmp(line, tmp, ft_strlen(tmp)) == 0
				&& ft_strlen(line) == ft_strlen(tmp)))
			break ;
		write(fd[1], line, ft_strlen(line));
		free(line);
	}
	free(line);
	free(tmp);
	get_next_line(-1);
	return (close(fd[1]), fd[0]);
}

void	error_exit(char *msg)
{
	perror(msg);
	exit(1);
}
