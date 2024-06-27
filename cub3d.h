/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caigner <caigner@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/24 12:24:55 by jseidere          #+#    #+#             */
/*   Updated: 2024/06/27 19:58:02 by caigner          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

#include "./libft/libft.h"
#include <mlx.h>
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/time.h>

////////////////////////////////////////////
//////////////////STRUCTS//////////////////
//////////////////////////////////////////

typedef struct s_map
{
	char    **map;
	char    **map_tmp;
	
}   t_map;

typedef struct s_raycast
{
	int		pos_x; // current x or y player
	int		pos_y;
	double	dir_x; // ray direction
	double	dir_y;
	double	side_dist_x; // distance between player and next x or y
	double	side_dist_y;
	double	delta_x; // distance between two x or y
	double	delta_y;
	double	perp_wall_dist;
	int		step_x; // -1 or 1
	int		step_y;
	int		hit;
	int		side; // 0 = NS, 1 = EW
	int		line_height;
	int		line_start;
	int		line_end;
} t_raycast;

typedef struct s_player
{
	double	x;
	double	y;
	double	dir_x;
	double	dir_y;
}	t_player;

typedef struct s_game
{
	void		*mlx;
	void		*win;
	int			fd;
	t_player	player;
	t_raycast	raycast;
}   t_game;

////////////////////////////////////////////
///////////////////MACROS//////////////////
//////////////////////////////////////////

# define FOV 60
# define X 0
# define Y 1
# define HEIGHT 1
# define FLOOR 0
# define WALL 1
# define DOOR 2

////////////////////////////////////////////
/////////////////FUNCTIONS/////////////////
//////////////////////////////////////////

//cub3d.c

//map_checker.c


#endif