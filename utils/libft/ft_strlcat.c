/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anpicard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 11:03:06 by anpicard          #+#    #+#             */
/*   Updated: 2024/11/12 14:16:03 by anpicard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	size_dst;

	size_dst = ft_strlen(dst);
	i = 0;
	if (dstsize == 0 || dstsize <= size_dst)
		return (ft_strlen(src) + dstsize);
	while (src[i] && (i + size_dst + 1) < dstsize)
	{
		dst[size_dst + i] = src[i];
		i++;
	}
	dst[size_dst + i] = 0;
	return (ft_strlen(src) + size_dst);
}
