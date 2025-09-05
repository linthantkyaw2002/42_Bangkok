/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkyaw <lkyaw@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/05 13:41:37 by lkyaw             #+#    #+#             */
/*   Updated: 2025/09/05 14:09:08 by lkyaw            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <stdio.h>
#include "libft.h"

int	ft_lstsize(t_list *lst)
{
	int	i;

	i = 0;
	while (lst)
	{
		i++;
		lst = lst->next;
	}
	return (i);
}
/*
int	main(void)
{
	t_list	*head = NULL;

	t_list	*node1 = ft_lstnew("nodeA");
	t_list	*node2 = ft_lstnew("nodeB");
	t_list	*node3 = ft_lstnew("nodeC");

	ft_lstadd_front(&head, node1);
	ft_lstadd_front(&head, node2);
	ft_lstadd_front(&head, node3);

	printf("%d\n", ft_lstsize(head));
	t_list *temp;
    while (head)
    {
        temp = head->next;
        free(head);
        head = temp;
    }
	return (0);
}*/
