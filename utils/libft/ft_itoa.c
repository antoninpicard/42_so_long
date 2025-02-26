/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anpicard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 11:03:32 by anpicard          #+#    #+#             */
/*   Updated: 2024/11/15 13:15:38 by anpicard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_count(long nb)
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

char	*ft_itoa(long int n)
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

// #include <stdio.h>
// #include <stdlib.h>
// #include <string.h>

// int main()
// {
//     int test_values[] = {0, -123, 456, -2147483648, 2147483647};
//     char *expected_results[] = {"0", "-123", "456", "-2147483648",
//					 "2147483647"};
//     int num_tests = sizeof(test_values) / sizeof(test_values[0]);
//     int success = 1;

//     for (int i = 0; i < num_tests; i++)
//     {
//         char *result = ft_itoa(test_values[i]);
//         if (strcmp(result, expected_results[i]) != 0)
//         {
//             printf("Test %d: failed for input %d, expected '%s', got
//					 '%s'\n", i + 1, 
//						test_values[i], expected_results[i], result);
//             success = 0;
//         }
//         else
//         {
//             printf("Test %d: success\n", i + 1);
//         }
//         free(result);
//     }

//     if (success)
//         printf("All tests passed!\n");

//     return 0;
// }
