/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anpicard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 11:03:22 by anpicard          #+#    #+#             */
/*   Updated: 2024/11/14 09:07:33 by anpicard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	size_t	i;

	if (!dest && !src && n)
		return (NULL);
	if (dest < src)
	{
		i = 0;
		while (i < n)
		{
			*(unsigned char *)(dest + i) = *(unsigned char *)(src + i);
			i++;
		}
	}
	else
	{
		i = n;
		while (i > 0)
		{
			i--;
			*(unsigned char *)(dest + i) = *(unsigned char *)(src + i);
		}
	}
	return (dest);
}
// #include <stdio.h>
// #include <string.h>

// int main()
// {
//     char str1[] = "Overlap Example";
//     char str2[] = "Overlap Example";

//     ft_memmove(str1 + 5, str1, 7);
//     printf("ft_memmove result: %s\n", str1);

//     memmove(str2 + 5, str2, 7);
//     printf("Standard memmove result: %s\n", str2);

//     char src[] = "Hello, World!";
//     char dest1[50];
//     char dest2[50];

//     ft_memmove(dest1, src, strlen(src) + 1);
//     memmove(dest2, src, strlen(src) + 1);

//     printf("ft_memmove result without overlap: %s\n", dest1);
//     printf("Standard memmove result without overlap: %s\n", dest2);

//     return 0;
// }
