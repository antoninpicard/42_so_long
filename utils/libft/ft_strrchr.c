/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anpicard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 11:02:53 by anpicard          #+#    #+#             */
/*   Updated: 2024/11/14 09:06:22 by anpicard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int	i;
	int	p;

	i = -1;
	p = -1;
	while (++i, s[i])
	{
		if (s[i] == (unsigned char)c)
			p = i;
	}
	if ((unsigned char)c == '\0')
		return ((char *)s + i);
	if (p == -1)
		return (0);
	return ((char *)s + p);
}

// #include <stdio.h>
// #include <string.h>

// int main()
// {
//     const char *str = "Hello, World!";
//     char c1 = 'o';
//     char c2 = 'z';
//     char c3 = '\0';

//     char *result1 = ft_strrchr(str, c1);
//     if (result1)
//         printf("Last occurrence of '%c' found at position: %ld\n",
//				 c1, result1 - str);
//     else
//         printf("Character '%c' not found\n", c1);

//     char *result2 = ft_strrchr(str, c2);
//     if (result2)
//         printf("Last occurrence of '%c' found at position: %ld\n",
//				 c2, result2 - str);
//     else
//         printf("Character '%c' not found\n", c2);

//     char *result3 = ft_strrchr(str, c3);
//     if (result3)
//         printf("Null character found at position: %ld\n", result3
//				 - str);
//     else
//         printf("Null character not found\n");

//     return 0;
// }