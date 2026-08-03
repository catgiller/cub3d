/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ervsahin <ervsahin@student.42kocaeli.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/03 14:21:47 by ervsahin          #+#    #+#             */
/*   Updated: 2026/08/03 14:30:49 by ervsahin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# define NO_ID	1
# define SO_ID	2
# define WE_ID	3
# define EA_ID	4
# define FLOOR_ID 5
# define CEILING_ID 6

typedef struct s_map
{
	char	**grid;
	int		width;
	int		height;
}	t_map;

typedef struct s_textures
{
	char	*no;
	char	*so;
	char	*we;
	char	*ea;
}	t_textures;

typedef struct s_player
{
	int		x;
	int		y;
	char	dir;
}	t_player;

typedef struct s_color
{
	int		r;
	int		g;
	int		b;
}	t_color;

typedef struct s_mlx
{
	void	*mlx;
	void	*win;
}	t_mlx;

typedef struct s_game
{
	t_map		map;
	t_textures	textures;
	t_player	player;
	t_color		floor;
	t_color		ceiling;
	int			floor_set;
	int			ceiling_set;
	t_mlx		mlx;
}	t_game;

void	print_error(char *message);
int		check_file_extension(char *file_name);
void	parser(t_game *game, char *file);
void	read_file(int fd, t_game *game);
char	*extract_path(char *line);
char	*skip_whitespace(char *line);
int		get_identifier(char *line);
int		parse_texture(char *line, t_game *game);
int		store_texture(t_game *game, int id, char *path);
int		check_texture_file(char *path);
int		read_number(char **line, int *value);
void	init_game(t_game *game);
int		get_color_identifier(char *line);
int		parse_color(char *line, t_game *game);
int		store_color(t_game *game, int id, t_color color);
int		extract_rgb(char *line, t_color *color);
int		read_number(char **line, int *value);

#endif