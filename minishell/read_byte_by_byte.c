#include "minishell.h"

char	*read_byte_by_byte(void)
{
	char	c;
	char	*line;
	int		read_bytes;

	line = ft_strdup("");
	if (!line)
		return (NULL);
	while (1)
	{
		read_bytes = read(STDIN_FILENO, &c, 1);
		if (read_bytes <= 0)
			break ;
		line = append_char(line, c);
		if (c == '\n')
			break ;
	}
	if (read_bytes <= 0 && (!line || !*line))
	{
		free(line);
		return (NULL);
	}
	return (line);
}
