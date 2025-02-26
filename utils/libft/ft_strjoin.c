/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anpicard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 11:03:09 by anpicard          #+#    #+#             */
/*   Updated: 2024/11/12 14:14:23 by anpicard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		i;
	int		y;
	int		size;
	char	*final_s;

	i = 0;
	y = 0;
	size = ft_strlen(s1) + ft_strlen(s2) + 1;
	final_s = malloc(sizeof(char) * size);
	if (!final_s)
		return (NULL);
	while (s1[y])
	{
		final_s[i] = s1[y];
		i++;
		y++;
	}
	y = 0;
	while (s2[y])
	{
		final_s[i] = s2[y++];
		i++;
	}
	final_s[i] = 0;
	return (final_s);
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
//     char *str1 = "Hello, ";
//     char *str2 = "World!";
//     char *result = ft_strjoin(str1, str2);

//     if (result)
//     {
//         printf("Joined string: %s\n", result);
//         free(result);
//     }
//     else
//     {
//         printf("Memory allocation failed\n");
//     }

//     return 0;
// }