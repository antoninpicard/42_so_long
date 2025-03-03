/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucnavar <lucnavar@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/28 10:33:13 by anpicard          #+#    #+#             */
/*   Updated: 2025/03/03 10:43:00 by lucnavar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

# define FRAME_COUNT 7
# define FRAME_DELAY 150000
# define PORTAL_FRAMES (char *[]){"textures/portal/frame_1.xpm", \
	"textures/portal/frame_2.xpm", "textures/portal/frame_3.xpm", \
	"textures/portal/frame_4.xpm", "textures/portal/frame_5.xpm", \
	"textures/portal/frame_6.xpm", "textures/portal/frame_7.xpm", NULL}

void	put_image(t_game *game, void *img, int x, int y)
{
	mlx_put_image_to_window(game->mlx, game->win, img, x * TILE_SIZE, y
		* TILE_SIZE);
}

static int	load_images(t_game *game);

static int	init_player_position(t_game *game)
{
	int	x;
	int	y;

	y = 0;
	while (y < game->map.height)
	{
		x = 0;
		while (x < game->map.width)
		{
			if (game->map.grid[y][x] == 'P')
			{
				game->map.player_x = x;
				game->map.player_y = y;
				return (1);
			}
			x++;
		}
		y++;
	}
	return (0);
}

int	render_map(t_game *game)
{
	int	pos[2];

	pos[1] = 0;
	while (pos[1] < game->map.height)
	{
		pos[0] = 0;
		while (pos[0] < game->map.width)
		{
			if (game->map.grid[pos[1]][pos[0]] == '1')
				put_image(game, game->img_wall, pos[0], pos[1]);
			else
			{
				put_image(game, game->img_ground, pos[0], pos[1]);
				if (game->map.grid[pos[1]][pos[0]] == 'E')
					put_image(game, game->img_exit, pos[0], pos[1]);
				if (game->map.grid[pos[1]][pos[0]] == 'C')
					put_image(game, game->img_collectible, pos[0], pos[1]);
				if (game->map.grid[pos[1]][pos[0]] == 'P' || 
					game->map.grid[pos[1]][pos[0]] == 'X')
					put_image(game, game->img_player, pos[0], pos[1]);
			}
			pos[0]++;
		}
		pos[1]++;
	}
	return (1);
}

int	init_game(t_game *game)
{
	char	**portal_frames;

	game->mlx = mlx_init();
	if (!game->mlx)
		return (0);
	game->win = mlx_new_window(game->mlx, game->map.width * TILE_SIZE,
			game->map.height * TILE_SIZE, "so_long");
	if (!game->win)
		return (0);
	if (!load_images(game))
		return (0);
	game->moves = 0;
	game->is_exiting = 0;
	if (!init_player_position(game))
		return (0);
	ft_printf("Loading portal frames...\n");
	portal_frames = PORTAL_FRAMES;
	init_animation(game, FRAME_COUNT, FRAME_DELAY, portal_frames);
	ft_printf("Game initialized successfully\n");
	render_map(game);
	return (1);
}

static int	load_images(t_game *game)
{
	int	width;
	int	height;

	ft_printf("Loading player image...\n");
	game->img_player = mlx_xpm_file_to_image(game->mlx, "textures/car.xpm",
			&width, &height);
	ft_printf("Loading wall image...\n");
	game->img_wall = mlx_xpm_file_to_image(game->mlx, "textures/wall.xpm",
			&width, &height);
	ft_printf("Loading collectible image...\n");
	game->img_collectible = mlx_xpm_file_to_image(game->mlx,
			"textures/collectible.xpm", &width, &height);
	ft_printf("Loading ground image...\n");
	game->img_ground = mlx_xpm_file_to_image(game->mlx, "textures/ground.xpm",
			&width, &height);
	ft_printf("Loading exit image...\n");
	game->img_exit = mlx_xpm_file_to_image(game->mlx, "textures/portal/frame_1.xpm",
			&width, &height);
	if (!game->img_player || !game->img_wall || !game->img_collectible
		|| !game->img_ground || !game->img_exit)
		return (0);
	return (1);
}
