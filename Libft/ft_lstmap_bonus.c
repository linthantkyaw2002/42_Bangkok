/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkyaw <lkyaw@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/05 17:12:05 by lkyaw             #+#    #+#             */
/*   Updated: 2025/09/05 17:23:44 by lkyaw            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <stdio.h>
#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new_lst;
	t_list	*new_node;

	if (!lst || !f || !del)
		return (NULL);
	new_lst = NULL;
	while (lst)
	{
		new_node = ft_lstnew(f(lst->content));
		if (!new_node)
		{
			ft_lstclear(&new_lst, del);
			return (NULL);
		}
		ft_lstadd_back(&new_lst, new_node);
		lst = lst->next;
	}
	return (new_lst);
}
/*
void *uppercase(void *content)
{
    char *str = ft_strdup((char *)content); // duplicate string
    if (!str) return NULL;

    for (int i = 0; str[i]; i++)
        if (str[i] >= 'a' && str[i] <= 'z')
            str[i] -= 32;
    return str;
}
// Delete function: free content
void del_content(void *content)
{
    free(content);
}
int main(void)
{
    // Create a simple list
    t_list *head = ft_lstnew(ft_strdup("hello"));
    head->next = ft_lstnew(ft_strdup("world"));
    // Map to uppercase
    t_list *new_head = ft_lstmap(head, uppercase, del_content);
    // Print new list
    for (t_list *tmp = new_head; tmp; tmp = tmp->next)
        printf("%s\n", (char *)tmp->content);
    // Free lists
    ft_lstclear(&head, del_content);
    ft_lstclear(&new_head, del_content);

    return 0;
}*/
