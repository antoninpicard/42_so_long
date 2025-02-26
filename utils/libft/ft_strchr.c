/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anpicard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 11:03:14 by anpicard          #+#    #+#             */
/*   Updated: 2024/11/14 09:07:11 by anpicard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	int	i;

	i = -1;
	while (++i, s[i])
	{
		if (s[i] == (unsigned char)c)
			return ((char *)s + i);
	}
	if ((unsigned char)c == '\0')
		return ((char *)s + i);
	return (0);
}
// #include <stdio.h>
// #include <string.h>

// int main()
// {
//     const char *str = "Hello, World!";

//     char *result1 = ft_strchr(str, 'W');
//     if (result1)
//         printf("Character 'W' found at position: %ld\n", result1 - str);
//     else
//         printf("Character 'W' not found\n");

//     char *result2 = ft_strchr(str, 'z');
//     if (result2)
//         printf("Character 'z' found at position: %ld\n", result2 - str);
//     else
//         printf("Character 'z' not found\n");

//     char *result3 = ft_strchr(str, '\0');
//     if (result3)
//         printf("Null character found at position: %ld\n", result3 - str);
//     else
//         printf("Null character not found\n");

//     return 0;
// }