/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkyaw <lkyaw@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/05 16:10:57 by lkyaw             #+#    #+#             */
/*   Updated: 2025/09/05 17:01:46 by lkyaw            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <stdio.h>
#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*ptr;
	t_list	*next;

	if (!lst || !del)
		return ;
	ptr = *lst;
	while (ptr)
	{
		next = ptr->next;
		del(ptr->content);
		free(ptr);
		ptr = next;
	}
	*lst = NULL;
}
/*
void    del_content(void *content)
{
    free(content);
}
int main(void)
{
    // Create 3 nodes with strdup strings
    t_list *n1 = ft_lstnew(ft_strdup("Hello"));
    t_list *n2 = ft_lstnew(ft_strdup("World"));
    t_list *n3 = ft_lstnew(ft_strdup("!"));
    // Link them into a list
    n1->next = n2;
    n2->next = n3;
    // Our list head
    t_list *head = n1;
    // Print before clearing
    printf("Before clear:\n");
    t_list *tmp = head;
    while (tmp)
    {
        printf("%s\n", (char *)tmp->content);
        tmp = tmp->next;
    }
    // Clear the list
    ft_lstclear(&head, del_content);
    // After clear, head should be NULL
    if (head == NULL)
        printf("List cleared successfully!\n");
    else
        printf("Clear failed, head not NULL\n");

    return (0);
}*/
