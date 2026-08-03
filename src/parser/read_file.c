/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ervsahin <ervsahin@student.42kocaeli.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/02 00:18:23 by ervsahin          #+#    #+#             */
/*   Updated: 2026/08/03 14:22:38 by ervsahin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "utils/get_next_line/get_next_line.h"
#include <stdlib.h>

void	read_file(int fd, t_game *game)
{
	char	*line;

	(void)game;
	line = get_next_line(fd);
	if (!line)
		print_error("Empty file.");
	while (line)
	{
		if (get_identifier(skip_whitespace(line)) != 0)
			parse_texture(line, game);
		if (get_color_identifier(skip_whitespace(line)) != 0)
			parse_color(line, game);
		free(line);
		line = get_next_line(fd);
	}
}
