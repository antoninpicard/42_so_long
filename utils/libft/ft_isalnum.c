/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anpicard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 11:03:44 by anpicard          #+#    #+#             */
/*   Updated: 2024/11/12 14:25:38 by anpicard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isalnum(int c)
{
	return (ft_isalpha(c) || ft_isdigit(c));
}

// #include <ctype.h>
// #include <stdio.h>

// int main()
// {
//     int test_values[] = {'a', 'Z', '0', '9', '!', ' ', 127, -1};
//     int num_tests = sizeof(test_values) / sizeof(test_values[0]);
//     int success = 1;

//     for (int i = 0; i < num_tests; i++)
//     {
//         int result_original = isalnum(test_values[i]);
//         int result_ft = ft_isalnum(test_values[i]);

//         if ((result_original != 0) != (result_ft != 0))
//         {
//             printf("Test %d: failed for input '%c' (ASCII: %d)\n", 
//						i + 1, test_values[i], test_values[i]);
//             success = 0;
//         }
//         else
//         {
//             printf("Test %d: success\n", i + 1);
//         }
//     }

//     if (success)
//         printf("All tests passed!\n");

//     return 0;
// }