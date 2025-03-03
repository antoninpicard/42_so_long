#include "../inc/so_long.h"
#include <stdio.h>

char    **generate_frame_paths(const char *folder, int frame_count)
{
    char    **frames;
    int     i;

    frames = (char **)malloc(sizeof(char *) * frame_count);
    if (!frames)
    {
        write(2, "Error: Failed to allocate memory for frame paths\n", 46);
        exit(1);
    }
    i = 0;
    while (i < frame_count)
    {
        frames[i] = (char *)malloc(100);
        if (!frames[i])
        {
            write(2, "Error: Failed to allocate memory for frame path\n", 45);
            exit(1);
        }
        build_frame_path(frames[i], folder, i + 1);
        i++;
    }
    return (frames);
}

int main(void)
{
    t_data  data;
    char    **frames;
    int     frame_count;
    int     i;

    frame_count = 7;
    frames = generate_frame_paths("portal", 7);
    data.mlx = mlx_init();
    if (!data.mlx)
        return (1);
    data.win = mlx_new_window(data.mlx, WINDOW_WIDTH,
            WINDOW_HEIGHT, "Animation");
    if (!data.win)
        return (1);
    init_animation(&data, frame_count, 100000, frames);
    mlx_loop_hook(data.mlx, animate, &data);
    mlx_loop(data.mlx);
    i = 0;
    while (i < frame_count)
        free(frames[i++]);
    free(frames);
    free(data.img);
    return (0);
}
