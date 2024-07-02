/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caigner <caigner@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/24 12:24:37 by jseidere          #+#    #+#             */
/*   Updated: 2024/07/02 13:05:33 by caigner          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	check_argv(int ac, char **av, t_game *cub)
{
	if (ac == 1)
	{
		ft_putstr_fd("Error\nNo map file provided\n", 2);
		return (0);
	}
	else if (ac > 2)
	{
		ft_putstr_fd("Error\nToo many arguments\n", 2);
		return (0);
	}
	else if (ac == 2 && ft_strncmp(av[1] + ft_strlen(av[1]) - 4, ".cub", 4))
	{
		ft_putstr_fd("Error\nInvalid file extension\n", 2);
		return (0);
	}
	cub->fd = open(av[1], O_RDONLY);
	if (cub->fd < 0)
	{
		ft_putstr_fd("Error\nCan't open file\n", 2);
		return (0);
	}
	return (1);
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
	mlx_loop(cub->mlx);
	return (0);
}

int	close_program(t_game *cub, int exitcode)
{
	free_all(cub);
	exit(exitcode);
}

int	key_hook(int key, t_game *cub)
{
	if (key == ESC)
		close_program(cub, 0);
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
	t_game	cub;

	if (!check_argv(argc, argv, &cub))
		return (1);
	init_window(&cub);
	mlx_hook(cub.win, 2, 1, key_hook, &cub);
	return (0);
}
