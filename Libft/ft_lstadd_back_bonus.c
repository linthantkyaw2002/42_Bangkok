/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkyaw <lkyaw@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/05 14:40:05 by lkyaw             #+#    #+#             */
/*   Updated: 2025/09/05 16:10:03 by lkyaw            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <stdio.h>
#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*ptr;

	if (!lst || !new)
		return ;
	if (*lst == NULL)
	{
		*lst = new;
		new->next = NULL;
		return ;
	}
	ptr = *lst;
	while (ptr->next != NULL)
		ptr = ptr->next;
	ptr->next = new;
}
/*
void print_list(t_list *head)
{
    while (head)
    {
        printf("%s -> ", (char *)head->content);
        head = head->next;
    }
    printf("NULL\n");
}
int	main(void)
{
	t_list	*head = NULL;

	t_list	*node1 = ft_lstnew("nodeA");
	t_list	*node2 = ft_lstnew("nodeB");
	t_list	*node3 = ft_lstnew("nodeC");

	ft_lstadd_front(&head, node1);
	print_list(head);
	ft_lstadd_back(&head, node2);
	print_list(head);
	ft_lstadd_back(&head, node3);
	print_list(head);

	t_list *temp;
    while (head)
    {
        temp = head->next;
        free(head);
        head = temp;
    }
	return (0);
}*/
