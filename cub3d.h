/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jseidere <jseidere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/24 12:24:55 by jseidere          #+#    #+#             */
/*   Updated: 2024/07/17 12:29:16 by jseidere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <mlx.h>
# include <stdio.h>
# include <math.h>
# include <stdlib.h>
# include <string.h>
# include <stdbool.h>
# include "get_next_line.h"
# include "libft/libft.h"
# include <unistd.h>
# include <fcntl.h>
# include <sys/time.h>

////////////////////////////////////////////
///////////////////MACROS//////////////////
//////////////////////////////////////////

# define WINDOW_WIDTH 800
# define WINDOW_HEIGHT 600
# define NUM_TEXTURES 4
# define FOV 60
# define X 0
# define Y 1
# define HEIGHT 1
# define FLOOR 0
# define WALL 1
# define DOOR 2
# define NORTH 0
# define SOUTH 1
# define WEST 2
# define EAST 3
# define PLAYERPOS "NSWE"

//Keys

# define W 119
# define A 97
# define S 115
# define D 100
# define E 101
# define ESC 65307
# define ARROWUP 65362
# define ARROWDOWN 65364
# define ARROWLEFT 65361
# define ARROWRIGHT 65363

////////////////////////////////////////////
//////////////////STRUCTS//////////////////
//////////////////////////////////////////

typedef struct s_texture
{
	void	*img;
	char	*addr;
	char	*path;
	int		height;
	int		width;
}	t_texture;

typedef struct s_raycast
{
	int				pos_x; // current x or y player
	int				pos_y;
	double			dir_x; // ray direction
	double			dir_y;
	double			side_dist_x; // distance between player and next x or y
	double			side_dist_y;
	double			delta_x; // distance between two x or y
	double			delta_y;
	double			perp_wall_dist;
	int				step_x; // -1 or 1
	int				step_y;
	int				hit;
	int				side; // 0 = NS, 1 = EW
	int				line_height;
	int				line_start;
	int				line_end;
	double			plane_x;
	t_texture		texture;
	unsigned int	color;
//	double	plane_y;
}	t_raycast;

typedef struct s_player
{
	double	x;
	double	y;
	double	dir_x;
	double	dir_y;
	double	time;
	double	old_time;
}	t_player;

typedef struct s_game
{
	void		*mlx;
	void		*win;
	void		*img;
	void		*addr;
	int			bits_per_pixel;
	int			line_length;
	int			endian;
	int			map_param;
	t_texture	texture[NUM_TEXTURES]; //N, S, E, W
	t_player	player;
	t_raycast	raycast;
	int			fd;
	int			rows;
	char		**map;
	int			player_amount;
}	t_game;

////////////////////////////////////////////
/////////////////FUNCTIONS/////////////////
//////////////////////////////////////////

//cub3d.c

//init.c
void	init_var(t_game *game);
int		init_window(t_game *cub);
void	init_texture(t_game *game);
int		init_img(t_game *game);

//check_file.c
bool	right_fileextension(char *file);
int		check_file(t_game *game, char *argv);
void	get_rows(t_game *game);

//map_checker.c
bool	only_allowed_chars(char *str);
bool	only_walls(char *str);
bool	check_row(t_game *game, char **map);
bool	check_surr(t_game *game, int y, int x);
bool	check_pos(t_game *game);

//map_utils_check.c
bool	check_texture(t_game *game, char *str);
bool	check_attributes(t_game *game);
bool	valid_texture(t_game *game, char *path, char *dir);
bool	is_dir(char *str);
bool	is_fc(char *str);

//norm_map.c
int		len_until_sc(char *str, char c);
char	*norm_line(char *str);
void	norm_map(t_game *game);
bool	is_empty(char *str);

//read_map.c
int		check_for_newline(char *str);
void	double_free(char *s1, char *s2, int fd, t_game *game);
void	single_free(char *s1, t_game *game);
char	*get_map_temp(t_game *game, char *map_temp, int fd);
void	init_map(t_game *game, char *argv);

//free.c
int		ft_error(char *str, t_game *game);
int		free_map(char **map);

//utils.c
int		print_td_array(char **str);
bool	skip_spaces(char *str, int *j);
void	count_player(t_game *game, char *str);
//free.c
void	free_all(t_game *cub);
void	destroy_mlx(t_game *cub);
int		free_success(t_game *game);

//raycaster_1.c
void	determine_texture(t_game *cub, t_raycast *r);
void	my_mlx_pixel_put(t_game *cub, int x, int y, unsigned int color);
void	draw_line(t_game *cub, int x, t_raycast *r);
void	raycaster(t_game *cub);

//raycaster_2.c
void	init_ray_struct(t_game *cub, t_raycast *r, int i);
void	get_side_dist(t_raycast *r);
void	calculate_dist(t_raycast *r, char **map);
void	calculate_height(t_raycast *r);

#endif