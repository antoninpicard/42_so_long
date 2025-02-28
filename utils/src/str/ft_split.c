/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anpicard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 16:23:26 by anpicard          #+#    #+#             */
/*   Updated: 2025/02/28 09:02:06 by anpicard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_count_words(char const *s, char c)
{
	size_t	nb_words;
	size_t	i;

	i = 0;
	nb_words = 0;
	while (s[i])
	{
		if (s[i] != c && (i == 0 || s[i - 1] == c))
			nb_words++;
		i++;
	}
	return (nb_words);
}

static char	*ft_copy_words(char const *src, size_t len)
{
	char	*str;
	size_t	i;

	str = (char *) malloc(sizeof(char) * (len + 1));
	if (!str)
		return (NULL);
	i = 0;
	while (i < len)
	{
		str[i] = src[i];
		i++;
	}
	str[i] = 0;
	return (str);
}

static void	ft_free_all(char **split, size_t count)
{
	size_t	i;

	i = 0;
	while (i < count)
	{
		free(split[i]);
		i++;
	}
	free(split);
}

static char	**split_words(char const *s, char c, char **split)
{
	size_t	i;
	size_t	j;
	size_t	k;

	i = 0;
	k = 0;
	while (s[i])
	{
		while (s[i] == c)
			i++;
		j = i;
		while (s[i] && s[i] != c)
			i++;
		if (i > j)
		{
			split[k] = ft_copy_words(s + j, i - j);
			if (!split[k++])
			{
				ft_free_all(split, k);
				return (NULL);
			}
		}
	}
	split[k] = 0;
	return (split);
}

char	**ft_split(char const *s, char c)
{
	char	**split;

	if (!s)
		return (NULL);
	split = (char **) malloc(sizeof(char *) * (ft_count_words(s, c) + 1));
	if (!split)
		return (NULL);
	return (split_words(s, c, split));
}

// #include <stdio.h>
// #include <string.h>
// #include <stdlib.h>

// // Fonction d'affichage pour les tests
// void print_split(char **split) {
//     int i = 0;
//     while (split[i]) {
//         printf("Split[%d]: %s\n", i, split[i]);
//         i++;
//     }
// }

// // Fonction de comparaison pour vérifier les résultats
// int compare_split(char **split, char **expected_split) {
//     int i = 0;
//     while (split[i] && expected_split[i]) {
//         if (strcmp(split[i], expected_split[i]) != 0) {
//             return 0; // échec si une comparaison échoue
//         }
//         i++;
//     }
//     if ((split[i] == NULL && expected_split[i] != NULL) || 
//         (split[i] != NULL && expected_split[i] == NULL)) {
//         return 0; // cas où les longueurs sont différentes
//     }
//     return 1; // succès si tout correspond
// }

// // Fonction de test pour ft_split
// void test_ft_split(const char *input, char delimiter, char **expected_result)
// {
//     char **result = ft_split(input, delimiter);

//     if (compare_split(result, expected_result)) {
//         printf("Test passed\n");
//     } else {
//         printf("Test failed\n");
//         printf("Input: %s\n", input);
//         print_split(result);
//     }

//     // Libération de la mémoire allouée par ft_split
//     for (int i = 0; result[i]; i++) {
//         free(result[i]);
//     }
//     free(result);
// }

// int main() {
//     // Test 1: Cas avec un séparateur unique
//     char *input1 = "hello,world";
//     char *expected1[] = {"hello", "world", NULL};
//     test_ft_split(input1, ',', expected1);

//     // Test 2: Cas avec plusieurs séparateurs
//     char *input2 = "apple,,banana";
//     char *expected2[] = {"apple", "banana", NULL};
//     test_ft_split(input2, ',', expected2);

//     // Test 3: Cas avec le séparateur au début de la chaîne
//     char *input3 = ",leading";
//     char *expected3[] = {"leading", NULL};
//     test_ft_split(input3, ',', expected3);

//     // Test 4: Cas avec le séparateur à la fin de la chaîne
//     char *input4 = "trailing,";
//     char *expected4[] = {"trailing", NULL};
//     test_ft_split(input4, ',', expected4);

//     // Test 5: Cas sans séparateur (la chaîne entière est un seul élément)
//     char *input5 = "nomatch";
//     char *expected5[] = {"nomatch", NULL};
//     test_ft_split(input5, ',', expected5);

//     // Test 6: Cas avec une chaîne vide
//     char *input6 = "";
//     char *expected6[] = {NULL};
//     test_ft_split(input6, ',', expected6);

//     // Test 7: Cas avec des espaces comme séparateurs
//     char *input7 = "this is a test";
//     char *expected7[] = {"this", "is", "a", "test", NULL};
//     test_ft_split(input7, ' ', expected7);

//     // Test 8: Cas avec des tabulations comme séparateurs
//     char *input8 = "tab\tseparated\tvalues";
//     char *expected8[] = {"tab", "separated", "values", NULL};
//     test_ft_split(input8, '\t', expected8);

//     // Test 9: Cas avec des séparateurs multiples
//     char *input9 = "word1,word2,,word3";
//     char *expected9[] = {"word1", "word2", "word3", NULL};
//     test_ft_split(input9, ',', expected9);

//     // Test 10: Cas avec des espaces multiples comme séparateurs
//     char *input10 = "  split  this  string  ";
//     char *expected10[] = {"split", "this", "string", NULL};
//     test_ft_split(input10, ' ', expected10);

//     // Test 11: Cas avec des caractères spéciaux
//     char *input11 = "abc@xyz#def@ghi";
//     char *expected11[] = {"abc", "xyz#def", "ghi", NULL};
//     test_ft_split(input11, '@', expected11);

//     // Test 12: Cas avec des séparateurs à la fin
//     char *input12 = "word1,word2,";
//     char *expected12[] = {"word1", "word2", NULL};
//     test_ft_split(input12, ',', expected12);

//     // Test 13: Cas avec une seule lettre comme entrée et un séparateur
//     char *input13 = "a";
//     char *expected13[] = {"a", NULL};
//     test_ft_split(input13, ',', expected13);

//     // Test 14: Cas avec des séquences complexes
//     char *input14 = "123,456,789";
//     char *expected14[] = {"123", "456", "789", NULL};
//     test_ft_split(input14, ',', expected14);

//     return 0;
// }
