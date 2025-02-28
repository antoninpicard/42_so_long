/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anpicard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/28 12:22:24 by anpicard          #+#    #+#             */
/*   Updated: 2025/02/28 12:22:45 by anpicard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static char	**copy_map_grid(char **grid, int height)
{
	char	**copy;
	int		i;

	copy = malloc(sizeof(char *) * (height + 1));
	if (!copy)
		return (NULL);
	i = 0;
	while (i < height)
	{
		copy[i] = ft_strdup(grid[i]);
		if (!copy[i])
		{
			free_map_grid(&copy, i);
			return (NULL);
		}
		i++;
	}
	return (copy);
}

static void	flood_fill(char **grid, int x, int y, t_validation *val)
{
	if (grid[y][x] == '1' || grid[y][x] == 'V')
		return ;
	if (grid[y][x] == 'C')
		val->collectibles++;
	else if (grid[y][x] == 'E')
		val->exit_found = 1;
	grid[y][x] = 'V';
	flood_fill(grid, x + 1, y, val);
	flood_fill(grid, x - 1, y, val);
	flood_fill(grid, x, y + 1, val);
	flood_fill(grid, x, y - 1, val);
}

int	validate_path(t_map *map)
{
	char			**temp_grid;
	t_validation	val;

	temp_grid = copy_map_grid(map->grid, map->height);
	if (!temp_grid)
		return (0);
	val.collectibles = 0;
	val.exit_found = 0;
	flood_fill(temp_grid, map->player_pos.x, map->player_pos.y, &val);
	free_map_grid(&temp_grid, map->height);
	return (val.collectibles == map->collectibles && val.exit_found);
}
