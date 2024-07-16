/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caigner <caigner@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/24 12:24:37 by jseidere          #+#    #+#             */
/*   Updated: 2024/07/16 20:32:17 by caigner          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	init_texture(t_game *game)
{
	int	i;

	i = 0;
	while (i < NUM_TEXTURES)
	{
		game->texture[i] = malloc(sizeof(t_texture));
		game->texture[i]->img = NULL;
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
//	game->addr = malloc(WINDOW_HEIGHT * WINDOW_WIDTH * sizeof(int));
//	if (!game->addr)
//		ft_error("malloc failed\n", game);
	game->player.x = 0;
	game->player.y = 0;
	game->player.dir_x = 0;
	game->player.dir_y = 0;
	game->player.plane_x = 0;
	game->player.plane_y = 0;
	game->move_speed = MOVEMENT;
	game->rot_speed = ROTATION;
}

void	texture_to_mlx(t_game *game)
{
	int	i;

	i = 0;
	while (i < 4)
	{
		game->texture[i]->img = mlx_xpm_file_to_image(game->mlx,
				game->texture[i]->path, &game->texture[i]->width,
				&game->texture[i]->height);
		free(game->texture[i]->path);
		i++;
	}
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

int	main(int argc, char **argv)
{
	t_game		game;

	if (argc == 2)
	{
		init_var(&game);
		init_map(&game, argv[1]);
		print_td_array(game.map);
		check_file(&game, argv[1]);
		init_window(&game);
		mlx_loop_hook(game.mlx, render, &game);
		mlx_hook(game.win, 2, 1, key_hook, &game);
		mlx_hook(game.win, 17, 0L, free_success, &game);
		mlx_loop(game.mlx);
	}
	else
		perror("Wrong input!");
	return (0);
}
