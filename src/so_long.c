/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anpicard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 14:09:33 by anpicard          #+#    #+#             */
/*   Updated: 2025/02/26 14:59:45 by anpicard         ###   ########.fr       */
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

int	main(void)
{
	void	*mlx;
	void	*win;

	mlx = mlx_init();
	if (!mlx)
		return (1);
	win = mlx_new_window(mlx, WINDOW_WIDTH, WINDOW_HEIGHT, WINDOW_TITLE);
	if (!win)
	{
		mlx_destroy_display(mlx);
		free(mlx);
		return (1);
	}
	ft_printf("Window created successfully!\n");
	mlx_hook(win, 17, 0, close_window, NULL);
	mlx_hook(win, 2, 1L<<0, handle_keypress, NULL);
	mlx_loop(mlx);
	return (0);
}
