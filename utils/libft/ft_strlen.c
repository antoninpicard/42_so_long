/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anpicard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 11:03:01 by anpicard          #+#    #+#             */
/*   Updated: 2024/11/11 16:06:41 by anpicard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

/*
#include <stdio.h>
int	main(int ac, char **av)
{
	(void)ac;
	if (ac != 2)
		return (1);
	printf("Size: %zu\n", ft_strlen(av[1]));
	printf("size: %lu\n", sizeof(size_t));
	2147483647 + 1
	-2147483648
}*/
