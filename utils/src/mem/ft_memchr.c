/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anpicard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/13 15:40:38 by anpicard          #+#    #+#             */
/*   Updated: 2025/02/28 09:02:06 by anpicard         ###   ########.fr       */
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

// void test_ft_memchr(void *ptr, int value, size_t num, void *expected) {
//     // Vérification si le pointeur est NULL
//     if (ptr == NULL) {
//         if (expected == NULL) {
//             printf("Test passed: returned NULL for NULL pointer.\n");
//         } else {
//             printf("Test failed: returned other than NULL for NULL.\n");
//         }
//         return;
//     }

//     // Appel de memchr si le pointeur n'est pas NULL
//     void *result = ft_memchr(ptr, value, num);

//     if (result == expected) {
//         printf("Test passed: memchr found %d as expected.\n", value);
//     } else {
//         printf("Test failed: memchr did not behave as expected.\n");
//         printf("Expected: %p, Got: %p\n", expected, result);
//     }
// }

// int main() {
//     // Cas 1 : Test de la recherche d'un caractère existant
//     char str1[] = "Hello, World!";
//     // Recherche 'o' qui est à la position 4
//     test_ft_memchr(str1, 'o', strlen(str1), str1 + 4); 

//     // Cas 2 : Test de la recherche d'un caractère inexistant
//     test_ft_memchr(str1, 'z', strlen(str1), NULL);
//     // Recherche 'z' qui n'existe pas

//     // Cas 3 : Recherche du caractère à la première position
//     // 'H' est à la position 0
//     test_ft_memchr(str1, 'H', strlen(str1), str1); 

//     // Cas 4 : Recherche du caractère à la dernière position
//     // '!' est à la dernière position
//     test_ft_memchr(str1, '!', strlen(str1), str1 + strlen(str1) - 1); 

//     // Cas 5 : Recherche du caractère qui apparaît plusieurs fois
//     // 'o' à la pos 4, nous arrêtons la recherche à la première occurrence
//     test_ft_memchr(str1, 'o', strlen(str1), str1 + 4); 

//     // Cas 6 : Recherche dans un tableau vide
//     // Il n'y a rien à rechercher, donc retourne NULL
//     test_ft_memchr(str1, 'H', 0, NULL); 

//     // Cas 7 : Recherche dans un tableau avec des entiers
//     // Recherche de l'élément 3, qui est à la position 2 dans le tableau
//     int arr[] = {1, 2, 3, 4, 5};
//     test_ft_memchr(arr, 3, sizeof(arr), arr + 2); 

//     // Cas 8 : Recherche avec un pointeur NULL
//     // Pointeur NULL, doit retourner NULL
//     test_ft_memchr(NULL, 'H', strlen(str1), NULL); 

//     return 0;
// }