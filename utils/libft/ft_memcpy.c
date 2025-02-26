/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anpicard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 11:03:24 by anpicard          #+#    #+#             */
/*   Updated: 2024/11/12 14:40:46 by anpicard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	if (!dest && !src)
		return (NULL);
	return (ft_memmove(dest, src, n));
}

// #include <stdio.h>
// #include <string.h>
// void test_memcpy(void *dest, const void *src, size_t n, void
//		*expected_dest)
// {
//     ft_memcpy(dest, src, n);
//     if (memcmp(dest, expected_dest, n) == 0) {
//         printf("Test passed: memcpy correctly copied %zu bytes.\n", n);
//     } else {
//         printf("Test failed: memcpy did not correctly copy
//				%zu bytes.\n", n);
//     }
// }
// int main() {
//     char str1[] = "Hello, World!";
//     char str2[20];
//     test_memcpy(str2, str1, 13, "Hello, World!");
//     int arr1[] = {1, 2, 3, 4, 5};
//     int arr2[5];
//     test_memcpy(arr2, arr1, sizeof(arr1), arr1);
//     char arr3[] = "Hello, World!";
//     char arr4[20];
//     test_memcpy(arr4, arr3, 5, "Hello");
//     char str3[5] = "Test";
//     char str4[20];
//     test_memcpy(str4, str3, 5, "Test");
//     char str5[10] = "Test";
//     char str6[10] = "";
//     test_memcpy(str6, str5, 0, "");
//     char arr5[] = "Hello";
//     char arr6[6];
//     test_memcpy(arr6, arr5, 6, "Hello");
//     char arr7[] = "Hello";
//     test_memcpy(arr7 + 2, arr7, 3, "Hel");
//     char arr8[] = "abcdef";
//     test_memcpy(arr8 + 2, arr8, 3, "abc");
//     return 0;
// }