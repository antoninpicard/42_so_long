/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anpicard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 14:09:33 by anpicard          #+#    #+#             */
/*   Updated: 2025/03/03 10:11:59 by anpicard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	key_hook(int keycode, t_game *game)
{
	if (keycode == ESC)
		close_window(game);
	else if (keycode == W || keycode == A || keycode == S || keycode == D)
		move_player(game, keycode);
	else if (keycode == ARROW_DOWN || keycode == ARROW_LEFT
		|| keycode == ARROW_RIGHT || keycode == ARROW_UP)
		move_player(game, keycode);
	return (0);
}

int	main(int argc, char **argv)
{
	t_game	game;

	(void)argv;
	if (argc != 2)
		return (print_error("Usage: ./so_long [map_path]"), 1);
	ft_memset(&game, 0, sizeof(t_game));
	if (!parse_map(&game.map, argv[1]))
		return (1);
	if (!init_game(&game))
		return (cleanup_game(&game), 1);
	render_map(&game);
	mlx_hook(game.win, 17, 0, close_window, &game);
	mlx_key_hook(game.win, key_hook, &game);
	mlx_loop(game.mlx);
	return (0);
}
