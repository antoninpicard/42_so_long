/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anpicard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 15:49:05 by anpicard          #+#    #+#             */
/*   Updated: 2024/11/16 16:32:07 by anpicard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_printf.h"

int	ft_putchar(char c, int fd)
{
	ft_putchar_fd(c, fd);
	return (1);
}

int	ft_putstr(char *str, int fd)
{
	if (!str)
	{
		ft_putstr_fd("(null)", 1);
		return (6);
	}
	ft_putstr_fd(str, fd);
	return (ft_strlen(str));
}

int	ft_putnbr(long n, int fd)
{
	char	*str;
	int		len;

	str = ft_itoa(n);
	len = ft_putstr(str, fd);
	free(str);
	return (len);
}
