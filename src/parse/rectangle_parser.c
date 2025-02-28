/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rectangle_parser.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anpicard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/28 11:01:44 by anpicard          #+#    #+#             */
/*   Updated: 2025/02/28 11:01:56 by anpicard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	check_wall_x(t_map *map, int y)
{
	int	x;

	x = 0;
	while (x < map->width)
	{
		if (map->grid[y][x] != '1')
			return (0);
		x++;
	}
	return (1);
}

static int	check_wall_y(t_map *map, int x)
{
	int	y;

	y = 0;
	while (y < map->height)
	{
		if (map->grid[y][x] != '1')
			return (0);
		y++;
	}
	return (1);
}

int	check_rectangle(t_map *map)
{
	if (map->height == map->width)
		return (0);
	if (!check_wall_x(map, 0))
		return (0);
	if (!check_wall_x(map, map->height - 1))
		return (0);
	if (!check_wall_y(map, 0))
		return (0);
	if (!check_wall_y(map, map->width - 1))
		return (0);
	return (1);
}
