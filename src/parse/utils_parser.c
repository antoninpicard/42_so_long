/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_parser.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anpicard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/28 11:21:47 by anpicard          #+#    #+#             */
/*   Updated: 2025/02/28 12:37:08 by anpicard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	free_map_grid(char ***grid, int height)
{
	int	i;

	if (!(*grid))
		return ;
	i = 0;
	while (i < height)
	{
		free((*grid)[i]);
		(*grid)[i] = NULL;
		i++;
	}
	free(*grid);
	*grid = NULL;
}

void	cleanup_gnl(int fd)
{
	char	*tmp;

	tmp = get_next_line(fd);
	while (tmp)
	{
		free(tmp);
		tmp = get_next_line(fd);
	}
}

int	check_extra_lines(t_map *map, int fd)
{
	char	*line;

	line = get_next_line(fd);
	if (line)
	{
		free(line);
		free_map_grid(&map->grid, map->height);
		close(fd);
		return (0);
	}
	return (1);
}

void	check_file_extension(char *map_path)
{
	if (!ft_strrchr(map_path, '.') || ft_strncmp(ft_strrchr(map_path, '.'),
			".ber", 4) != 0)
	{
		print_error("Invalid file extension");
		exit(1);
	}
}
