/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caigner <caigner@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/24 12:43:54 by jseidere          #+#    #+#             */
/*   Updated: 2024/07/03 19:26:54 by caigner          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	move_helper(t_game *game, double dir_x, double dir_y)
{
	if (!game->map[(int)(game->player.x + dir_x * game->move_speed)][(int)game->player.y])
		game->player.x += dir_x * game->move_speed;
	if (!game->map[(int)game->player.x][(int)(game->player.y + dir_y * game->move_speed)])
		game->player.y += dir_y * game->move_speed;
}

void	move(t_game *game, int key)
{
	if (key == W || key == ARROWUP)
		move_helper(game, game->player.dir_x, game->player.dir_y);
	if (key == S || key == ARROWDOWN)
		move_helper(game, -game->player.dir_x, -game->player.dir_y);
	if (key == A)
		move_helper(game, -game->player.plane_x, -game->player.plane_y);
	if (key == D)
		move_helper(game, game->player.plane_x, game->player.plane_y);
}

void	rotate(t_player *player)
{
	//player->dir_x = player->dir_x * cos()
}

int	key_hook(int key, t_game *game)
{
	if (key == ESC)
		free_success(game);
	else if (key == W || key == ARROWUP || key == A || key == S || key == ARROWDOWN || key == D)
		move(game, key);
	if (key == ARROWLEFT)
		rotate();
	else if (key == ARROWRIGHT)
		rotate();
	return (0);
}
