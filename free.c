/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jseidere <jseidere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/24 12:36:26 by jseidere          #+#    #+#             */
/*   Updated: 2024/07/02 13:25:43 by jseidere         ###   ########.fr       */
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
	if (game->fd)
		close(game->fd);
	if (game->map)
		free_map(game->map);
	perror(str);
	return (0);
}
void	close_window(t_game *cub)
{
	int	i;

	i = 0;
	if (cub->mlx)
		mlx_loop_end(cub->mlx);
	while (i < NUM_TEXTURES)
	{
		if (cub->texture[i].img)
			mlx_destroy_image(cub->mlx, cub->texture[i].img);
		i++;
	}
	if (cub->win)
		mlx_destroy_window(cub->mlx, cub->win);
	if (cub->mlx)
	{
		mlx_destroy_display(cub->mlx);
		free(cub->mlx);
	}
}

void	free_all(t_game *cub)
{
	//free everything
	close_window(cub);
}
