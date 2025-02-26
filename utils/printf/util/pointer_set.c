/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pointer_set.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anpicard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 10:52:27 by anpicard          #+#    #+#             */
/*   Updated: 2024/11/15 15:56:37 by anpicard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_put_hex_digit_count(int digit)
{
	if (digit < 10)
		return (ft_putchar(digit + '0', 1));
	else
		return (ft_putchar(digit - 10 + 'a', 1));
}

static int	ft_put_address_count(unsigned long address)
{
	int	count;

	count = 0;
	if (address >= 16)
		count += ft_put_address_count(address / 16);
	count += ft_put_hex_digit_count(address % 16);
	return (count);
}

int	ft_put_pointer(void *ptr)
{
	int	count;

	count = 0;
	if (!ptr)
	{
		write(1, "(nil)", 5);
		return (5);
	}
	count += write(1, "0x", 2);
	count += ft_put_address_count((unsigned long)ptr);
	return (count);
}
