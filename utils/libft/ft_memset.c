/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anpicard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 11:03:19 by anpicard          #+#    #+#             */
/*   Updated: 2024/11/14 09:07:24 by anpicard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *s, int c, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		*(unsigned char *)(s + i) = (unsigned char) c;
		i++;
	}
	return (s);
}
// #include <stdio.h>
// #include <string.h>

// int main()
// {
//     char str1[50] = "Hello, World!";
//     char str2[50] = "Hello, World!";

//     ft_memset(str1, 'x', 5);
//     printf("ft_memset result: %s\n", str1);

//     memset(str2, 'x', 5);
//     printf("Standard memset result: %s\n", str2);

//     char str3[50] = "Another Test String";
//     ft_memset(str3, '*', strlen(str3));
//     printf("ft_memset full overwrite: %s\n", str3);

//     return 0;
// }
