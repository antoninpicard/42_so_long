/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anpicard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 15:24:50 by anpicard          #+#    #+#             */
/*   Updated: 2024/11/12 14:02:54 by anpicard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*new;

	new = (t_list *) malloc(sizeof(t_list));
	if (!new)
		return (NULL);
	new->content = content;
	new->next = NULL;
	return (new);
}
// #include <stdio.h>
// #include <stdlib.h>

// void print_list(t_list *lst)
// {
// 	while (lst)
// 	{
// 		printf("%s -> ", (char *)lst->content);
// 		lst = lst->next;
// 	}
// 	printf("NULL\n");
// }

// int main()
// {
// 	t_list *node1 = ft_lstnew("Hello");
// 	t_list *node2 = ft_lstnew("World");
// 	t_list *node3 = ft_lstnew("!");

// 	node1->next = node2;
// 	node2->next = node3;

// 	printf("Created list:\n");
// 	print_list(node1);

// 	free(node1);
// 	free(node2);
// 	free(node3);

// 	return 0;
// }
