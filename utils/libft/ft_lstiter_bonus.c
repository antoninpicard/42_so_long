/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anpicard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 14:16:59 by anpicard          #+#    #+#             */
/*   Updated: 2024/11/12 13:56:48 by anpicard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstiter(t_list *lst, void (*f)(void *))
{
	while (lst)
	{
		f(lst->content);
		lst = lst->next;
	}
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

// void print_content(void *content)
// {
// 	printf("%s\n", (char *)content);
// }

// int main()
// {
// 	t_list *list = ft_lstnew(strdup("First"));
// 	list->next = ft_lstnew(strdup("Second"));
// 	list->next->next = ft_lstnew(strdup("Third"));

// 	printf("List contents:\n");
// 	ft_lstiter(list, print_content);

// 	free(list->next->next->content);
// 	free(list->next->next);
// 	free(list->next->content);
// 	free(list->next);
// 	free(list->content);
// 	free(list);

// 	return 0;
// }