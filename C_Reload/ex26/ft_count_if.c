/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_count_if.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkyaw <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/26 19:43:21 by lkyaw             #+#    #+#             */
/*   Updated: 2025/08/26 20:01:35 by lkyaw            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <stdio.h>
/*
int	has_a(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if(str[i] == 'a')
			return (1);
		i++;
	}
	return (0);
}
*/
int	ft_count_if(char **tab, int (*f)(char*))
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (tab[i])
	{
		if (f(tab[i]))
			count++;
		i++;
	}
	return (count);
}
/*
int	main(void)
{
	char	*str[]={"hello", "world", "age", "aye", "hi", "aaa", NULL};

	printf("%i\n", ft_count_if(str, &has_a));
}*/
