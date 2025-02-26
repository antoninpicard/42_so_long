/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anpicard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 16:39:57 by anpicard          #+#    #+#             */
/*   Updated: 2024/11/12 13:51:01 by anpicard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*tmp;

	if (!lst || !del)
		return ;
	while (*lst)
	{
		tmp = (*lst)->next;
		del((*lst)->content);
		free(*lst);
		*lst = tmp;
	}
	*lst = NULL;
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

// void print_list(t_list *lst)
// {
// 	while (lst)
// 	{
// 		printf("%s -> ", (char *)lst->content);
// 		lst = lst->next;
// 	}
// 	printf("NULL\n");
// }

// void del(void *content)
// {
// 	free(content);
// }

// int main()
// {
// 	t_list *list = ft_lstnew(strdup("First"));
// 	list->next = ft_lstnew(strdup("Second"));
// 	list->next->next = ft_lstnew(strdup("Third"));

// 	printf("Before clearing:\n");
// 	print_list(list);

// 	ft_lstclear(&list, del);

// 	printf("After clearing:\n");
// 	print_list(list);

// 	return 0;
// }
