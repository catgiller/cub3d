/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ervsahin <ervsahin@student.42kocaeli.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/03 14:10:10 by ervsahin          #+#    #+#             */
/*   Updated: 2026/06/06 22:33:14 by ervsahin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>

/* ==================== DATA STRUCTURES ==================== */

typedef struct s_map
{
	char	*no_texture;
	char	*so_texture;
	char	*we_texture;
	char	*ea_texture;
	int		floor_color;
	int		ceiling_color;
	char	**grid;
	int		width;
	int		height;
	int		player_x;
	int		player_y;
	char	player_dir;
}	t_map;

/* ==================== PARSING FUNCTIONS ==================== */

/* parse_file.c */
int		parse_file(char *filename, t_map *map);
int		process_lines(char **lines, t_map *map);

/* parse_utils.c */
char	**read_lines(int fd, int line_count);
void	free_lines(char **lines);
int		is_element(char *line);
int		is_map_line(char *line);
int		is_empty_line(char *line);
int		error_msg(char *msg);

/* parse_elements.c */
int		parse_identifier(char *line, t_map *map);
int		parse_color(char *line, int *color);
int		parse_texture(char *line, char **texture);

/* parse_map.c */
int		parse_map(char **lines, t_map *map);

/* ==================== VALIDATION FUNCTIONS ==================== */

/* val_element.c */
int		validate_elements(t_map *map);

/* val_map.c */
int		validate_map_chars(t_map *map);

/* val_flood.c */
int		validate_map_closed(t_map *map);

/* ==================== UTILITY FUNCTIONS ==================== */

/* General utilities */
void	free_map(t_map *map);

/* get_next_line functions */
char	*get_next_line(int fd);
size_t	ft_strlen(char *s);
char	*ft_strjoin(char *s1, char *s2);
char	*ft_strchr(char *s, int c);
char	*ft_substr(char *s, unsigned int start, size_t len);
size_t	ft_strlcpy(char *dst, char *src, size_t dstsize);

#endif