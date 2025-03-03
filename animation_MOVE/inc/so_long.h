#ifndef SO_LONG_H
# define SO_LONG_H

# include <mlx.h>
# include <stdlib.h>
# include <unistd.h>
# include <time.h> // Pour usleep

# define WINDOW_WIDTH 800
# define WINDOW_HEIGHT 600

typedef struct s_data
{
    void    *mlx;
    void    *win;
    void    **img;       // Tableau dynamique pour les images
    int     frame_count; // Nombre de frames
    int     frame;       // Frame actuelle
    int     frame_delay; // Délai entre les frames en microsecondes
} t_data;

// Fonctions
void    *load_image(void *mlx, char *path);
int     animate(void *param);
void	init_animation(t_data *data, int frame_count, int frame_delay, char **frames);
char 	**generate_frame_paths(const char *folder, int frame_count);
void	build_frame_path(char *buffer, const char *folder, int frame_number);

#endif