/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkyaw <lkyaw@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/02 03:41:21 by lkyaw             #+#    #+#             */
/*   Updated: 2026/02/02 03:41:21 by lkyaw            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <sys/wait.h>
# include <stdio.h>
# include <string.h>
# include <errno.h>
# include "get_next_line/get_next_line.h"

/* Utils */
size_t	ft_strlen(const char *s);
int		ft_strncmp(const char *a, const char *b, size_t n);
char	**ft_split(char const *s, char c);
char	*ft_strjoin(char const *s1, char const *s2);
void	free_tab(char **tab);
void	error_exit(char *msg);

/* Core Logic */
char	*find_path(char *cmd, char **envp);
void	exec_cmd(char *cmd, char **envp);
int		here_doc(char *limiter);

#endif