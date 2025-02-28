/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anpicard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 17:14:17 by anpicard          #+#    #+#             */
/*   Updated: 2025/02/28 09:02:06 by anpicard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_count(long nb)
{
	int	count;

	count = 0;
	if (nb < 0)
	{
		nb = nb * (-1);
		count = 1;
	}
	if (nb == 0)
		count = 1;
	else
	{
		while (nb)
		{
			nb = nb / 10;
			count++;
		}
	}
	return (count);
}

char	*ft_itoa(int n)
{
	int		len;
	int		is_neg;
	char	*str;
	long	nb;

	nb = (long)n;
	len = ft_count(nb);
	str = (char *) malloc(sizeof(char) * (len + 1));
	if (!str)
		return (NULL);
	is_neg = (nb < 0);
	if (is_neg)
		nb = -nb;
	str[len] = '\0';
	while (len--)
	{
		str[len] = (nb % 10) + '0';
		nb = nb / 10;
	}
	if (is_neg)
		str[0] = '-';
	return (str);
}

// #include <limits.h>
// #include <stdio.h>
// #include <string.h>

// void test_ft_itoa(long int num, const char *expected) {
//     // Appel de la fonction itoa
//     char *result = ft_itoa(num);  // Conversion en base 10

//     // Comparaison du résultat
//     if (strcmp(result, expected) == 0) {
//         printf("Test passed for itoa(%ld) -> \"%s\"\n", num, result);
//     } else {
//         printf("Test failed for itoa(%ld)\n", num);
//         printf("Expected: \"%s\"\n", expected);
//         printf("Got: \"%s\"\n", result);
//     }
// 	free(result);
// }

// int main() {
//     // Cas 1 : Test pour un entier positif simple
//     test_ft_itoa(123, "123");

//     // Cas 2 : Test pour un entier négatif
//     test_ft_itoa(-123, "-123");

//     // Cas 3 : Test pour zéro
//     test_ft_itoa(0, "0");

//     // Cas 4 : Test pour un nombre positif avec plusieurs chiffres
//     test_ft_itoa(4567, "4567");

//     // Cas 5 : Test pour un nombre négatif avec plusieurs chiffres
//     test_ft_itoa(-4567, "-4567");

//     // Cas 6 : Test pour le plus grand entier possible (INT_MAX)
//     test_ft_itoa(INT_MAX, "2147483647");

//     // Cas 7 : Test pour le plus petit entier possible (INT_MIN)
//     test_ft_itoa(INT_MIN, "-2147483648");

//     // Cas 8 : Test pour un nombre avec un seul chiffre
//     test_ft_itoa(7, "7");
//     test_ft_itoa(-7, "-7");

//     // Cas 9 : Test pour les valeurs limites
//     test_ft_itoa(999999, "999999");
//     test_ft_itoa(-999999, "-999999");

//     return 0;
// }