/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ervsahin <ervsahin@student.42kocaeli.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/03 14:10:10 by ervsahin          #+#    #+#             */
/*   Updated: 2026/06/06 21:44:55 by ervsahin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int	main(int argc, char **argv)
{
	t_map	map;
	int		fd;

	if (argc != 2)
	{
		error_msg("Usage: ./cub3D <map_file.cub>");
		return (1);
	}
	memset(&map, 0, sizeof(t_map));
	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
	{
		error_msg("Error: Could not open file");
		return (1);
	}
	close(fd);
	return (0);
}