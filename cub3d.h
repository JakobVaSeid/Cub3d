/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caigner <caigner@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/24 12:24:55 by jseidere          #+#    #+#             */
/*   Updated: 2024/07/01 17:28:02 by caigner          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "./libft/libft.h"
# include <mlx.h>
# include <stdio.h>
# include <math.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>
# include <fcntl.h>
# include <sys/time.h>

////////////////////////////////////////////
//////////////////STRUCTS//////////////////
//////////////////////////////////////////

typedef struct s_map
{
	char	**map;
	char	**map_tmp;
}	t_map;

typedef struct s_texture
{
	void	*img;
	char	*addr;
	int		height;
	int		length;
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
	int			fd;
	t_texture	texture[4]; //N, S, E, W
	t_map		map;
	t_player	player;
	t_raycast	raycast;
}	t_game;

////////////////////////////////////////////
///////////////////MACROS//////////////////
//////////////////////////////////////////

# define WINDOW_WIDTH 800
# define WINDOW_HEIGHT 600
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

////////////////////////////////////////////
/////////////////FUNCTIONS/////////////////
//////////////////////////////////////////

//cub3d.c

//map_checker.c

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