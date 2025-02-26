/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anpicard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 10:08:15 by anpicard          #+#    #+#             */
/*   Updated: 2024/11/12 14:04:03 by anpicard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lstsize(t_list *lst)
{
	int	length;

	length = 0;
	while (lst)
	{
		length++;
		lst = lst->next;
	}
	return (length);
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

// int main()
// {
// 	t_list *node1 = ft_lstnew("Node 1");
// 	t_list *node2 = ft_lstnew("Node 2");
// 	t_list *node3 = ft_lstnew("Node 3");

// 	node1->next = node2;
// 	node2->next = node3;

// 	int size = ft_lstsize(node1);
// 	printf("List size: %d\n", size);

// 	free(node1);
// 	free(node2);
// 	free(node3);

// 	return 0;
// }