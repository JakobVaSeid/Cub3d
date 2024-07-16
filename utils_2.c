/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caigner <caigner@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/16 18:36:54 by caigner           #+#    #+#             */
/*   Updated: 2024/07/16 18:45:58 by caigner          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	add_plane_and_dir_vector(t_game *game, char c)
{
	if (c == 'N')
	{
		game->player.dir_y = -1;
		game->player.plane_x = FOV;
	}
	else if (c == 'S')
	{
		game->player.dir_y = 1;
		game->player.plane_x = -FOV;
	}
	else if (c == 'W')
	{
		game->player.dir_x = -1;
		game->player.plane_y = -FOV;
	}
	else if (c == 'E')
	{
		game->player.dir_x = 1;
		game->player.plane_y = FOV;
	}
}
