/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anpicard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 11:57:22 by anpicard          #+#    #+#             */
/*   Updated: 2024/11/12 14:19:21 by anpicard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	unsigned int	i;
	char			*new_s;

	i = 0;
	if (!s)
		return (NULL);
	new_s = (char *)malloc(sizeof(char) * (ft_strlen(s) + 1));
	if (!new_s)
		return (NULL);
	while (s[i])
	{
		new_s[i] = f(i, s[i]);
		i++;
	}
	new_s[i] = 0;
	return (new_s);
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

// char example_function(unsigned int index, char c)
// {
//     return c + index; // Exemple simple : ajoute l'index au caractère
// }

// int main()
// {
//     const char *original = "abcde";
//     char *new_string = ft_strmapi(original, example_function);

//     if (new_string)
//     {
//         printf("Original string: %s\n", original);
//         printf("Modified string: %s\n", new_string);
//         free(new_string);
//     }
//     else
//     {
//         printf("Memory allocation failed\n");
//     }

//     return 0;
// }