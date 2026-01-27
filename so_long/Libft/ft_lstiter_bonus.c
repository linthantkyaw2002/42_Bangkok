/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkyaw <lkyaw@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/05 17:04:22 by lkyaw             #+#    #+#             */
/*   Updated: 2025/09/05 17:10:16 by lkyaw            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <stdio.h>
#include "libft.h"

void	ft_lstiter(t_list *lst, void (*f)(void *))
{
	t_list	*ptr;

	if (!lst || !f)
		return ;
	ptr = lst;
	while (ptr)
	{
		f(ptr->content);
		ptr = ptr->next;
	}
}
/*
void print_content(void *content)
{
    printf("%s\n", (char *)content);
}
int main(void)
{
    // Create 3 nodes
    t_list *n1 = ft_lstnew(ft_strdup("hello"));
    t_list *n2 = ft_lstnew(ft_strdup("world"));
    t_list *n3 = ft_lstnew(ft_strdup("libft"));
    //Link them
    n1->next = n2;
    n2->next = n3;
    t_list *head = n1;
    // Use ft_lstiter to print all nodes
    ft_lstiter(head, print_content);
    // Free all nodes
    t_list *tmp;
    while (head)
    {
        tmp = head->next;
        free(head->content);
        free(head);
        head = tmp;
    }

    return 0;
}*/
