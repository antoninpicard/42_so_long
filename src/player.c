/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucnavar <lucnavar@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/28 12:23:31 by anpicard          #+#    #+#             */
/*   Updated: 2025/03/03 12:28:21 by lucnavar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	is_valid_move(t_game *game, int x, int y)
{
	char	next_pos;

	if (x < 0 || x >= game->map.width || y < 0 || y >= game->map.height)
		return (0);
	next_pos = game->map.grid[y][x];
	if (next_pos == '1')
		return (0);
	return (1);
}

static void	load_victory_frames(t_game *game, void **flag_frames, char **frame_paths, int *dims)
{
	int	i;

	i = 0;
	while (i < 12)
	{
		flag_frames[i] = mlx_xpm_file_to_image(game->mlx, frame_paths[i], &dims[0], &dims[1]);
		if (!flag_frames[i])
		{
			while (--i >= 0)
				mlx_destroy_image(game->mlx, flag_frames[i]);
			free(flag_frames);
			return ;
		}
		i++;
	}
}

static void	init_victory_paths(char **frame_paths)
{
	frame_paths[0] = "textures/flag/frame_1";
	frame_paths[1] = "textures/flag/frame_2";
	frame_paths[2] = "textures/flag/frame_3";
	frame_paths[3] = "textures/flag/frame_4";
	frame_paths[4] = "textures/flag/frame_5";
	frame_paths[5] = "textures/flag/frame_6";
	frame_paths[6] = "textures/flag/frame_7";
	frame_paths[7] = "textures/flag/frame_8";
	frame_paths[8] = "textures/flag/frame_9";
	frame_paths[9] = "textures/flag/frame_10";
	frame_paths[10] = "textures/flag/frame_11";
	frame_paths[11] = "textures/flag/frame_12";
	frame_paths[12] = NULL;
}

static void	play_victory_animation(t_game *game, void **flag_frames, int *dims)
{
	int	i;
	int	frame_count;
	int	window_width;
	int	window_height;

	window_width = game->map.width * TILE_SIZE;
	window_height = game->map.height * TILE_SIZE;
	frame_count = 0;
	while (frame_count < 60)
	{
		i = frame_count % 12;
		mlx_clear_window(game->mlx, game->win);
		mlx_put_image_to_window(game->mlx, game->win, flag_frames[i], 
			(window_width - dims[0]) / 2, (window_height - dims[1]) / 2);
		mlx_do_sync(game->mlx);
		usleep(83333);
		frame_count++;
	}
}

static void	display_victory_flag(t_game *game)
{
	void	**flag_frames;
	char	*frame_paths[13];
	int		dims[2];
	int		i;

	init_victory_paths(frame_paths);
	flag_frames = malloc(sizeof(void *) * 12);
	if (!flag_frames)
		return ;
	load_victory_frames(game, flag_frames, frame_paths, dims);
	play_victory_animation(game, flag_frames, dims);
	i = 0;
	while (i < 12)
		mlx_destroy_image(game->mlx, flag_frames[i++]);
	free(flag_frames);
}

static void	handle_exit_position(t_game *game, int x, int y, char current)
{
	if (game->map.grid[game->map.player_y][game->map.player_x] == 'X')
		game->map.grid[game->map.player_y][game->map.player_x] = 'E';
	else
		game->map.grid[game->map.player_y][game->map.player_x] = '0';
	game->map.player_x = x;
	game->map.player_y = y;
	if (current == 'E')
	{
		game->map.grid[y][x] = 'X';
		ft_printf("\nYou need to collect all items first! Remaining: %d\n",
			game->map.collectibles);
	}
	else
		game->map.grid[y][x] = 'P';
}

static void	update_move_player(t_game *game, int x, int y)
{
	char	current;

	current = game->map.grid[y][x];
	if (current == 'C')
		game->map.collectibles--;
	if (current == 'E' && game->map.collectibles == 0)
	{
		game->moves++;
		ft_printf("\nCongratulations! You won in %d moves!\n", game->moves);
		game->map.grid[game->map.player_y][game->map.player_x] = '0';
		game->map.player_x = -1;
		game->map.player_y = -1;
		render_map(game);
		display_victory_flag(game);
		cleanup_game(game);
		exit(0);
	}
	handle_exit_position(game, x, y, current);
	game->moves++;
	ft_printf("Moves: %d\n", game->moves);
	render_map(game);
}

int	handle_keypress(int keycode, t_game *game)
{
	int	new_x;
	int	new_y;

	if (keycode == XK_Escape)
	{
		cleanup_game(game);
		exit(0);
	}
	new_x = game->map.player_x;
	new_y = game->map.player_y;
	if (keycode == XK_w || keycode == XK_Up)
		new_y--;
	if (keycode == XK_s || keycode == XK_Down)
		new_y++;
	if (keycode == XK_a || keycode == XK_Left)
		new_x--;
	if (keycode == XK_d || keycode == XK_Right)
		new_x++;
	if (is_valid_move(game, new_x, new_y))
		update_move_player(game, new_x, new_y);
	return (0);
}
