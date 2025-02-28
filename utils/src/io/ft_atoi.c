/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anpicard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 10:59:13 by anpicard          #+#    #+#             */
/*   Updated: 2025/02/28 09:02:06 by anpicard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <limits.h>

int	ft_atoi(const char *str)
{
	size_t		i;
	int			sign;
	long int	result;

	i = 0;
	sign = 1;
	result = 0;
	while ((str[i] >= '\t' && str[i] <= '\r') || str[i] == ' ')
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		if ((result * 10 + str[i] - '0') / 10 == result)
			result = result * 10 + str[i] - '0';
		else
			return ((sign < 0) * LONG_MIN + (sign > 0) * LONG_MAX);
		i++;
	}
	return (result * sign);
}

// #include <stdio.h>

// void test_ft_atoi(const char *str, int expected) {
//     int result = ft_atoi(str);
//     if (result == expected) {
//         printf("Test passed for ft_atoi(\"%s\")\n", str);
//     } else {
//         printf("Test failed for ft_atoi(\"%s\")\n", str);
//         printf("Expected: %d\n", expected);
//         printf("Got: %d\n", result);
//     }
// }

// int main() {
//     // Cas 1 : Nombre positif simple
//     test_ft_atoi("123", 123);

//     // Cas 2 : Nombre négatif simple
//     test_ft_atoi("-123", -123);

//     // Cas 3 : Nombre avec des espaces avant
//     // (devrait ignorer les espaces au début)
//     test_ft_atoi("   456", 456);

//     // Cas 4 : Nombre avec des signes plus et moins au début
//     test_ft_atoi("+789", 789);
//     test_ft_atoi("   -42", -42);

//     // Cas 5 : Nombre avec zéro au début
//     test_ft_atoi("000123", 123);

//     // Cas 6 : Nombre entouré d'espaces et de caractères non numériques
//     // (devrait s'arrêter au premier caractère non numérique)
//     test_ft_atoi("   123abc", 123);
//     test_ft_atoi("   -456xyz", -456);
//     test_ft_atoi("789abc123", 789);

//     // Cas 7 : Chiffre unique
//     test_ft_atoi("5", 5);

//     // Cas 8 : Entrée vide (devrait retourner 0)
//     test_ft_atoi("", 0);

//     // Cas 9 : Chaîne avec seulement des espaces (devrait retourner 0)
//     test_ft_atoi("   ", 0);

//     // Cas 10 : Valeur maximale d'un entier (devrait être INT_MAX)
//     test_ft_atoi("2147483647", INT_MAX);

//     // Cas 11 : Valeur minimale d'un entier (devrait être INT_MIN)
//     test_ft_atoi("-2147483648", INT_MIN);

//     // Cas 12 : Dépassement positif
//     // (devrait retourner INT_MAX dans une bonne implémentation)
//     test_ft_atoi("2147483648", -2147483648);

//     // Cas 13 : Dépassement négatif
//     // (devrait retourner INT_MIN dans une bonne implémentation)
//     test_ft_atoi("-2147483649", 2147483647);

//     // Cas 14 : Entrée avec plusieurs signes
//     // (devrait retourner 0 car non valide)
//     test_ft_atoi("+-123", 0);
//     test_ft_atoi("-+123", 0);

//     // Cas 15 : Entrée sans chiffres mais avec signes (devrait retourner 0)
//     test_ft_atoi("-", 0);
//     test_ft_atoi("+", 0);

//     return (0);
// }