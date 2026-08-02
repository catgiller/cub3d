/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ervsahin <ervsahin@student.42kocaeli.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/02 13:24:11 by ervsahin          #+#    #+#             */
/*   Updated: 2026/08/02 13:24:43 by ervsahin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include <stdlib.h>

void	init_game(t_game *game)
{
	game->textures.no = NULL;
	game->textures.so = NULL;
	game->textures.we = NULL;
	game->textures.ea = NULL;
	game->map.grid = NULL;
	game->map.width = 0;
	game->map.height = 0;
	game->player.x = 0;
	game->player.y = 0;
	game->player.dir = '\0';
	game->floor.r = 0;
	game->floor.g = 0;
	game->floor.b = 0;
	game->ceiling.r = 0;
	game->ceiling.g = 0;
	game->ceiling.b = 0;
	game->floor_set = 0;
	game->ceiling_set = 0;
	game->mlx.mlx = NULL;
	game->mlx.win = NULL;
}
