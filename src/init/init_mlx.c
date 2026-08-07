/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_mlx.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ervsahin <ervsahin@student.42kocaeli.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/07 18:55:00 by ervsahin          #+#    #+#             */
/*   Updated: 2026/08/07 18:55:00 by ervsahin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include <stdlib.h>

int	close_game(t_game *game)
{
	free_game(game);
	exit(0);
	return (0);
}

int	handle_keypress(int keycode, t_game *game)
{
	if (keycode == KEY_ESC)
		close_game(game);
	else if (keycode == KEY_W)
		move_forward(game);
	else if (keycode == KEY_S)
		move_backward(game);
	else if (keycode == KEY_A)
		move_left(game);
	else if (keycode == KEY_D)
		move_right(game);
	else if (keycode == KEY_LEFT)
		rotate_left(game);
	else if (keycode == KEY_RIGHT)
		rotate_right(game);
	return (0);
}

void	init_mlx(t_game *game)
{
	game->mlx.mlx = mlx_init();
	if (!game->mlx.mlx)
		print_error("Failed to initialize MiniLibX!");
	game->mlx.win = mlx_new_window(game->mlx.mlx, WIN_WIDTH,
			WIN_HEIGHT, "cub3D");
	if (!game->mlx.win)
		print_error("Failed to create window!");
	game->mlx.img.img = mlx_new_image(game->mlx.mlx, WIN_WIDTH, WIN_HEIGHT);
	if (!game->mlx.img.img)
		print_error("Failed to create MLX image!");
	game->mlx.img.addr = mlx_get_data_addr(game->mlx.img.img,
			&game->mlx.img.bpp, &game->mlx.img.line_len,
			&game->mlx.img.endian);
	load_textures(game);
	mlx_hook(game->mlx.win, 17, 0, close_game, game);
	mlx_hook(game->mlx.win, 2, 1L << 0, handle_keypress, game);
	mlx_loop_hook(game->mlx.mlx, render_frame, game);
}
