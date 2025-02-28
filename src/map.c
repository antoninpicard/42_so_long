/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anpicard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/28 12:23:06 by anpicard          #+#    #+#             */
/*   Updated: 2025/02/28 12:54:38 by anpicard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	init_map(t_map *map, char *map_path)
{
	int	fd;

	map->height = get_map_height(map_path);
	if (map->height <= 0)
		return (0);
	map->grid = ft_calloc(map->height, sizeof(char *));
	if (!map->grid)
		return (0);
	fd = open(map_path, O_RDONLY);
	if (fd < 0)
		return (0);
	if (!read_map_lines(map, fd))
		return (0);
	if (!check_rectangle(map))
		return (0);
	if (map->width > MAX_WIDTH || map->height > MAX_HEIGHT)
		return (0);
	return (1);
}
