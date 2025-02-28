/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anpicard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 14:03:17 by anpicard          #+#    #+#             */
/*   Updated: 2025/02/28 12:33:34 by anpicard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../minilibx-linux/mlx.h"
# include "../utils/includes/ft_printf.h"
# include "../utils/includes/get_next_line.h"
# include "../utils/includes/libft.h"
# include <X11/keysym.h>
# include <fcntl.h>
# include <stdlib.h>
# include <unistd.h>

# define TILE_SIZE 64
# define MAX_HEIGHT 31
# define MAX_WIDTH 59
# define ESC XK_Escape
# define W XK_w
# define A XK_a
# define S XK_s
# define D XK_d
# define L XK_l
# define ARROW_RIGHT XK_Right
# define ARROW_LEFT XK_Left
# define ARROW_UP XK_Up
# define ARROW_DOWN XK_Down

typedef struct s_position
{
	int				x;
	int				y;
}					t_position;

typedef struct s_map
{
	char			**grid;
	int				width;
	int				height;
	int				collectibles;
	int				exit;
	int				player;
	t_position		player_pos;
	char			last_move;
}					t_map;

typedef struct s_tile_images
{
	void			*player_ground;
	void			*collect_ground;
	void			*exit_ground;
}					t_tile_images;

typedef struct s_game
{
	void			*mlx;
	void			*win;
	void			*img_player;
	void			*img_wall;
	void			*img_ground;
	void			*img_collectible;
	void			*img_exit;
	t_map			map;
	t_tile_images	images;
	int				moves;
	int				collected;
}					t_game;

typedef struct s_validation
{
	int				collectibles;
	int				exit_found;
}					t_validation;

int					init_map(t_map *map, char *map_path);
void				free_map_grid(char ***grid, int height);
void				cleanup_gnl(int fd);
int					check_extra_lines(t_map *map, int fd);
int					parse_map(t_map *map, char *map_path);
int					get_map_height(char *map_path);
int					read_map_lines(t_map *map, int fd);
void				check_file_extension(char *map_path);
int					check_rectangle(t_map *map);
int					validate_path(t_map *map);
void				print_error(char *message);
void				cleanup_game(t_game *game);
int					close_window(t_game *game);
int					init_game(t_game *game);
int					render_map(t_game *game);
int					move_player(t_game *game, int keycode);
void				*create_transparent_image(t_game *game, void *bg_img,
						void *fg_img);

#endif