#include "so_long.h"

void    *load_image(void *mlx, char *path)
{
    int width;
    int height;

    return (mlx_xpm_file_to_image(mlx, path, &width, &height));
}

int animate(void *param)
{
    t_data *data;

    data = (t_data *)param;
    mlx_clear_window(data->mlx, data->win);
    mlx_put_image_to_window(data->mlx, data->win, data->img[data->frame], 0, 0);
    data->frame = (data->frame + 1) % FRAME_COUNT;
    usleep(FRAME_DELAY);
    return (0);
}

void init_animation(t_data *data)
{
    char    *frames[FRAME_COUNT] = {
        "textures/frame_1.xpm",
        "textures/frame_2.xpm",
        "textures/frame_3.xpm",
        "textures/frame_4.xpm",
        "textures/frame_5.xpm",
        "textures/frame_6.xpm",
        "textures/frame_7.xpm"
    };
    int i;

    i = 0;
    while (i < FRAME_COUNT)
    {
        data->img[i] = load_image(data->mlx, frames[i]);
        i++;
    }
    data->frame = 0;
}