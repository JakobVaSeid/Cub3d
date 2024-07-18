/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caigner <caigner@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/16 18:36:54 by caigner           #+#    #+#             */
/*   Updated: 2024/07/18 16:08:22 by caigner          ###   ########.fr       */
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

int	key_press(int key, t_game *game)
{
	if (key >= 0 && key <= KEY_NUMS)
		game->key_state[key] = true;
	return (0);
}

int	key_release(int key, t_game *game)
{
	if (key >= 0 && key <= KEY_NUMS)
		game->key_state[key] = false;
	return (0);
}

void	ft_texture_to_mlx(t_game *game)
{
	int	i;

	i = 0;
	while (i < 4)
	{
		game->texture[i].img = mlx_xpm_file_to_image(game->mlx, \
				game->texture[i].path, &game->texture[i].width, \
				&game->texture[i].height);
		i++;
	}
}
