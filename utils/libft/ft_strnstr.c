/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anpicard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 11:02:56 by anpicard          #+#    #+#             */
/*   Updated: 2024/11/14 09:06:30 by anpicard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	x;
	size_t	len_little;

	len_little = ft_strlen(little);
	i = 0;
	if (!big && !little && len)
		return (NULL);
	if (len_little == 0)
		return ((char *) big);
	while (big[i] && i < len)
	{
		x = 0;
		while (big[i + x] && big[i + x] == little[x] && i + x < len)
			x++;
		if (x == len_little)
			return ((char *) big + i);
		i++;
	}
	return (NULL);
}

// #include <stdio.h>
// #include <string.h>

// size_t ft_strlen(const char *s)
// {
//     size_t len = 0;
//     while (s[len])
//         len++;
//     return len;
// }

// int main()
// {
//     const char *big = "Hello, World!";
//     const char *little1 = "World";
//     const char *little2 = "Universe";
//     const char *little3 = "";
//     size_t len = 13;

//     char *result1 = ft_strnstr(big, little1, len);
//     if (result1)
//         printf("Found '%s' in '%s' at position: %ld\n", little1, 
//				big, result1 - big);
//     else
//         printf("'%s' not found in '%s'\n", little1, big);
//				

//     char *result2 = ft_strnstr(big, little2, len);
//     if (result2)
//         printf("Found '%s' in '%s'\n", little2, big);
//     else
//         printf("'%s' not found in '%s'\n", little2, big);

//     char *result3 = ft_strnstr(big, little3, len);
//     if (result3)
//         printf("Found empty string in '%s' at position: %ld\n", 
//				big, result3 - big);
//     else
//         printf("Empty string not found in '%s'\n", big);

//     char *result4 = ft_strnstr(big, little1, 5);
//     if (result4)
//         printf("Found '%s' in '%s' within length 5\n", little1, big);
//     else
//         printf("'%s' not found in '%s' within length 5\n", little1, big);

//     return 0;
// }