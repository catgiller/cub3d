/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ervsahin <ervsahin@student.42kocaeli.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/01 01:16:12 by ervsahin          #+#    #+#             */
/*   Updated: 2026/08/01 02:40:28 by ervsahin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"
#include "../../libft/libft.h"
#include "../get_next_line/get_next_line.h"
#include <fcntl.h>

static int	check_file_extension(char *file_name)
{
	int	len;

	len = ft_strlen(file_name);
	if (len < 4)
		return (0);
	if (ft_strncmp(&file_name[len - 4], ".cub", 4) != 0)
		return (0);
	return (1);
}

int read_file(int fd)
{
    int	fd;
    char *line;

    while (line != NULL)
	{
		free(line);
		line = get_next_line(fd);
        return(0);
	}
    close(fd);
    return(1);
}

void	parser(t_game *game, char *file)
{
    int fd;
    char *line;
	(void)game;

	fd = 0;
	if (!check_file_extension(file))
		print_error("Invalid file extension.");
	fd = open(file, O_RDONLY);
	if (fd == -1)
		print_error("opening file failed!");
    line = get_next_line(fd);
    read_file(fd);

}