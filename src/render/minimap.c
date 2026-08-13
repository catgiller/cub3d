/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ervsahin <ervsahin@student.42kocaeli.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/12 00:00:00 by ervsahin          #+#    #+#             */
/*   Updated: 2026/08/12 00:00:00 by ervsahin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	get_cell_color(char cell)
{
	if (cell == '1')
		return (0x555555);
	if (cell == '0' || cell == 'N' || cell == 'S' || cell == 'E' || cell == 'W')
		return (0xBBBBBB);
	return (0x333333);
}

static void	draw_cell(t_game *game, int cx, int cy, int color)
{
	int	x;
	int	y;
	int	px;
	int	py;

	y = 0;
	while (y < MINIMAP_CELL)
	{
		x = 0;
		while (x < MINIMAP_CELL)
		{
			px = cx * MINIMAP_CELL + x + MINIMAP_OFF_X;
			py = cy * MINIMAP_CELL + y + MINIMAP_OFF_Y;
			my_mlx_pixel_put(&game->mlx.img, px, py, color);
			x++;
		}
		y++;
	}
}

static void	draw_grid(t_game *game, int half)
{
	int	dy;
	int	dx;
	int	mx;
	int	my;
	int	c;

	dy = -half;
	while (dy <= half)
	{
		dx = -half;
		while (dx <= half)
		{
			mx = (int)game->player.pos_x + dx;
			my = (int)game->player.pos_y + dy;
			c = 0;
			if (my >= 0 && my < game->map.height
				&& mx >= 0 && mx < game->map.width)
				c = game->map.grid[my][mx];
			draw_cell(game, dx + half, dy + half, get_cell_color(c));
			dx++;
		}
		dy++;
	}
}

static void	draw_dir_line(t_game *game, int half)
{
	int		px;
	int		py;
	double	dx;
	double	dy;
	double	t;

	px = half * MINIMAP_CELL + MINIMAP_OFF_X + MINIMAP_CELL / 2;
	py = half * MINIMAP_CELL + MINIMAP_OFF_Y + MINIMAP_CELL / 2;
	dx = game->player.dir_x;
	dy = game->player.dir_y;
	t = 0;
	while (t < MINIMAP_CELL * 1.2)
	{
		my_mlx_pixel_put(&game->mlx.img,
			px + (int)(dx * t), py + (int)(dy * t), 0xFF4444);
		t += 0.3;
	}
}

void	draw_minimap(t_game *game)
{
	int	cx;
	int	cy;
	int	r;
	int	y;
	int	x;

	draw_grid(game, MINIMAP_RADIUS);
	draw_dir_line(game, MINIMAP_RADIUS);
	cx = MINIMAP_RADIUS * MINIMAP_CELL + MINIMAP_OFF_X + MINIMAP_CELL / 2;
	cy = MINIMAP_RADIUS * MINIMAP_CELL + MINIMAP_OFF_Y + MINIMAP_CELL / 2;
	r = MINIMAP_CELL / 3;
	y = -r;
	while (y <= r)
	{
		x = -r;
		while (x <= r)
		{
			if (x * x + y * y <= r * r)
				my_mlx_pixel_put(&game->mlx.img,
					cx + x, cy + y, 0xFF2222);
			x++;
		}
		y++;
	}
}
