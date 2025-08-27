/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_lowercase.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkyaw <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/14 14:15:50 by lkyaw             #+#    #+#             */
/*   Updated: 2025/07/14 14:18:26 by lkyaw            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <unistd.h>

int	ft_str_is_lowercase(char *str)
{
	int		i;
	char	j;

	i = 0;
	while (str[i])
	{
		j = 'a';
		while (str[i] != j && j <= 'z')
		{
			j++;
		}
		if (j > 'z')
			return (0);
		i++;
	}
	return (1);
}
/*
int	main(void)
{
	char *str = "avjvdje";
	char *str1 = "Hello*";
	char *str2 = "********";

	char i;
	char j;
	char k;

	i = ft_str_is_lowercase(str) + '0';
	j = ft_str_is_lowercase(str1) + '0';
	k = ft_str_is_lowercase(str2) + '0';
	write(1, &i, 1);
	write(1, "\n", 1);
	write(1, &j, 1);
	write(1, "\n", 1);
	write(1, &k,1);

	return (0);
}*/
