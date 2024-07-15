/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caigner <caigner@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/24 12:24:37 by jseidere          #+#    #+#             */
/*   Updated: 2024/07/15 10:46:13 by caigner          ###   ########.fr       */
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
	game->mlx = NULL;
	game->img = NULL;
	init_texture(game);
	game->addr = malloc(WINDOW_HEIGHT * WINDOW_WIDTH * sizeof(int));
	if (!game->addr)
		ft_error("malloc failed\n", game);
	game->player.x = 0;
	game->player.y = 0;
	game->player.dir_x = 0;
	game->player.dir_y = 0;
	game->player.plane_x = 0;
	game->player.plane_y = FOV;
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
	if (!game->img)
	{
		ft_error("mlx_new_image failed\n", game);
	}
	game->addr = mlx_get_data_addr(game->img, &game->bits_per_pixel,
			&game->line_length, &game->endian);
	if (!game->addr)
		ft_error("mlx_get_data_addr", game);
	return (0);
}

int	main(int argc, char **argv)
{
	t_game		game;

	if (argc == 2)
	{
		init_var(&game);
		init_map(&game, argv[1]);
		printf("Row: %d\n", game.rows);
		print_td_array(game.map);
		check_file(&game, argv[1]);
		init_window(&game);
		mlx_loop_hook(game.mlx, render, &game);
		mlx_hook(game.win, 2, 1, key_hook, &game);
		mlx_loop(game.mlx);
	}
	else
		perror("Wrong input!");
	return (0);
}
