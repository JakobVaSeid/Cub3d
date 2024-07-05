/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jseidere <jseidere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/24 12:24:37 by jseidere          #+#    #+#             */
/*   Updated: 2024/07/05 17:34:43 by jseidere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"



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
		get_rows(&game);
		printf("Row: %d\n", game.rows);
		print_td_array(game.map);
		init_window(&game);
		check_file(&game, argv[1]);
		//init_img(&game);
		printf("Param: %i\n", game.map_param);
		mlx_hook(game.win, 2, 1, key_hook, &game);
		mlx_loop(game.mlx);
	}
	else
		perror("Wrong input!");
	return (0);
}
