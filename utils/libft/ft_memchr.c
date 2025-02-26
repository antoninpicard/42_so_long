/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anpicard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 11:03:29 by anpicard          #+#    #+#             */
/*   Updated: 2024/11/12 14:26:22 by anpicard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		if (*(unsigned char *)(s + i) == (unsigned char) c)
			return ((void *)(s + i));
		i++;
	}
	return (NULL);
}
// #include <stdio.h>
// #include <string.h>

// int main()
// {
//     char str[] = "Hello, World!";
//     char c1 = 'W';
//     char c2 = 'z';

//     char *result1 = ft_memchr(str, c1, strlen(str));
//     char *result2 = ft_memchr(str, c2, strlen(str));

//     if (result1)
//         printf("Character '%c' found at position: %ld\n", 
//					c1, result1 - str);
//     else
//         printf("Character '%c' not found\n", c1);

//     if (result2)
//         printf("Character '%c' found at position: %ld\n",
//					c2, result2 - str);
//     else
//         printf("Character '%c' not found\n", c2);

//     return 0;
// }