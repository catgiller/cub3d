#ifndef CUB3D_H
# define CUB3D_H

#define NO_ID   1
#define SO_ID   2
#define WE_ID   3
#define EA_ID   4

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
void	read_file(int fd, t_game *game);
char	*extract_path(char *line);
char	*skip_whitespace(char *line);
int		get_idenfitier(char *line);
int		parse_texture(char *line, t_game *game);
int		store_texture(t_game *game, int id, char *path);
int		check_texture_file(char *path);

#endif