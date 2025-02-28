/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anpicard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 19:31:46 by anpicard          #+#    #+#             */
/*   Updated: 2025/02/28 09:02:06 by anpicard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*arr;
	size_t	total;

	total = nmemb * size;
	if (nmemb && size && (total / nmemb != size))
		return (NULL);
	arr = malloc(total);
	if (!arr)
		return (NULL);
	ft_memset(arr, 0, total);
	return (arr);
}

// #include <stdio.h>

// void test_calloc(size_t num_elements, size_t element_size) {
//     // Appel de calloc
//     void *ptr = ft_calloc(num_elements, element_size);

//     // Vérifier si l'allocation a échoué
//     if (ptr == NULL) {
//         printf("Test failed: Memory allocation failed\n");
//         return;
//     }

//     // Vérifier si la mémoire est initialisée à zéro
//     unsigned char *byte_ptr = (unsigned char *)ptr;
//     for (size_t i = 0; i < num_elements * element_size; i++) {
//         if (byte_ptr[i] != 0) {
//             printf("Test failed: Not initialized to zero at index %zu\n", i);
//             free(ptr);
//             return;
//         }
//     }

//     printf("Test passed: %zu size %zu\n", num_elements, element_size);

//     // Libérer la mémoire allouée
//     free(ptr);
// }

// int main() {
//     // Cas 1 : Test d'allocation pour un petit 
//     // nombre d'éléments de petite taille (type int)
//     // Allouer de la mémoire pour 10 entiers
//     test_calloc(10, sizeof(int));

//     // Cas 2 : Test d'allocation pour un grand nombre d'éléments
//     // Allouer de la mémoire pour 1000 caractères
//     test_calloc(1000, sizeof(char));

//     // Cas 3 : Test avec une taille d'élément plus grande (type double)
//     // Allouer de la mémoire pour 5 doubles
//     test_calloc(5, sizeof(double));

//     // Cas 4 : Test de l'allocation pour un nombre d'éléments de taille zéro
//     // Allouer de la mémoire pour 0 entiers
//     test_calloc(0, sizeof(int));

//     // Cas 5 : Test de l'allocation avec 
//     // une taille d'élément nulle (doit échouer)
//     // Allouer de la mémoire pour 10 éléments de taille 0
//     test_calloc(10, 0);

//     // Cas 6 : Test avec une allocation très grande
//     // Allouer un nombre très grand d'éléments
//     test_calloc(1000000000, sizeof(int));

//     return 0;
// }