/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anpicard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 16:39:32 by anpicard          #+#    #+#             */
/*   Updated: 2024/11/12 13:32:50 by anpicard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*last;

	if (!new)
		return ;
	if (!*lst)
	{
		*lst = new;
		return ;
	}
	last = ft_lstlast(*lst);
	last->next = new;
}

// #include "libft.h"
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
// int main()
// {
// 	t_list *list = ft_lstnew("First");
// 	t_list *new_elem1 = ft_lstnew("Second");
// 	t_list *new_elem2 = ft_lstnew("Third");

// 	ft_lstadd_back(&list, new_elem1);
// 	ft_lstadd_back(&list, new_elem2);

// 	print_list(list); 

// 	return 0;
// }