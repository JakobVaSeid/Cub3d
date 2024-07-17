/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caigner <caigner@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/24 12:24:37 by jseidere          #+#    #+#             */
/*   Updated: 2024/07/17 13:34:46 by caigner          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	texture_to_mlx(t_game *game)
{
	int	i;

	i = 0;
	while (i < 4)
	{
		game->texture[i].img = mlx_xpm_file_to_image(game->mlx, \
				game->texture[i].path, &game->texture[i].width, \
				&game->texture[i].height);
		free(game->texture[i].path);
		i++;
	}
}

int	main(int argc, char **argv)
{
	t_game		game;

	if (argc == 2)
	{
		init_var(&game);
		init_map(&game, argv[1]);
		get_rows(&game);
		printf("Row: %d\n", game.rows);
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
