/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   transparent.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anpicard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/28 12:28:08 by anpicard          #+#    #+#             */
/*   Updated: 2025/02/28 12:32:31 by anpicard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	copy_pixel_data(char *new_data, char *fg_data, int i)
{
	new_data[i] = fg_data[i];
	new_data[i + 1] = fg_data[i + 1];
	new_data[i + 2] = fg_data[i + 2];
}

static void	process_image_data(char *new_data, char *bg_data, char *fg_data,
		int size)
{
	int	i;

	ft_memcpy(new_data, bg_data, size);
	i = 0;
	while (i < size)
	{
		if (fg_data[i] != 0 || fg_data[i + 1] != 0 || fg_data[i + 2] != 0)
			copy_pixel_data(new_data, fg_data, i);
		i += 4;
	}
}

void	*create_transparent_image(t_game *game, void *bg_img, void *fg_img)
{
	void	*new_img;
	char	*bg_data;
	char	*fg_data;
	char	*new_data;
	int		params[3];

	if (!bg_img || !fg_img)
		return (NULL);
	new_img = mlx_new_image(game->mlx, TILE_SIZE, TILE_SIZE);
	if (!new_img)
		return (NULL);
	bg_data = mlx_get_data_addr(bg_img, &params[0], &params[1], &params[2]);
	fg_data = mlx_get_data_addr(fg_img, &params[0], &params[1], &params[2]);
	new_data = mlx_get_data_addr(new_img, &params[0], &params[1], &params[2]);
	if (!bg_data || !fg_data || !new_data)
	{
		mlx_destroy_image(game->mlx, new_img);
		return (NULL);
	}
	process_image_data(new_data, bg_data, fg_data, TILE_SIZE * TILE_SIZE
		* (params[0] / 8));
	return (new_img);
}
