/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anpicard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 14:03:17 by anpicard          #+#    #+#             */
/*   Updated: 2025/02/28 09:21:56 by anpicard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../minilibx-linux/mlx.h"
# include "../utils/includes/libft.h"
# include "../utils/includes/ft_printf.h"
# include "../utils/includes/get_next_line.h"
# include <stdlib.h>
# include <unistd.h>

# define WINDOW_WIDTH 800
# define WINDOW_HEIGHT 600
# define WINDOW_TITLE "so_long"

# define KEY_ESC 65307 // ESC

typedef struct s_game
{
	void	*mlx;
	void	*win;
}			t_game;

int			close_window(void *param);
int			handle_keypress(int keycode, void *param);
void		print_error(char *message);

#endif