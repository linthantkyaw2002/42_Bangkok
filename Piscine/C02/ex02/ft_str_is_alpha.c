/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_alpha.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkyaw <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/14 12:46:29 by lkyaw             #+#    #+#             */
/*   Updated: 2025/07/14 14:00:07 by lkyaw            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <unistd.h>

int	ft_str_is_alpha(char *str)
{
	int		i;
	char	j;
	char	k;

	i = 0;
	while (str[i])
	{
		j = 'a';
		k = 'A';
		while ((str[i] != j && str[i] != k) && (j <= 'z' || k <= 'Z'))
		{
			j++;
			k++;
		}
		if (j > 'z' && k > 'Z')
			return (0);
		i++;
	}
	return (1);
}
/*
int	main(void)
{
	char *str = "Hello";
	char *str1 = "Hello*";
	char *str2 = "********";

	char i;
	char j;
	char k;

	i = ft_str_is_alpha(str) + '0';
	j = ft_str_is_alpha(str1) + '0';
	k = ft_str_is_alpha(str2) + '0';
	write(1, &i, 1);
	write(1, "\n", 1);
	write(1, &j, 1);
	write(1, "\n", 1);
	write(1, &k,1);

	return (0);
}*/	
