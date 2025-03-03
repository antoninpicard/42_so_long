/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   build_path.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anpicard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/03 07:48:48 by anpicard          #+#    #+#             */
/*   Updated: 2025/03/03 08:08:15 by anpicard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void    my_itoa(int num, char *str)
{
    int     i;
    int     j;
    char    temp[10];

    i = 0;
    if (num == 0)
        str[i++] = '0';
    while (num > 0)
    {
        temp[i++] = (num % 10) + '0';
        num /= 10;
    }
    j = 0;
    while (j < i)
    {
        str[j] = temp[i - j - 1];
        j++;
    }
    str[j] = '\0';
}

void    build_frame_path(char *buffer, const char *folder, int frame_number)
{
    char    frame_str[10];

    ft_strcpy(buffer, "textures/");
    ft_strcat(buffer, folder);
    ft_strcat(buffer, "/frame_");
    my_itoa(frame_number, frame_str);
    ft_strcat(buffer, frame_str);
    ft_strcat(buffer, ".xpm");
}