/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_numeric.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkyaw <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/14 13:59:35 by lkyaw             #+#    #+#             */
/*   Updated: 2025/07/14 14:10:04 by lkyaw            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <unistd.h>

int	ft_str_is_numeric(char *str)
{
	int		i;
	char	j;

	i = 0;
	while (str[i])
	{
		j = '0';
		while (str[i] != j && j <= '9')
		{
			j++;
		}
		if (j > '9')
			return (0);
		i++;
	}
	return (1);
}
/*
int	main(void)
{
	char *str = "1234568";
	char *str1 = "Hello*";
	char *str2 = "********";

	char i;
	char j;
	char k;

	i = ft_str_is_numeric(str) + '0';
	j = ft_str_is_numeric(str1) + '0';
	k = ft_str_is_numeric(str2) + '0';
	write(1, &i, 1);
	write(1, "\n", 1);
	write(1, &j, 1);
	write(1, "\n", 1);
	write(1, &k,1);

	return (0);
}*/
