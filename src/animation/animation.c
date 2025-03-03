/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animation.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anpicard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/03 07:51:36 by anpicard          #+#    #+#             */
/*   Updated: 2025/03/03 08:11:43 by anpicard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

void    *load_image(void *mlx, char *path)
{
    int width;
    int height;
    void *img;

    img = mlx_xpm_file_to_image(mlx, path, &width, &height);
    if (!img)
    {
        write(2, "Error: Failed to load image\n", 28);
        return (NULL);
    }
    return (img);
}

int animate(void *param)
{
    t_game *data;

    data = (t_game *)param;
    mlx_clear_window(data->mlx, data->win);
    mlx_put_image_to_window(data->mlx, data->win,
        data->img[data->frame], 0, 0);
    data->frame = (data->frame + 1) % data->frame_count;
    usleep(data->frame_delay);
    return (0);
}

void init_animation(t_game *data, int frame_count,
        int frame_delay, char **frames)
{
    int i;

    data->img = (void **)malloc(sizeof(void *) * frame_count);
    if (!data->img)
    {
        write(2, "Error: Failed to allocate memory for images\n", 44);
        exit(1);
    }
    i = 0;
    while (i < frame_count)
    {
        data->img[i] = load_image(data->mlx, frames[i]);
        if (!data->img[i])
        {
            write(2, "Error: Failed to load image\n", 28);
            exit(1);
        }
        i++;
    }
    data->frame_count = frame_count;
    data->frame_delay = frame_delay;
    data->frame = 0;
}