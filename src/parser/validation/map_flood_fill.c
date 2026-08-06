/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_flood_fill.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ervsahin <ervsahin@student.42kocaeli.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/04 18:00:00 by ervsahin          #+#    #+#             */
/*   Updated: 2026/08/04 18:00:00 by ervsahin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "libft.h"
#include <stdlib.h>

static char	**copy_map(t_game *game)
{
	char	**copy;
	int		i;

	copy = malloc(sizeof(char *) * (game->map.height + 1));
	if (!copy)
		print_error("Malloc failed.");
	i = -1;
	while (++i < game->map.height)
	{
		copy[i] = ft_strdup(game->map.grid[i]);
		if (!copy[i])
		{
			free_map(copy, i);
			print_error("Malloc failed.");
		}
	}
	copy[game->map.height] = NULL;
	return (copy);
}

static void	flood_fill(t_flood *f, int x, int y)
{
	if (x < 0 || y < 0 || x >= f->width || y >= f->height)
	{
		f->closed = 0;
		return ;
	}
	if (f->map[y][x] == '1' || f->map[y][x] == 'F')
		return ;
	if (f->map[y][x] == ' ')
	{
		f->closed = 0;
		return ;
	}
	f->map[y][x] = 'F';
	flood_fill(f, x + 1, y);
	flood_fill(f, x - 1, y);
	flood_fill(f, x, y + 1);
	flood_fill(f, x, y - 1);
}

static void	check_unreachable(char **copy, t_game *game)
{
	int	i;
	int	j;

	i = -1;
	while (++i < game->map.height)
	{
		j = -1;
		while (++j < game->map.width)
		{
			if (copy[i][j] != 'F' && copy[i][j] != '1'
				&& copy[i][j] != ' ')
			{
				free_map(copy, game->map.height);
				print_error("Map has unreachable areas.");
			}
		}
	}
}

void	validate_map_enclosed(t_game *game)
{
	char	**copy;
	t_flood	f;

	copy = copy_map(game);
	f.map = copy;
	f.width = game->map.width;
	f.height = game->map.height;
	f.closed = 1;
	flood_fill(&f, game->player.x, game->player.y);
	if (!f.closed)
	{
		free_map(copy, game->map.height);
		print_error("Map not enclosed by walls.");
	}
	check_unreachable(copy, game);
	free_map(copy, game->map.height);
}
