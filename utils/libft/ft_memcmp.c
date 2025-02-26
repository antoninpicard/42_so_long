/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anpicard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 11:03:27 by anpicard          #+#    #+#             */
/*   Updated: 2024/11/12 14:39:52 by anpicard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n && *(unsigned char *)(s1 + i) == *(unsigned char *)(s2 + i))
		i++;
	if (i < n)
		return (*(unsigned char *)(s1 + i) - *(unsigned char *)(s2 + i));
	return (0);
}
// #include <stdio.h>
// #include <string.h>

// int main()
// {
//     char str1[] = "Hello, World!";
//     char str2[] = "Hello, World!";
//     char str3[] = "Hello, C Programmers!";
//     int result1 = ft_memcmp(str1, str2, strlen(str1));
//     printf("Test 1: %d (Expected: 0)\n", result1);

//     int result2 = ft_memcmp(str1, str3, strlen(str1));
//     printf("Test 2: %d (Expected: non-zero)\n", result2);

//     int result3 = ft_memcmp(str1, str3, 5);
//     printf("Test 3: %d (Expected: 0)\n", result3);

//     return 0;
// }
