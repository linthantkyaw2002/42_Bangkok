/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkyaw <lkyaw@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/28 13:57:44 by lkyaw             #+#    #+#             */
/*   Updated: 2025/09/28 14:30:07 by lkyaw            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*ft_extract_line(char **leftover)
{
	char	*line;
	char	*new_leftover;
	int		index;

	if (!(*leftover) || !(**leftover))
		return (NULL);
	index = ft_strchr_index(*leftover, '\n');
	if (index >= 0)
	{
		line = ft_substr(*leftover, 0, index + 1);
		new_leftover = ft_substr(*leftover, index + 1, ft_strlen(*leftover)
				- index - 1);
	}
	else
	{
		line = ft_substr(*leftover, 0, ft_strlen(*leftover));
		new_leftover = NULL;
	}
	free(*leftover);
	*leftover = new_leftover;
	return (line);
}

int	leftover_join(char **leftover, char *buffer)
{
	*leftover = ft_strjoin(*leftover, buffer);
	if (!*leftover)
	{
		free(buffer);
		return (0);
	}
	return (1);
}

char	*read_into_leftover(int fd, char *leftover)
{
	char	*buffer;
	ssize_t	bytes_read;

	buffer = malloc(BUFFER_SIZE + 1);
	if (!buffer)
		return (NULL);
	while (ft_strchr_index(leftover, '\n') < 0)
	{
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		if (bytes_read < 0)
		{
			free(buffer);
			return (NULL);
		}
		if (bytes_read == 0)
			break ;
		buffer[bytes_read] = '\0';
		if (!leftover_join(&leftover, buffer))
			return (NULL);
	}
	free(buffer);
	return (leftover);
}

char	*get_next_line(int fd)
{
	static char	*leftover[MAX_FD];
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	leftover[fd] = read_into_leftover(fd, leftover[fd]);
	if (!leftover[fd])
		return (NULL);
	line = ft_extract_line(&leftover[fd]);
	return (line);
}
