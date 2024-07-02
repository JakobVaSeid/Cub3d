/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caigner <caigner@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/02 12:37:03 by caigner           #+#    #+#             */
/*   Updated: 2024/07/02 13:07:41 by caigner          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

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
