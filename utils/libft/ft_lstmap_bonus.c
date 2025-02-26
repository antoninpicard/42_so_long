/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anpicard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 14:29:21 by anpicard          #+#    #+#             */
/*   Updated: 2024/11/12 14:26:08 by anpicard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new_lst;
	t_list	*new_node;
	void	*new_content;

	if (!lst || !f || !del)
		return (NULL);
	new_lst = NULL;
	while (lst)
	{
		new_content = f(lst->content);
		new_node = ft_lstnew(new_content);
		if (!new_node)
		{
			del(new_content);
			ft_lstclear(&new_lst, del);
			return (NULL);
		}
		ft_lstadd_back(&new_lst, new_node);
		lst = lst->next;
	}
	return (new_lst);
}
// #include <stdio.h>
// #include <stdlib.h>
// #include <string.h>

// t_list *ft_lstnew(void *content)
// {
// 	t_list *new = (t_list *)malloc(sizeof(t_list));
// 	if (!new)
// 		return (NULL);
// 	new->content = content;
// 	new->next = NULL;
// 	return (new);
// }

// void ft_lstadd_back(t_list **lst, t_list *new)
// {
// 	t_list *last;

// 	if (!new)
// 		return;
// 	if (!*lst)
// 	{
// 		*lst = new;
// 		return;
// 	}
// 	last = ft_lstlast(*lst);
// 	last->next = new;
// }

// t_list *ft_lstlast(t_list *lst)
// {
// 	if (!lst)
// 		return (NULL);
// 	while (lst->next)
// 		lst = lst->next;
// 	return (lst);
// }

// void ft_lstclear(t_list **lst, void (*del)(void *))
// {
// 	t_list *tmp;

// 	while (*lst)
// 	{
// 		tmp = (*lst)->next;
// 		del((*lst)->content);
// 		free(*lst);
// 		*lst = tmp;
// 	}
// 	*lst = NULL;
// }

// void *duplicate_content(void *content)
// {
// 	return strdup((char *)content);
// }

// void delete_content(void *content)
// {
// 	free(content);
// }

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
// 	t_list *list = ft_lstnew(strdup("First"));
// 	list->next = ft_lstnew(strdup("Second"));
// 	list->next->next = ft_lstnew(strdup("Third"));

// 	printf("Original list:\n");
// 	print_list(list);

// 	t_list *mapped_list = ft_lstmap(list, duplicate_content, 
//			delete_content);

// 	printf("Mapped list:\n");
// 	print_list(mapped_list);

// 	// Libération de la mémoire
// 	ft_lstclear(&list, delete_content);
// 	ft_lstclear(&mapped_list, delete_content);

// 	return 0;
// }
