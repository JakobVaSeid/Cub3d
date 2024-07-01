/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jseidere <jseidere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/24 12:24:55 by jseidere          #+#    #+#             */
/*   Updated: 2024/06/28 12:08:07 by jseidere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

#include <mlx.h>
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "get_next_line/get_next_line.h"
#include "libft/libft.h"

////////////////////////////////////////////
//////////////////STRUCTS//////////////////
//////////////////////////////////////////

typedef struct s_map
{
    char    **map;
    char    **map_tmp;
    int     rows;
}   t_map;

typedef struct s_game
{
    int     fd;
    char    **map;
    //t_map   *map;
}   t_game;

////////////////////////////////////////////
///////////////////MACROS//////////////////
//////////////////////////////////////////

# define PLAYERPOS "NSWE"


////////////////////////////////////////////
/////////////////FUNCTIONS/////////////////
//////////////////////////////////////////

//cub3d.c

//map_checker.c
bool    right_fileextension(char *file);
int     check_map(t_game *game, char *argv);

//read_map.c
int     check_for_newline(char *str);
void	double_free(char *s1, char *s2, int fd, t_game *game);
void	single_free(char *s1, t_game *game);
char	*get_map_temp(t_game *game, char *map_temp, int fd);
void	init_map(t_game *game, char *argv);

//free.c
int     ft_error(char *str, t_game *game);

//utils.c
int     print_2D_array(char **str);

#endif