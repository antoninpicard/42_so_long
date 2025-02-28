#include "so_long.h"

int main(void)
{
    t_data data;

    data.mlx = mlx_init();
    if (!data.mlx)
        return (1);
    data.win = mlx_new_window(data.mlx, WINDOW_WIDTH, WINDOW_HEIGHT, "Animation");
    if (!data.win)
        return (1);

    init_animation(&data);
    mlx_loop_hook(data.mlx, animate, &data);
    mlx_loop(data.mlx);

    return (0);
}