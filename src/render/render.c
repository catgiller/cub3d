/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ervsahin <ervsahin@student.42kocaeli.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/07 19:05:00 by ervsahin          #+#    #+#             */
/*   Updated: 2026/08/07 19:05:00 by ervsahin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	my_mlx_pixel_put(t_img *img, int x, int y, int color)
{
	char	*dst;

	if (x < 0 || x >= WIN_WIDTH || y < 0 || y >= WIN_HEIGHT)
		return ;
	dst = img->addr + (y * img->line_len + x * (img->bpp / 8));
	*(unsigned int *)dst = color;
}

static int	encode_rgb(t_color color)
{
	return ((color.r << 16) | (color.g << 8) | color.b);
}

static void	draw_background(t_game *game)
{
	int	x;
	int	y;
	int	c_color;
	int	f_color;

	c_color = encode_rgb(game->ceiling);
	f_color = encode_rgb(game->floor);
	y = 0;
	while (y < WIN_HEIGHT / 2)
	{
		x = 0;
		while (x < WIN_WIDTH)
			my_mlx_pixel_put(&game->mlx.img, x++, y, c_color);
		y++;
	}
	while (y < WIN_HEIGHT)
	{
		x = 0;
		while (x < WIN_WIDTH)
			my_mlx_pixel_put(&game->mlx.img, x++, y, f_color);
		y++;
	}
}

static unsigned int	get_tex_color(t_tex *tex, int x, int y)
{
	char	*pixel;

	if (x < 0 || x >= tex->width || y < 0 || y >= tex->height)
		return (0);
	pixel = tex->addr + (y * tex->line_len + x * (tex->bpp / 8));
	return (*(unsigned int *)pixel);
}

void	draw_wall_stripe(t_game *game, t_ray *ray, int x)
{
	int		y;
	int		tex_y;
	double	step;
	double	tex_pos;

	step = 1.0 * game->tex[ray->tex_id].height / ray->line_height;
	tex_pos = (ray->draw_start - WIN_HEIGHT / 2 + ray->line_height / 2) * step;
	y = ray->draw_start;
	while (y <= ray->draw_end)
	{
		tex_y = (int)tex_pos & (game->tex[ray->tex_id].height - 1);
		tex_pos += step;
		my_mlx_pixel_put(&game->mlx.img, x, y,
			get_tex_color(&game->tex[ray->tex_id], ray->tex_x, tex_y));
		y++;
	}
}

int	render_frame(void *param)
{
	t_game	*game;

	game = (t_game *)param;
	draw_background(game);
	cast_rays(game);
	draw_minimap(game);
	mlx_put_image_to_window(game->mlx.mlx, game->mlx.win,
		game->mlx.img.img, 0, 0);
	return (0);
}
