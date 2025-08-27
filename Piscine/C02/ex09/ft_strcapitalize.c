/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcapitalize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkyaw <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/14 16:24:27 by lkyaw             #+#    #+#             */
/*   Updated: 2025/07/15 14:51:59 by lkyaw            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <unistd.h>
/*
void	print(char *str)
{
	int i;

	i = 0;
	while (str[i])
		i++;
	write(1, str, i);
}
*/
int	is_lower(char c)
{
	return (c >= 'a' && c <= 'z');
}

int	is_upper(char c)
{
	return (c >= 'A' && c <= 'Z');
}

int	is_alpha(char c)
{
	return ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'));
}

int	is_num(char c)
{
	return (c >= '0' && c <= '9');
}

char	*ft_strcapitalize(char *str)
{
	int	i;
	int	is_aorn;

	i = 0;
	while (str[i])
	{
		if (i == 0 && is_lower(str[i]))
			str[i] = str[i] - 32;
		else if (i > 0)
		{
			is_aorn = is_alpha(str[i -1]) || is_num(str[i -1]);
			if (is_lower(str[i]) && !is_aorn)
				str[i] = str[i] - 32;
			else if (is_aorn && is_upper(str[i]))
				str[i] = str[i] + 32;
		}
		i++;
	}
	return (str);
}
/*
int	main(void)
{
	char str[]="hi, how are you? 42words forty-two; fifty+and+one";
	ft_strcapitalize(str);
	print(str);
	return (0);
}*/
