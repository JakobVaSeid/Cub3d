/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jseidere <jseidere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/24 12:36:26 by jseidere          #+#    #+#             */
/*   Updated: 2024/07/03 15:02:19 by jseidere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	free_map(char **map)
{
	int	i;

	i = 0;
	while (map[i])
	{
		free(map[i]);
		i++;
	}
	free(map);
	return (0);
}

int	ft_error(char *str, t_game *game)
{
	ft_putstr_fd(str, 2);
	free_all(game);
	exit(1);
}

void	destroy_mlx(t_game *cub)
{
	int	i;

	i = 0;
	while (i < NUM_TEXTURES)
	{
		if (cub->texture[i].img)
			mlx_destroy_image(cub->mlx, cub->texture[i].img);
		i++;
	}
	if (cub->mlx && cub->win)
		mlx_destroy_window(cub->mlx, cub->win);
	if (cub->mlx)
	{
		mlx_destroy_display(cub->mlx);
		free(cub->mlx);
	}
}

int	free_success(t_game *game)
{
	free_all(game);
	exit(0);
}

void	free_all(t_game *game)
{
	if (game->map)
		free_map(game->map);
	destroy_mlx(game);
	if (game->fd)
		close(game->fd);
}
