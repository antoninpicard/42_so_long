/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anpicard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 14:09:33 by anpicard          #+#    #+#             */
/*   Updated: 2025/02/28 09:24:55 by anpicard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	close_window(void *param)
{
	(void)param;
	ft_printf("Closing window...\n");
	exit(0);
	return (0);
}

int	handle_keypress(int keycode, void *param)
{
	(void)param;
	if (keycode == KEY_ESC)
	{
		ft_printf("ESC key pressed, closing window...\n");
		exit(0);
	}
	return (0);
}

int	main(int argc, char **argv)
{
	t_game	game;

	if (argc != 2)
		return (print_error("Usage: ./so_long [map_path]"), 1);
	return (1);
}
