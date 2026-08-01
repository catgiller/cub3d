/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_texture.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ervsahin <ervsahin@student.42kocaeli.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/01 14:46:26 by ervsahin          #+#    #+#             */
/*   Updated: 2026/08/01 20:05:26 by ervsahin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "libft.h"

#define NO_ID   1
#define SO_ID   2
#define WE_ID   3
#define EA_ID   4

int	get_identifier(char *line)
{
	if (!ft_strncmp(line, "NO", 2)
		&& (line[2] == ' ' || line[2] == '\t'))
		return (NO_ID);
	else if (!ft_strncmp(line, "SO", 2)
		&& (line[2] == ' ' || line[2] == '\t'))
		return (SO_ID);
	else if (!ft_strncmp(line, "WE", 2)
		&& (line[2] == ' ' || line[2] == '\t'))
		return (WE_ID);
	else if (!ft_strncmp(line, "EA", 2)
		&& (line[2] == ' ' || line[2] == '\t'))
		return (EA_ID);
	return (0);
}

int	parse_texture(char *line, t_game *game)
{
	int		id;

	id = 0;
	line = skip_whitespace(line);
	id = get_idenfitier(line);
	if (id == 1)
		game->textures.no = extract_path(line);
	else if (id == 2)
		game->textures.so = extract_path(line);
	else if (id == 3)
		game->textures.we = extract_path(line);
	else if (id == 4)
		game->textures.ea = extract_path(line);
	else
	{
		print_error("Invalid texture identifier.");
		return (0);
	}
	return (1);
}
