/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkyaw <lkyaw@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/09 19:12:33 by lkyaw             #+#    #+#             */
/*   Updated: 2025/09/09 19:12:45 by lkyaw            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include "ft_printf.h"

int	main(void)
{
	int	i;

	i = printf("cspdikuxX%  ");
	printf("\n");
	printf("%i", i);
	printf("\n");
	i = ft_printf("cspdkiuxX%  ");
	printf("\n");
	printf("%i", i);
}
