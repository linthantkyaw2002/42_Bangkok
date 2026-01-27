/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkyaw <lkyaw@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/05 14:12:49 by lkyaw             #+#    #+#             */
/*   Updated: 2025/09/05 16:03:33 by lkyaw            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <stdio.h>
#include "libft.h"

t_list	*ft_lstlast(t_list *lst)
{
	t_list	*ptr;

	if (!lst)
		return (NULL);
	ptr = lst;
	while (ptr->next)
	{
		ptr = ptr->next;
	}
	return (ptr);
}
/*
void free_list(t_list *head)
{
    t_list *temp;

    while (head)
    {
        temp = head->next;
        free(head->content);  // only if content is dynamically allocated
        free(head);
        head = temp;
    }
}

int	main(void)
{
	t_list	*head = NULL;
	t_list	*last = NULL;

	t_list	*node1 = ft_lstnew("nodeA");
	t_list	*node2 = ft_lstnew("nodeB");
	t_list	*node3 = ft_lstnew("nodeC");

	ft_lstadd_front(&head, node1);
	ft_lstadd_front(&head, node2);
	ft_lstadd_front(&head, node3);

	last = ft_lstlast(head);
	printf("%s\n", (char *)(last->content));
	
	free(head);
	return (0);
}*/
