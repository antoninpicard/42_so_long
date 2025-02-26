/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anpicard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 11:02:58 by anpicard          #+#    #+#             */
/*   Updated: 2024/11/14 09:06:46 by anpicard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n && s1[i] && s1[i] == s2[i])
		i++;
	if (i < n)
		return ((unsigned char) s1[i] - (unsigned char) s2[i]);
	return (0);
}

// #include <stdio.h>
// #include <string.h>

// int main()
// {
//     const char *str1 = "Hello, World!";
//     const char *str2 = "Hello, World!";
//     const char *str3 = "Hello, Universe!";
//     size_t n = 5;

//     int result1 = ft_strncmp(str1, str2, n);
//     printf("ft_strncmp result (Test 1): %d\n", result1);

//     int result2 = ft_strncmp(str1, str3, n);
//     printf("ft_strncmp result (Test 2): %d\n", result2);

//     int result3 = ft_strncmp(str1, str3, 20);
//     printf("ft_strncmp result (Test 3): %d\n", result3);

//     int std_result1 = strncmp(str1, str2, n);
//     int std_result2 = strncmp(str1, str3, n);
//     int std_result3 = strncmp(str1, str3, 20);

//     printf("Standard strncmp result (Test 1): %d\n", std_result1);
//     printf("Standard strncmp result (Test 2): %d\n", std_result2);
//     printf("Standard strncmp result (Test 3): %d\n", std_result3);

//     return 0;
// }