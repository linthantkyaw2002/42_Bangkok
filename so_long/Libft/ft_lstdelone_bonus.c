/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkyaw <lkyaw@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/05 15:40:58 by lkyaw             #+#    #+#             */
/*   Updated: 2025/09/05 16:09:47 by lkyaw            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <stdio.h>
#include "libft.h"

void	ft_lstdelone(t_list *lst, void (*del)(void *))
{
	if (!lst || !del)
		return ;
	del(lst->content);
	free(lst);
}
/*
void    del_content(void *content)
{
    free(content);
}
int main(void)
{
    t_list *node = ft_lstnew(ft_strdup("Hello, World!"));
    if (!node)
    {
        printf("Node creation failed\n");
        return (1);
    }

    printf("Before deletion: %s\n", (char *)node->content);

    ft_lstdelone(node, del_content);
	
	printf("Node deleted successfully\n");
    return (0);
}*/
