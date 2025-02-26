/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_hex.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anpicard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 13:47:37 by anpicard          #+#    #+#             */
/*   Updated: 2024/11/16 16:32:32 by anpicard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_printf.h"

static int	ft_count(uintptr_t nb)
{
	int	count;

	count = 1;
	while (nb >= 16)
	{
		nb = nb / 16;
		count++;
	}
	return (count);
}

char	*ft_itoa_hex(uintptr_t nb, char *base)
{
	char	*new_s;
	int		count;

	count = ft_count(nb);
	new_s = (char *)ft_calloc(count + 1, sizeof(char));
	if (!new_s)
		return (NULL);
	while (count--)
	{
		new_s[count] = base[nb % 16];
		nb = nb / 16;
	}
	return (new_s);
}

int	ft_convert_hex(unsigned int nb, int uppercase)
{
	char	*new_s;
	int		count;

	if (uppercase)
		new_s = ft_itoa_hex((unsigned int)nb, "0123456789ABCDEF");
	else
		new_s = ft_itoa_hex((unsigned int)nb, "0123456789abcdef");
	if (!new_s)
		return (0);
	count = ft_putstr(new_s, 1);
	free(new_s);
	return (count);
}
