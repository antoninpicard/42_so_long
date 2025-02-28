/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anpicard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/13 15:49:17 by anpicard          #+#    #+#             */
/*   Updated: 2025/02/28 09:02:06 by anpicard         ###   ########.fr       */
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

// void test_ft_memcmp(const void *ptr1, const void *ptr2, 
// 					size_t num, int expected) {
//     int result = ft_memcmp(ptr1, ptr2, num);

//     if (result == expected) {
//         printf("Test passed: memcmp returned the expected value.\n");
//     } else {
//         printf("Test failed: memcmp did not return the expected value.\n");
//         printf("Expected: %d, Got: %d\n", expected, result);
//     }
// }

// int main() {
//     // Cas 1 : Comparaison de deux blocs identiques
//     // Les deux blocs sont identiques, donc la comparaison doit renvoyer 0
//     char str1[] = "Hello";
//     char str2[] = "Hello";
//     test_ft_memcmp(str1, str2, 5, 0);

//     // Cas 2 : Comparaison de deux blocs différents
//     // "Hello" est inférieur à "World", donc un nombre négatif
//     char str3[] = "Hello";
//     char str4[] = "World";
//     test_ft_memcmp(str3, str4, 5, -15);

//     // Cas 3 : Comparaison d'un bloc plus grand
//     char str5[] = "Hello";
//     char str6[] = "Hello, World!";
//     test_ft_memcmp(str5, str6, 5, 0);

//     // Cas 4 : Comparaison avec un bloc vide
//     // Aucun caractère à comparer, la comparaison doit renvoyer 0
//     char str7[] = "";
//     test_ft_memcmp(str7, str1, 0, 0);

//     // Cas 5 : Comparaison de chaînes de caractères
//     // Les chaînes "abcd" sont identiques, donc la comparaison renvoye 0
//     char str8[] = "abcd";
//     char str9[] = "abcd";
//     test_ft_memcmp(str8, str9, 4, 0); 

//     // Cas 6 : Comparaison avec un bloc de taille 0
//     // Comparaison de taille 0, doit renvoyer 0
//     test_ft_memcmp(str1, str2, 0, 0); 
//     // Cas 7 : Comparaison de blocs contenant des entiers et des caractères
//     // Les blocs diffèrent au dernier entier (3 vs 4), donc un nombre négatif
//     int arr1[] = {1, 2, 3};
//     int arr2[] = {1, 2, 4};
//     test_ft_memcmp(arr1, arr2, sizeof(arr1), -1); 

//     // Cas 8 : Comparaison de blocs adjacents en mémoire
//     char *adj_str1 = "Hello";
//     char *adj_str2 = "Hello";
//     test_ft_memcmp(adj_str1, adj_str2, 5, 0);

//     // Cas 9 : Comparaison avec une partie de mémoire identique
//     char str10[] = "Hello, World!";
//     char str11[] = "Hello, friend!";
//     // Les 5 premiers caractères sont identiques, donc 0
//     test_ft_memcmp(str10, str11, 5, 0); 
//     // Les 8 premiers caractères diffèrent, donc un nombre négatif
//     test_ft_memcmp(str10, str11, 8, -15); 

//     return 0;
// }