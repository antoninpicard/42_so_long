/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anpicard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/13 15:16:31 by anpicard          #+#    #+#             */
/*   Updated: 2025/02/28 09:02:06 by anpicard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int	i;

	i = ft_strlen(s);
	while (i >= 0)
	{
		if (s[i] == (unsigned char) c)
			return ((char *) s + i);
		i--;
	}
	return (NULL);
}

// #include <string.h>
// #include <stdio.h>

// void test_ft_strrchr(const char *str, int c, const char *expected) {
//     char *result = ft_strrchr(str, c);

//     // Vérification spéciale pour le cas où c est 
// 	// '\0' et result doit pointer à la fin
//     if (c == '\0') {
//         if (result == str + strlen(str)) {
//             printf("Test passed for strrchr(\"%s\", '\\0')\n", str);
//         } else {
//             printf("Test failed for strrchr(\"%s\", '\\0')\n", str);
//             printf("Expected: pointer to end of string\n");
//             printf("Got: %s\n", result ? result : "NULL");
//         }
//     } else {
//         if (result == expected) {
//             printf("Test passed for strrchr(\"%s\", '%c')\n", str, c);
//         } else {
//             printf("Test failed for strrchr(\"%s\", '%c')\n", str, c);
//             printf("Expected: %s\n", expected ? expected : "NULL");
//             printf("Got: %s\n", result ? result : "NULL");
//         }
//     }
// }

// int main(void)
// {
// 	// char *test = strrchr(NULL, 'a');
// 	// char *test2 = ft_strrchr(NULL, 'a');
// 	// ft_strrchr(NULL, 't');
// 	// strrchr(NULL, 't');

// 	// Cas 1 : Caractère présent plusieurs fois dans la chaîne
//     test_ft_strrchr("hello world", 'o', "orld");

//     // Cas 2 : Caractère présent une seule fois
//     test_ft_strrchr("hello world", 'w', "world");

//     // Cas 3 : Caractère au début de la chaîne
//     test_ft_strrchr("hello world", 'h', "hello world");

//     // Cas 4 : Caractère à la fin de la chaîne
//     test_ft_strrchr("hello world", 'd', "d");

//     // Cas 5 : Caractère absent de la chaîne
//     test_ft_strrchr("hello world", 'x', NULL);

//     // Cas 6 : Rechercher le caractère nul '\0' 
// 	// (devrait pointer vers la fin de la chaîne)
//     test_ft_strrchr("hello world", '\0', "");

//     // Cas 7 : Chaîne vide et recherche de '\0' (
// 	// devrait retourner le pointeur vers la chaîne vide)
//     test_ft_strrchr("", '\0', "");

//     // Cas 8 : Chaîne vide et recherche d'un caractère autre que 
// 	// '\0' (devrait retourner NULL)
//     test_ft_strrchr("", 'a', NULL);

//     // Cas 9 : Rechercher un caractère dans une chaîne de longueur 1 
// 	// (cas unique)
//     test_ft_strrchr("a", 'a', "a");

//     // Cas 10 : Rechercher un caractère absent dans une chaîne de longueur 1
//     test_ft_strrchr("a", 'b', NULL);

// 	return 0;
// }