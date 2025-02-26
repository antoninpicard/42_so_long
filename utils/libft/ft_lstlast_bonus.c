/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anpicard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 10:24:00 by anpicard          #+#    #+#             */
/*   Updated: 2024/11/12 13:57:58 by anpicard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstlast(t_list *lst)
{
	if (!lst)
		return (NULL);
	while (lst->next)
		lst = lst->next;
	return (lst);
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
// 	t_list *list = ft_lstnew("First");
// 	list->next = ft_lstnew("Second");
// 	list->next->next = ft_lstnew("Third");

// 	t_list *last = ft_lstlast(list);
// 	if (last)
// 		printf("Last element content: %s\n", (char *)last->content);
// 	else
// 		printf("List is empty\n");

// 	// Libération de la mémoire
// 	free(list->next->next);
// 	free(list->next);
// 	free(list);

// 	return 0;
// }