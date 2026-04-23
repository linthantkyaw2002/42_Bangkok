/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkyaw <lkyaw@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/02 03:42:52 by lkyaw             #+#    #+#             */
/*   Updated: 2026/02/02 03:42:58 by lkyaw            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_extract_line(char **leftover)
{
	char	*line;
	char	*new_leftover;
	int		index;

	if (!(*leftover) || !(**leftover))
	{
		free(*leftover);
		return (*leftover = NULL);
	}
	index = ft_strchr_index(*leftover, '\n');
	if (index >= 0)
	{
		line = ft_substr(*leftover, 0, index + 1);
		new_leftover = ft_substr(*leftover, index + 1, ft_strlen(*leftover));
		if (new_leftover && *new_leftover == '\0')
		{
			free(new_leftover);
			new_leftover = NULL;
		}
	}
	else
		line = ft_strdup(*leftover);
	if (index < 0)
		new_leftover = NULL;
	return (free(*leftover), *leftover = new_leftover, line);
}

int	leftover_join(char **leftover, char *buffer)
{
	char	*joined;

	joined = ft_gnljoin(*leftover, buffer);
	if (!joined)
	{
		free(*leftover);
		*leftover = NULL;
		return (0);
	}
	*leftover = joined;
	return (1);
}

char	*read_into_leftover(int fd, char *leftover)
{
	char	*buffer;
	ssize_t	bytes;

	buffer = malloc(BUFFER_SIZE + 1);
	if (!buffer)
		return (free(leftover), NULL);
	while (ft_strchr_index(leftover, '\n') < 0)
	{
		bytes = read(fd, buffer, BUFFER_SIZE);
		if (bytes <= 0)
		{
			if (bytes < 0)
			{
				free(leftover);
				leftover = NULL;
			}
			break ;
		}
		buffer[bytes] = '\0';
		if (!leftover_join(&leftover, buffer))
			return (free(buffer), NULL);
	}
	return (free(buffer), leftover);
}

char	*get_next_line(int fd)
{
	static char	*leftover;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
	{
		if (fd == -1 && leftover)
		{
			free(leftover);
			leftover = NULL;
		}
		return (NULL);
	}
	leftover = read_into_leftover(fd, leftover);
	if (!leftover)
		return (NULL);
	line = ft_extract_line(&leftover);
	return (line);
}
