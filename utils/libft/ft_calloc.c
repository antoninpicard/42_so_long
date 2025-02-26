/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anpicard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 11:03:46 by anpicard          #+#    #+#             */
/*   Updated: 2024/11/12 13:22:07 by anpicard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	char	*arr;
	size_t	i;

	i = 0;
	arr = (char *) malloc(size * nmemb);
	if (!arr)
		return (NULL);
	while (i < nmemb * size)
	{
		arr[i] = 0;
		i++;
	}
	return ((void *) arr);
}

// #include <stdlib.h>
// #include <stdio.h>
// #include <string.h>

// int main()
// {
//     size_t nmemb1 = 5, size1 = sizeof(int);
//     size_t nmemb2 = 10, size2 = sizeof(char);
//     size_t nmemb3 = 0, size3 = sizeof(float);

//     int *arr1 = (int *)calloc(nmemb1, size1);
//     int *arr2 = (int *)ft_calloc(nmemb1, size1);

//     char *arr3 = (char *)calloc(nmemb2, size2);
//     char *arr4 = (char *)ft_calloc(nmemb2, size2);

//     float *arr5 = (float *)calloc(nmemb3, size3);
//     float *arr6 = (float *)ft_calloc(nmemb3, size3);

//     if (!arr1 || !arr2 || !arr3 || !arr4 || !arr5 || !arr6)
//     {
//         printf("Memory allocation failed\n");
//         return 1;
//     }

//     if (memcmp(arr1, arr2, nmemb1 * size1) == 0)
//         printf("Test 1: success\n");
//     else
//         printf("Test 1: failed\n");

//     if (memcmp(arr3, arr4, nmemb2 * size2) == 0)
//         printf("Test 2: success\n");
//     else
//         printf("Test 2: failed\n");

//     if (memcmp(arr5, arr6, nmemb3 * size3) == 0)
//         printf("Test 3: success\n");
//     else
//         printf("Test 3: failed\n");

//     free(arr1);
//     free(arr2);
//     free(arr3);
//     free(arr4);
//     free(arr5);
//     free(arr6);

//     return 0;
// }
