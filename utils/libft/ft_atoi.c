/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anpicard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 11:03:51 by anpicard          #+#    #+#             */
/*   Updated: 2025/02/16 10:49:48 by anpicard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *str)
{
	size_t		i;
	int			sign;
	long int	result;

	i = 0;
	sign = 1;
	result = 0;
	while ((str[i] >= '\t' && str[i] <= '\r') || str[i] == ' ')
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		if ((result * 10 + str[i] - '0') / 10 == result)
			result = result * 10 + str[i] - '0';
		else
			return ((sign < 0) * LONG_MIN + (sign > 0) * LONG_MAX);
		i++;
	}
	return (result * sign);
}

// #include <stdio.h>
// int    main()
// {
// char int_min[] = "-2147483648";
// char int_max[] = "2147483647";
// char long_min[] = "-9223372036854775808";
// char long_max[] = "9223372036854775807";
//     printf("atoi : %d\n", atoi(long_max));
//     printf("ft_atoi : %d", ft_atoi(long_max));
// }
