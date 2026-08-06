/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ervsahin <ervsahin@student.42kocaeli.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/04 18:00:00 by ervsahin          #+#    #+#             */
/*   Updated: 2026/08/04 18:00:00 by ervsahin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include <stdlib.h>

void	free_game(t_game *game)
{
	if (game->textures.no)
		free(game->textures.no);
	if (game->textures.so)
		free(game->textures.so);
	if (game->textures.we)
		free(game->textures.we);
	if (game->textures.ea)
		free(game->textures.ea);
	if (game->map.grid)
		free_map(game->map.grid, game->map.height);
}
