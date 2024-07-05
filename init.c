/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jseidere <jseidere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/05 14:40:53 by jseidere          #+#    #+#             */
/*   Updated: 2024/07/05 15:32:06 by jseidere         ###   ########.fr       */
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
	game->win = NULL;
	game->map_param = 0;
	init_texture(game);
}

int	init_window(t_game *cub)
{
	cub->mlx = mlx_init();
    printf("cub->mlx: %p\n", cub->mlx);
	if (!cub->mlx)
	{
		ft_putstr_fd("Error\nCan't init mlx\n", 2);
		return (1);
	}
	cub->win = mlx_new_window(cub->mlx, WINDOW_WIDTH, WINDOW_HEIGHT, "Cub3D");
	if (!cub->win)
	{
		ft_putstr_fd("Error\nCan't create window\n", 2);
		return (1);
	}
	cub->img = mlx_new_image(cub->mlx, WINDOW_WIDTH, WINDOW_HEIGHT);
	cub->addr = mlx_get_data_addr(cub->img, &cub->bits_per_pixel,
			&cub->line_length, &cub->endian);
	//mlx_loop(cub->mlx);
	return (0);
}

int	xpm_to_img(void *mlx, char *path, void **img)
{
	int	height;
	int	width;

    printf("PathINXPM:%s\n", path);
    printf("mlx: %p\n", mlx);
	*img = mlx_xpm_file_to_image(mlx, path, &height, &width);
    printf("here!");
	if (*img == 0)
		return (0);
	return (1);
}

int init_img(t_game *game)
{
    int i;

    i = 0;
    while(i < NUM_TEXTURES)
    {
        printf("Path:%s\n", game->texture[i].path);
        if(xpm_to_img(game->mlx, game->texture[i].path, game->texture[i].img))
           return(0);
        i++;
    }
    return (1);
}