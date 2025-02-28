/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anpicard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/13 00:40:25 by anpicard          #+#    #+#             */
/*   Updated: 2025/02/28 09:02:06 by anpicard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	unsigned char		*d;
	const unsigned char	*s;

	if ((!dest && !src) && n)
		return (NULL);
	d = dest;
	s = src;
	while (n--)
		*d++ = *s++;
	return (dest);
}

// #include <stdio.h>
// #include <string.h>

// // Fonction pour tester memcpy
// void test_memcpy(void *dest, const void *src, size_t n, void *expected_dest)
// {
//     ft_memcpy(dest, src, n);  // Copie n octets de src vers dest

//     // Vérification de la comparaison entre dest et expected_dest
//     if (memcmp(dest, expected_dest, n) == 0) {
//         printf("Test passed: memcpy correctly copied %zu bytes.\n", n);
//     } else {
//         printf("Test failed: memcpy did not correctly copy %zu bytes.\n", n);
//     }
// }	

// int main() {
//     // Cas 1 : Copie simple de chaînes de caractères
//     // Copier les 13 premiers caractères de la chaîne dans str2
//     char str1[] = "Hello, World!";
//     char str2[20];
//     test_memcpy(str2, str1, 13, "Hello, World!");

//     // Cas 2 : Copie d'un bloc de mémoire (copie de données binaires)
//     // Copier tout le tableau d'entiers arr1 dans arr2
//     int arr1[] = {1, 2, 3, 4, 5};
//     int arr2[5]; // Assurez-vous que le tableau est suffisamment grand
//     test_memcpy(arr2, arr1, sizeof(arr1), arr1);

//     // Cas 3 : Copie d'une petite partie de données d'un tableau
//     // Copier les 5 premiers caractères de la chaîne dans arr4
//     char arr3[] = "Hello, World!";
//     char arr4[20]; // Assurez-vous que le tableau est suffisamment grand
//     test_memcpy(arr4, arr3, 5, "Hello");

//     // Cas 4 : Copie d'un tableau avec une taille incorrecte
//     // Essayez de copier plus de caractères que la taille du tableau source
//     // Essayons de copier plus de caractères que la source
//     char str3[5] = "Test"; // Taille du tableau = 5
//     char str4[20];         // Taille suffisante pour recevoir la copie
//     test_memcpy(str4, str3, 5, "Test");

//     // Cas 5 : Copie d'un bloc de taille 0
//     // Aucune donnée ne doit être copiée, str6 reste vide
//     char str5[10] = "Test"; // Contient "Test"
//     char str6[10] = "";     // Contient une chaîne vide
//     test_memcpy(str6, str5, 0, "");

//     // Cas 6 : Copie de données avec des valeurs négatives
//     // Copier la chaîne "Hello" dans arr6
//     char arr5[] = "Hello";
//     char arr6[6];
//     test_memcpy(arr6, arr5, 6, "Hello");

//     // Cas 7 : Copie dans le même tableau (même adresse)
//     // Copier les 3 premiers caractères de "Hello" dans l'arr7 à partir de i2
//     char arr7[] = "Hello";
//     test_memcpy(arr7 + 2, arr7, 3, "Hel");

//     // Cas 8 : Copie dans une zone mémoire qui se chevauche
//     char arr8[] = "abcdef";
//     test_memcpy(arr8 + 2, arr8, 3, "abc");

//     return 0;
// }