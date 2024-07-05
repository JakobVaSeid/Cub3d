/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jseidere <jseidere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/24 12:24:37 by jseidere          #+#    #+#             */
/*   Updated: 2024/07/03 17:54:21 by jseidere         ###   ########.fr       */
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
	init_texture(game);
}

int	init_window(t_game *cub)
{
	cub->mlx = mlx_init();
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

int	key_hook(int key, t_game *cub)
{
	if (key == ESC)
		free_success(cub);
	else if (key == W || key == ARROWUP)
		(void)cub;//move();
	else if (key == A)
		(void)cub;//move();
	else if (key == S || key == ARROWDOWN)
		(void)cub;//move();
	else if (key == D)
		(void)cub;//move();
	return (0);
}

int	main(int argc, char **argv)
{
	t_game	game;

	if (argc == 2)
	{
		init_var(&game);
		init_map(&game, argv[1]);
		printf("Row: %d\n", game.rows);
		print_td_array(game.map);
		init_window(&game);
		check_file(&game, argv[1]);
		mlx_hook(game.win, 2, 1, key_hook, &game);
		mlx_loop(game.mlx);
	}
	else
		perror("Wrong input!");
	return (0);
}
