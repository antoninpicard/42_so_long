/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anpicard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 12:11:04 by anpicard          #+#    #+#             */
/*   Updated: 2024/11/12 14:41:02 by anpicard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_striteri(char *s, void (*f)(unsigned int, char*))
{
	unsigned int	i;

	i = 0;
	while (s[i])
	{
		f(i, &s[i]);
		i++;
	}
}
// #include <stdio.h>

// void example_function(unsigned int index, char *character)
// {
//     if (character)
//         *character = *character - 32; 
// }

// int main()
// {
//     char str[] = "hello, world!";
//     printf("Before: %s\n", str);
//     ft_striteri(str, example_function);
//     printf("After: %s", str);

//     return 0;
// }