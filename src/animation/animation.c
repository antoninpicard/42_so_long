/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animation.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucnavar <lucnavar@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/03 07:51:36 by anpicard          #+#    #+#             */
/*   Updated: 2025/03/03 13:07:59 by lucnavar         ###   ########.fr       */
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
    int x;
    int y;

    data = (t_game *)param;
    y = 0;
    while (y < data->map.height)
    {
        x = 0;
        while (x < data->map.width)
        {
            if (data->map.grid[y][x] == 'E')
            {
                mlx_put_image_to_window(data->mlx, data->win,
                    data->img[data->frame], x * TILE_SIZE, y * TILE_SIZE);
            }
            x++;
        }
        y++;
    }
    data->frame = (data->frame + 1) % data->frame_count;
    usleep(data->frame_delay);
    return (0);
}

void init_animation(t_game *data, int frame_count,
        int frame_delay, char **frames)
{
    int i;

    data->frame = 0;
    data->frame_count = frame_count;
    data->frame_delay = frame_delay;
    data->img = malloc(sizeof(void *) * frame_count);
    if (!data->img)
    {
        write(2, "Error: Failed to allocate memory for images\n", 44);
        exit(1);
    }
    i = 0;
    while (i < frame_count)
    {
        ft_printf("Loading frame %d: %s\n", i + 1, frames[i]);
        data->img[i] = mlx_xpm_file_to_image(data->mlx, frames[i],
                &(int){0}, &(int){0});
        if (!data->img[i])
        {
            ft_printf("Error: Failed to load frame %d\n", i + 1);
            while (--i >= 0)
                mlx_destroy_image(data->mlx, data->img[i]);
            free(data->img);
            data->img = NULL;
            return ;
        }
        i++;
    }
    mlx_loop_hook(data->mlx, animate, data);
}
