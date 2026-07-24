/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_file.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ervsahin <ervsahin@student.42kocaeli.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/06 21:20:18 by ervsahin          #+#    #+#             */
/*   Updated: 2026/06/06 22:51:32 by ervsahin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"

int	count_lines(int fd)
{
	char	*line;
	int		count;

	count = 0;
	while (1)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		free(line);
		count++;
	}
	return (count);
}

int	parse_file(char *filename, t_map *map)
{
	int		fd;
	int		line_count;
	char	**lines;
	int		result;

	fd = open(filename, O_RDONLY);
	if (fd == -1)
		return (error_msg("Failed to open file!"));
	line_count = count_lines(fd);
	close(fd);
	fd = open(filename, O_RDONLY);
	if (fd == -1)
		return (error_msg("Failed to open file!"));
	lines = read_lines(fd, line_count);
	if (!lines)
	{
		close(fd);
		return (error_msg("Failed to read lines!"));
	}
	close(fd);
	result = process_lines(lines, map);
	free_lines(lines);
	return (result);
}

static int	process_line(char **lines, int i,
	t_map *map, int *map_started)
{
	if (lines[i][0] == '\n')
		return (*map_started && error_msg("Empty line in map!"));
	if (*map_started && is_element(lines[i]))
		return (error_msg("Elements after map!"));
	if (!*map_started && is_element(lines[i]))
		return (parse_identifier(lines[i], map));
	if (is_map_line(lines[i]))
	{
		*map_started = 1;
		return (parse_map(&lines[i], map));
	}
	return (error_msg("Invalid line!"));
}

int	process_lines(char **lines, t_map *map)
{
	int	i;
	int	map_started;

	if (!lines || !map)
		return (0);
	i = 0;
	map_started = 0;
	while (lines[i])
	{
		if (process_line(lines, i, map, &map_started) == -1)
			return (-1);
		i++;
	}
	if (!map_started)
		return (error_msg("No map found!"));
	return (0);
}
