/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parser.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anpicard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/28 08:27:53 by anpicard          #+#    #+#             */
/*   Updated: 2025/02/28 12:55:07 by anpicard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	get_map_height(char *map_path)
{
	int		fd;
	int		height;
	char	*line;

	fd = open(map_path, O_RDONLY);
	if (fd < 0)
		return (-1);
	height = 0;
	line = get_next_line(fd);
	while (line)
	{
		height++;
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
	return (height);
}

static int	check_map_line(char *line, t_map *map, int y)
{
	int	x;

	x = 0;
	while (line[x] && line[x] != '\n')
	{
		if (!ft_strchr("01CEP", line[x]))
			return (0);
		if (line[x] == 'C')
			map->collectibles++;
		else if (line[x] == 'E')
			map->exit++;
		else if (line[x] == 'P')
		{
			map->player++;
			map->player_pos.x = x;
			map->player_pos.y = y;
		}
		x++;
	}
	if (y == 0)
		map->width = x;
	return (x == map->width);
}

static int	read_line(t_map *map, int fd, int y)
{
	char	*line;

	line = get_next_line(fd);
	if (!line || !check_map_line(line, map, y))
	{
		free(line);
		cleanup_gnl(fd);
		free_map_grid(&map->grid, y);
		close(fd);
		return (0);
	}
	map->grid[y] = line;
	return (1);
}

int	read_map_lines(t_map *map, int fd)
{
	int		y;
	char	*extra_lines;

	y = 0;
	while (y < map->height)
	{
		if (!read_line(map, fd, y))
			return (0);
		y++;
	}
	extra_lines = get_next_line(fd);
	if (extra_lines != NULL)
	{
		free(extra_lines);
		free_map_grid(&map->grid, map->height);
		close(fd);
		return (0);
	}
	close(fd);
	return (1);
}

int	parse_map(t_map *map, char *map_path)
{
	check_file_extension(map_path);
	ft_memset(map, 0, sizeof(t_map));
	if (!init_map(map, map_path))
	{
		print_error("Invalid map format");
		free_map_grid(&map->grid, map->height);
		return (0);
	}
	if (map->collectibles < 1 || map->exit != 1 || map->player != 1)
	{
		print_error("Invalid map elements");
		free_map_grid(&map->grid, map->height);
		return (0);
	}
	if (!validate_path(map))
	{
		print_error("Invalid map : No path to exit or collectibles");
		free_map_grid(&map->grid, map->height);
		return (0);
	}
	return (1);
}
