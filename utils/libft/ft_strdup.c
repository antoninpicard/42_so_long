/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anpicard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 11:03:12 by anpicard          #+#    #+#             */
/*   Updated: 2024/11/12 14:12:33 by anpicard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(char *src)
{
	char	*str;
	int		i;

	i = 0;
	str = malloc(sizeof(char) * ft_strlen(src) + 1);
	if (str)
	{
		while (src[i])
		{
			str[i] = src[i];
			i++;
		}
		str[i] = 0;
		return (str);
	}
	return (0);
}
// #include <stdio.h>
// #include <stdlib.h>
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
//     char *original = "Hello, World!";
//     char *duplicate = ft_strdup(original);

//     if (duplicate)
//     {
//         printf("Original: %s\n", original);
//         printf("Duplicate: %s\n", duplicate);
//     }
//     else
//     {
//         printf("Memory allocation failed\n");
//     }

//     // Libérer la mémoire allouée
//     free(duplicate);

//     return 0;
// }