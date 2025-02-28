/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anpicard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/13 00:47:55 by anpicard          #+#    #+#             */
/*   Updated: 2025/02/28 09:02:06 by anpicard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	size_t	i;

	if (!dest && !src && n)
		return (NULL);
	if (dest < src)
	{
		i = 0;
		while (i < n)
		{
			*(unsigned char *)(dest + i) = *(unsigned char *)(src + i);
			i++;
		}
	}
	else
	{
		i = n;
		while (i > 0)
		{
			i--;
			*(unsigned char *)(dest + i) = *(unsigned char *)(src + i);
		}
	}
	return (dest);
}

// #include <stdio.h>
// #include <string.h>

// void test_memmove(void *dest, const void *src, size_t n, void *expected_dest)
// {
//     ft_memmove(dest, src, n);

//     if (memcmp(dest, expected_dest, n) == 0) {
//         printf("Test passed: memmove correctly copied %zu bytes.\n", n);
//     } else {
//         printf("Test failed: memmove didn't correctly copy %zu bytes.\n", n);
//     }
// }

// int main() {
//     // Test 1 : Cas simple de copie d'une chaîne de caractères
//     char str1[] = "Hello, World!";
//     char str2[20];
//     test_memmove(str2, str1, 13, "Hello, World!");

//     // Test 2 : Cas de copie d'un tableau d'entiers
//     int arr1[] = {1, 2, 3, 4, 5};
//     int arr2[5];
//     test_memmove(arr2, arr1, sizeof(arr1), arr1);

//     // Test 3 : Cas de copie partielle d'une chaîne de caractères
//     char arr3[] = "Hello, World!";
//     char arr4[20];
//     test_memmove(arr4, arr3, 5, "Hello");

//     // Test 4 : Copie d'un tableau d'une taille spécifique
//     char str3[4] = "Test";
//     char str4[20];
//     test_memmove(str4, str3, 4, "Test");

//     // Test 5 : Cas où aucune donnée n'est copiée (taille = 0)
//     char str5[10] = "Test";
//     char str6[10] = "";
//     test_memmove(str6, str5, 0, "");

//     // Test 6 : Cas où la destination et la source se chevauchent
//     // Copier "abc" dans la zone qui se chevauche
//     char arr5[] = "abcdef";
//     test_memmove(arr5 + 2, arr5, 3, "abc");

//     // Test 7 : Copie dans une z mémoire qui se chevauche dans le sens invers
//     char arr6[] = "abcdef";
//     test_memmove(arr6 + 3, arr6, 3, "abc");

//     // Test 8 : Cas avec une chaîne vide source
// 	// Copier une chaîne vide, aucune modification
//     char *empty_src = "";
//     char arr7[10] = "Hello";
//     test_memmove(arr7, empty_src, 0, "");

//     // Test 9 : Cas avec une source qui contient uniquement des zéros
//     char arr8[10] = {0}; // Source avec des zéros
//     test_memmove(arr7, arr8, 10, arr8); // Copier des zéros dans arr7

//     // Test 10 : Cas de mémoire identique (copie dans le même tableau)
// 	// Copier "Hello" dans la zone mémoire qui commence à l'indice 7
//     char arr9[] = "Hello, World!";
//     test_memmove(arr9 + 7, arr9, 5, "Hello");

//     return 0;
// }