/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ervsahin <ervsahin@student.42kocaeli.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/03 14:10:10 by ervsahin          #+#    #+#             */
/*   Updated: 2026/08/01 04:43:18 by ervsahin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>
#include "../cub3d.h"

int	main(int argc, char **argv)
{
	t_game	game;
	int		fd;

	(void)game;
	if (argc != 2)
	{
		print_error("invalid arguments!");
		return (1);
	}
	parser(&game, argv[1]);
	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
	{
		print_error("opening file failed!");
		return (1);
	}
	close(fd);
	return (0);
}