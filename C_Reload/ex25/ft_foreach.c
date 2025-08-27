/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_foreach.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkyaw <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/26 19:33:45 by lkyaw             #+#    #+#             */
/*   Updated: 2025/08/26 19:40:32 by lkyaw            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <unistd.h>
/*
void	ft_putnbr(int nb)
{
	long	n;
	int		i;
	char	nums[10];

	n = nb;
	if (n == 0)
	{
		write(1, "0", 1);
		return ;
	}
	if (n < 0)
	{
		write(1, "-", 1);
		n = -n;
	}
	i = 0;
	while (n > 0)
	{
		nums[i++] = (n % 10) + '0';
		n = n / 10;
	}
	while (--i >= 0)
	{
		write(1, &nums[i], 1);
	}
	write(1, "\n", 1);
}
*/
void	ft_foreach(int *tab, int length, void (*f)(int))
{
	int	i;

	i = 0;
	while (i < length)
	{
		f(tab[i]);
		i++;
	}
}
/*
int	main(void)
{
	int	arr[5] = {1, 22, 33, 44, 55};

	ft_foreach( arr, 5, &ft_putnbr);
}*/
