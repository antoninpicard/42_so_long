/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anpicard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 16:40:06 by anpicard          #+#    #+#             */
/*   Updated: 2024/11/12 13:52:15 by anpicard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdelone(t_list *lst, void (*del)(void *))
{
	if (!lst || !del)
		return ;
	del(lst->content);
	free(lst);
}
// #include <stdio.h>
// #include <stdlib.h>

// t_list *ft_lstnew(void *content)
// {
// 	t_list *new = (t_list *)malloc(sizeof(t_list));
// 	if (!new)
// 		return (NULL);
// 	new->content = content;
// 	new->next = NULL;
// 	return (new);
// }

// void del(void *content)
// {
// 	free(content);
// }

// int main()
// {
// 	t_list *node = ft_lstnew(strdup("Hello, World!"));

// 	if (!node)
// 	{
// 		printf("Memory allocation failed\n");
// 		return 1;
// 	}

// 	printf("Before deleting: %s\n", (char *)node->content);

// 	ft_lstdelone(node, del);

// 	printf("After deleting: node content freed and node deleted\n");

// 	return 0;
// }
