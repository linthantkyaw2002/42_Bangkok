/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_power.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkyaw <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/20 11:44:52 by lkyaw             #+#    #+#             */
/*   Updated: 2025/07/20 12:37:24 by lkyaw            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <stdio.h>

int	ft_iterative_power(int nb, int power)
{
	int	r;

	if (power < 0)
		return (0);
	r = 1;
	while (power > 0)
	{
		r *= nb;
		power--;
	}
	return (r);
}
/*
int	main(void)
{
	int	i = 5;
	int	j = 0;
	printf("%d\n", ft_iterative_power(i, j));
}*/
