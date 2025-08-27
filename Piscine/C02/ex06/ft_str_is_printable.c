/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_printable.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkyaw <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/14 14:39:58 by lkyaw             #+#    #+#             */
/*   Updated: 2025/07/14 15:14:17 by lkyaw            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <unistd.h>

int	ft_str_is_printable(char *str)
{
	int		i;
	char	j;

	i = 0;
	while (str[i])
	{
		j = 32;
		while (str[i] != j && j <= 126)
		{
			j++;
		}
		if (j > 126)
			return (0);
		i++;
	}
	return (1);
}
/*
int	main(void)
{
	char *str = "KJFKDJDK";
	char *str1 = "Hello\n*";
	char *str2 = "********";
	char *str3 = "";

	char i;
	char j;
	char k;
	char l;

	i = ft_str_is_printable(str) + '0';
	j = ft_str_is_printable(str1) + '0';
	k = ft_str_is_printable(str2) + '0';
	l = ft_str_is_printable(str3) + '0';
	write(1, &i, 1);
	write(1, "\n", 1);
	write(1, &j, 1);
	write(1, "\n", 1);
	write(1, &k, 1);
	write(1, "\n", 1);
	write(1, &l, 1);

	return (0);
}*/
