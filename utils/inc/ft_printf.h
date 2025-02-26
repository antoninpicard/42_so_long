/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anpicard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 11:25:38 by anpicard          #+#    #+#             */
/*   Updated: 2024/11/16 16:33:52 by anpicard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdint.h>
# include <unistd.h>

int	ft_printf(const char *format, ...);
int	ft_putchar(char c, int fd);
int	ft_putstr(char *str, int fd);
int	ft_putnbr(long n, int fd);
int	ft_put_pointer(void *ptr);
int	ft_convert_hex(unsigned int nb, int uppercase);

#endif