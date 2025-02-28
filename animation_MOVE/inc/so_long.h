#ifndef SO_LONG_H
# define SO_LONG_H

# include <mlx.h>
# include <stdlib.h>
# include <unistd.h>
# include <time.h>

# define WINDOW_WIDTH 800
# define WINDOW_HEIGHT 600
# define FRAME_COUNT 7
# define FRAME_DELAY 120000

typedef struct s_data
{
    void    *mlx;
    void    *win;
    void    *img[FRAME_COUNT];
    int     frame;
} t_data;

// Fonctions
void    *load_image(void *mlx, char *path);
int     animate(void *param);
void    init_animation(t_data *data);

#endif