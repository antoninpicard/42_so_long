/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anpicard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 14:03:17 by anpicard          #+#    #+#             */
/*   Updated: 2025/02/26 14:09:22 by anpicard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <stdlib.h>
# include <unistd.h>
# include "../minilibx-linux/mlx.h"
# include "../utils/inc/libft.h"
# include "../utils/inc/ft_printf.h"

/* Window settings */
# define WINDOW_WIDTH 800
# define WINDOW_HEIGHT 600
# define WINDOW_TITLE "so_long"

/* Key codes */
# define KEY_ESC 65307

/* Function prototypes */
int	close_window(void *param);
int	handle_keypress(int keycode, void *param);

#endif