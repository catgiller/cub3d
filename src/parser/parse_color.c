/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_color.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ervsahin <ervsahin@student.42kocaeli.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/02 10:13:17 by ervsahin          #+#    #+#             */
/*   Updated: 2026/08/03 14:22:36 by ervsahin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "utils/libft/libft.h"

int	read_number(char **line, int *value)
{
	if (!ft_isdigit(**line))
		return (0);
	*value = ft_atoi(*line);
	if (*value < 0 || *value > 255)
		return (0);
	while (ft_isdigit(**line))
		(*line)++;
	return (1);
}

int	extract_rgb(char *line, t_color *color)
{
	line = skip_whitespace(line);
	line++;
	line = skip_whitespace(line);
	if (!read_number(&line, &color->r))
		return (0);
	if (*line != ',')
		return (0);
	line++;
	if (!read_number(&line, &color->g))
		return (0);
	if (*line != ',')
		return (0);
	line++;
	if (!read_number(&line, &color->b))
		return (0);
	line = skip_whitespace(line);
	if (*line != '\0' && *line != '\n')
		return (0);
	return (1);
}

int	get_color_identifier(char *line)
{
	if (!ft_strncmp(line, "F", 1)
		&& (line[1] == ' ' || line[1] == '\t'))
		return (FLOOR_ID);
	else if (!ft_strncmp(line, "C", 1)
		&& (line[1] == ' ' || line[1] == '\t'))
		return (CEILING_ID);
	return (0);
}

int	store_color(t_game *game, int id, t_color color)
{
	if (id == FLOOR_ID && game->floor_set == 0)
	{
		game->floor = color;
		game->floor_set = 1;
	}
	else if (id == CEILING_ID && game->ceiling_set == 0)
	{
		game->ceiling = color;
		game->ceiling_set = 1;
	}
	else
	{
		print_error("Invalid color configuration.");
		return (0);
	}
	return (1);
}

int	parse_color(char *line, t_game *game)
{
	int		id;
	t_color	color;

	id = 0;
	line = skip_whitespace(line);
	id = get_color_identifier(line);
	if (id == 0)
	{
		print_error("i m blind");
		return (0);
	}
	if (!extract_rgb(line, &color))
	{
		print_error("did you miss something on the color?");
		return (0);
	}
	if (!store_color(game, id, color))
		return (0);
	return (1);
}
