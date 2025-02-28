/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anpicard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/13 00:13:34 by anpicard          #+#    #+#             */
/*   Updated: 2025/02/28 09:02:06 by anpicard         ###   ########.fr       */
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

// void test_memset(void *dest, int c, size_t n, void *expected_dest) {
//     ft_memset(dest, c, n);

//     if (memcmp(dest, expected_dest, n) == 0) {
//         printf("Test passed: %zu bytes.\n", n);
//     } else {
//         printf("Test failed: %zu bytes.\n", n);
//     }
// }

// int main() {
//     // Test 1: Remplir avec 'A' (valeur 65 en ASCII)
//     char str1[10];
//     test_memset(str1, 'A', 5, "AAAAA");

//     // Test 2: Remplir avec des espaces (valeur 32 en ASCII)
//     char str2[10];
//     test_memset(str2, 32, 10, "          ");

//     // Test 3: Cas où la taille est 0 (Aucun changement)
//     char str4[10] = "Hello";
//     test_memset(str4, 65, 0, "Hello");

//     // Test 4: Remplir une taille de 1
//     char str5[1];
//     test_memset(str5, 'Z', 1, "Z");

//     // Test 5: Remplir avec 255 (0xFF)
//     unsigned char str6[5];
//     test_memset(str6, 255, 5, 
//                 "\xFF\xFF\xFF\xFF\xFF");

//     return 0;
// }
