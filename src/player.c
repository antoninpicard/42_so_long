/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anpicard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/28 12:23:31 by anpicard          #+#    #+#             */
/*   Updated: 2025/02/28 12:23:45 by anpicard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	is_valid_move(t_game *game, int new_x, int new_y)
{
	char	next_pos;

	next_pos = game->map.grid[new_y][new_x];
	if (next_pos == '1')
		return (0);
	return (1);
}

static void	update_move_player(t_game *game, int new_x, int new_y)
{
	char	current_pos;

	current_pos = game->map.grid[new_y][new_x];
	if (current_pos == 'C')
		game->collected++;
	else if (current_pos == 'E' && (game->collected == game->map.collectibles))
	{
		game->moves++;
		ft_printf("You won in %d moves!\n", game->moves);
		close_window(game);
	}
	if (game->map.last_move == 'E')
		game->map.grid[game->map.player_pos.y][game->map.player_pos.x] = 'E';
	else
		game->map.grid[game->map.player_pos.y][game->map.player_pos.x] = '0';
	game->map.player_pos.x = new_x;
	game->map.player_pos.y = new_y;
	game->map.last_move = game->map.grid[new_y][new_x];
	game->map.grid[new_y][new_x] = 'P';
	game->moves++;
}

int	move_player(t_game *game, int keycode)
{
	int	new_x;
	int	new_y;

	new_x = game->map.player_pos.x;
	new_y = game->map.player_pos.y;
	if (keycode == W || keycode == ARROW_UP)
		new_y--;
	else if (keycode == A || keycode == ARROW_LEFT)
		new_x--;
	else if (keycode == S || keycode == ARROW_DOWN)
		new_y++;
	else if (keycode == D || keycode == ARROW_RIGHT)
		new_x++;
	if (is_valid_move(game, new_x, new_y))
	{
		update_move_player(game, new_x, new_y);
		ft_printf("Moves: %d\n", game->moves);
		render_map(game);
	}
	return (0);
}
