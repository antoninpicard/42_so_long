/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anpicard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 11:03:49 by anpicard          #+#    #+#             */
/*   Updated: 2024/11/12 13:19:40 by anpicard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		*(unsigned char *)(s + i) = 0;
		i++;
	}
}

// #include <strings.h>
// #include <stdio.h>
// #include <string.h>

// int main()
// {
//     char str1[] = "Hello, World!";
//     char str2[] = "Hello, World!";
//     char str3[] = "42 School";
//     char str4[] = "42 School";

//     bzero(str1, 5);
//     bzero(str3, 9);

//     ft_bzero(str2, 5);
//     ft_bzero(str4, 9);

//     if (memcmp(str1, str2, sizeof(str1)) == 0)
//         printf("Test 1: success\n");
//     else
//         printf("Test 1: failed\n");

//     if (memcmp(str3, str4, sizeof(str3)) == 0)
//         printf("Test 2: success\n");
//     else
//         printf("Test 2: failed\n");

//     return 0;
// }