/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caigner <caigner@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/05 14:40:53 by jseidere          #+#    #+#             */
/*   Updated: 2024/07/17 13:18:24 by caigner          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	init_texture(t_game *game)
{
	int	i;

	i = 0;
	while (i < NUM_TEXTURES)
	{
		game->texture[i].img = NULL;
		game->texture[i].addr = NULL;
		game->texture[i].path = NULL;
		i++;
	}
}

void	init_var(t_game *game)
{
	game->fd = 0;
	game->map = NULL;
	game->rows = 0;
	game->player_amount = 0;
	game->map_param = 0;
	game->mlx = NULL;
	game->win = NULL;
	game->img = NULL;
	game->player.x = 0;
	game->player.y = 0;
	game->player.dir_x = 0;
	game->player.dir_y = 0;
	game->player.plane_x = 0;
	game->player.plane_y = 0;
	game->move_speed = MOVEMENT;
	game->rot_speed = ROTATION;
	init_texture(game);
}

int	init_window(t_game *game)
{
	game->mlx = mlx_init();
	if (!game->mlx)
	{
		ft_putstr_fd("Error\nCan't init mlx\n", 2);
		return (1);
	}
//	texture_to_mlx(game);
	game->win = mlx_new_window(game->mlx, WINDOW_WIDTH, WINDOW_HEIGHT, "Cub3D");
	if (!game->win)
	{
		ft_putstr_fd("Error\nCan't create window\n", 2);
		return (1);
	}
	return (0);
}

int	xpm_to_img(void *mlx, char *path, void **img)
{
	int	height;
	int	width;

	*img = mlx_xpm_file_to_image(mlx, path, &height, &width);
	if (*img == 0)
		return (0);
	return (1);
}

int	init_img(t_game *game)
{
	int	i;

	i = 0;
	while (i < NUM_TEXTURES)
	{
		if (xpm_to_img(game->mlx, game->texture[i].path, game->texture[i].img))
			return (0);
		i++;
	}
	return (1);
}
