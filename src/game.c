/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anpicard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/28 10:33:13 by anpicard          #+#    #+#             */
/*   Updated: 2025/02/28 13:15:54 by anpicard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	load_images(t_game *game);

static void	put_image(t_game *game, void *img, int x, int y)
{
	mlx_put_image_to_window(game->mlx, game->win, img, x * TILE_SIZE, y
		* TILE_SIZE);
}

static void	render_tile(t_game *game, t_tile_images *imgs, int pos[2])
{
	if (!game || !game->img_ground || !game->img_wall || !imgs->player_ground
		|| !imgs->collect_ground || !imgs->exit_ground || !game->img_exit)
		return ;
	if (game->map.grid[pos[1]][pos[0]] == '0')
		put_image(game, game->img_ground, pos[0], pos[1]);
	else if (game->map.grid[pos[1]][pos[0]] == '1')
		put_image(game, game->img_wall, pos[0], pos[1]);
	else if (game->map.grid[pos[1]][pos[0]] == 'P')
		put_image(game, imgs->player_ground, pos[0], pos[1]);
	else if (game->map.grid[pos[1]][pos[0]] == 'C')
		put_image(game, imgs->collect_ground, pos[0], pos[1]);
	else if (game->map.grid[pos[1]][pos[0]] == 'E')
		put_image(game, imgs->exit_ground, pos[0], pos[1]);
}

int	render_map(t_game *game)
{
	int	pos[2];

	game->images.player_ground = create_transparent_image(game,
			game->img_ground, game->img_player);
	game->images.collect_ground = create_transparent_image(game,
			game->img_ground, game->img_collectible);
	game->images.exit_ground = create_transparent_image(game, game->img_ground,
			game->img_exit);
	if (!game->images.player_ground || !game->images.collect_ground
		|| !game->images.exit_ground)
		return (0);
	pos[1] = 0;
	while (pos[1] < game->map.height)
	{
		pos[0] = -1;
		while (++pos[0] < game->map.width)
			render_tile(game, &game->images, pos);
		pos[1]++;
	}
	mlx_destroy_image(game->mlx, game->images.player_ground);
	mlx_destroy_image(game->mlx, game->images.collect_ground);
	mlx_destroy_image(game->mlx, game->images.exit_ground);
	return (1);
}

int	init_game(t_game *game)
{
	ft_printf("Initializing MLX...\n");
	game->mlx = mlx_init();
	if (!game->mlx)
		return (print_error("Failed to initialize MLX"), 0);
	ft_printf("Creating window...\n");
	game->win = mlx_new_window(game->mlx, game->map.width * TILE_SIZE,
			game->map.height * TILE_SIZE, "so_long");
	if (!game->win)
		return (print_error("Failed to create window"), 0);
	game->moves = 0;
	game->collected = 0;
	ft_printf("Loading images..\n");
	if (!load_images(game))
	{
		print_error("Failed to load images");
		return (0);
	}
	ft_printf("Game initialized successfully\n");
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
	ft_printf("Loading exit image...\n");
	game->img_exit = mlx_xpm_file_to_image(game->mlx, "textures/exit.xpm",
			&width, &height);
	ft_printf("Loading ground image...\n");
	game->img_ground = mlx_xpm_file_to_image(game->mlx, "textures/ground.xpm",
			&width, &height);
	if (!game->img_player || !game->img_wall || !game->img_collectible
		|| !game->img_exit || !game->img_ground)
		return (0);
	return (1);
}
