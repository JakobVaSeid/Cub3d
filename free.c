/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caigner <caigner@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/24 12:36:26 by jseidere          #+#    #+#             */
/*   Updated: 2024/07/15 14:06:03 by caigner          ###   ########.fr       */
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

void	destroy_mlx(t_game *game)
{
	int	i;

	i = 0;
	while (i < NUM_TEXTURES)
	{
		if (game->texture[i]->img)
			mlx_destroy_image(game->mlx, game->texture[i]->img);
		i++;
	}
	if (game->img)
		mlx_destroy_image(game->mlx, game->img);
	if (game->mlx && game->win)
		mlx_destroy_window(game->mlx, game->win);
	if (game->mlx)
	{
		mlx_destroy_display(game->mlx);
		free(game->mlx);
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
	if (game->addr)
		free(game->addr);
	destroy_mlx(game);
	if (game->fd)
		close(game->fd);
}
