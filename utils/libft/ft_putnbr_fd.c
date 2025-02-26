/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anpicard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 13:30:48 by anpicard          #+#    #+#             */
/*   Updated: 2024/11/11 16:56:22 by anpicard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	unsigned int	number;
	int				temp;

	if (n < 0)
	{
		ft_putchar_fd('-', fd);
		n = -n;
	}
	number = n;
	if (number > 9)
	{
		ft_putnbr_fd(number / 10, fd);
	}
	temp = (number % 10) + 48;
	write(fd, &temp, 1);
}
