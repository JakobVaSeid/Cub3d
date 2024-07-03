/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caigner <caigner@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/24 12:24:37 by jseidere          #+#    #+#             */
/*   Updated: 2024/07/03 15:20:28 by caigner          ###   ########.fr       */
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

int	init_window(t_game *game)
{
	game->mlx = mlx_init();
	if (!game->mlx)
	{
		ft_putstr_fd("Error\nCan't init mlx\n", 2);
		return (1);
	}
	game->win = mlx_new_window(game->mlx, WINDOW_WIDTH, WINDOW_HEIGHT, "Cub3D");
	if (!game->win)
	{
		ft_putstr_fd("Error\nCan't create window\n", 2);
		return (1);
	}
	game->img = mlx_new_image(game->mlx, WINDOW_WIDTH, WINDOW_HEIGHT);
	game->addr = mlx_get_data_addr(game->img, &game->bits_per_pixel,
			&game->line_length, &game->endian);
	return (0);
}

int	key_hook(int key, t_game *game)
{
	if (key == ESC)
		free_success(game);
	else if (key == W || key == ARROWUP)
		(void)game;//move();
	else if (key == A)
		(void)game;//move();
	else if (key == S || key == ARROWDOWN)
		(void)game;//move();
	else if (key == D)
		(void)game;//move();
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
		check_file(&game, argv[1]);
		init_window(&game);
		mlx_hook(game.win, 2, 1, key_hook, &game);
		mlx_loop(game.mlx);
	}
	else
		perror("Wrong input!");
	return (0);
}
