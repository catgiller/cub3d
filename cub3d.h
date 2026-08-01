#ifndef CUB3D_H
# define CUB3D_H

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
	t_mlx		mlx;
}	t_game;

void	print_error(char *message);
int		check_file_extension(char *file_name);
void	parser(t_game *game, char *file);

#endif