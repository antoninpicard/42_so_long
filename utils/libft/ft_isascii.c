/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isascii.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anpicard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 11:03:39 by anpicard          #+#    #+#             */
/*   Updated: 2024/11/12 14:25:28 by anpicard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isascii(int c)
{
	return (c >= 0 && c < 128);
}
// #include <ctype.h>
// #include <stdio.h>

// int main()
// {
//     int test_values[] = {0, 127, 128, -1, 'A', 'z', 255, 65, 32, 100};
//     int num_tests = sizeof(test_values) / sizeof(test_values[0]);
//     int success = 1;

//     for (int i = 0; i < num_tests; i++)
//     {
//         int result_original = isascii(test_values[i]);
//         int result_ft = ft_isascii(test_values[i]);

//         if ((result_original != 0) != (result_ft != 0))
//         {
//             printf("Test %d: failed for input '%d'\n", i + 1, 
//						test_values[i]);
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
