/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ervsahin <ervsahin@student.42kocaeli.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/06 21:22:32 by ervsahin          #+#    #+#             */
/*   Updated: 2026/06/06 22:50:38 by ervsahin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"

char	**read_lines(int fd, int line_count)
{
	char	**lines;
	char	*line;
	int		i;

	lines = malloc(sizeof(char *) * (line_count + 1));
	if (!lines)
		return (NULL);
	i = 0;
	while (i < line_count)
	{
		line = get_next_line(fd);
		if (!line)
		{
			while (i > 0)
				free(lines[--i]);
			free(lines);
			return (NULL);
		}
		lines[i++] = line;
	}
	lines[i] = NULL;
	return (lines);
}

void	free_lines(char **lines)
{
	int	i;

	if (!lines)
		return ;
	i = 0;
	while (lines[i])
		free(lines[i++]);
	free(lines);
}

int	is_element(char *line)
{
	if (!line || !*line)
		return (0);
	if ((strncmp(line, "NO", 2) == 0 && (line[2] == ' ' || line[2] == '\t')) ||
		(strncmp(line, "SO", 2) == 0 && (line[2] == ' ' || line[2] == '\t')) ||
		(strncmp(line, "WE", 2) == 0 && (line[2] == ' ' || line[2] == '\t')) ||
		(strncmp(line, "EA", 2) == 0 && (line[2] == ' ' || line[2] == '\t')) ||
		(line[0] == 'F' && (line[1] == ' ' || line[1] == '\t')) ||
		(line[0] == 'C' && (line[1] == ' ' || line[1] == '\t')))
		return (1);
	return (0);
}

int	is_map_line(char *line)
{
	int	i;

	if (!line || !*line || line[0] == '\n')
		return (0);
	i = 0;
	while (line[i] == ' ' || line[i] == '\t')
		i++;
	if (line[i] == '0' || line[i] == '1')
		return (1);
	return (0);
}

int	error_msg(char *msg)
{
	write(2, "Error\n", 6);
	write(2, msg, strlen(msg));
	write(2, "\n", 1);
	return (-1);
}
