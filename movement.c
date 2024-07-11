/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chris <chris@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/24 12:43:54 by jseidere          #+#    #+#             */
/*   Updated: 2024/07/11 13:19:38 by chris            ###   ########.fr       */
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

void	rotate(t_game *game, t_player *player, int key)
{
	if (key == ARROWRIGHT)
	{
		player->old_dir_x = player->dir_x;
		player->dir_x = player->dir_x * cos(-game->rot_speed) - player->dir_y * sin(-game->rot_speed);
		player->dir_y = player->old_dir_x * sin(-game->rot_speed) + player->dir_y * cos(-game->rot_speed);
		player->old_plane_x = player->plane_x;
		player->plane_x = player->plane_x * cos(-game->rot_speed) - player->plane_y * sin(-game->rot_speed);
		player->plane_y = player->old_plane_x * sin(-game->rot_speed) + player->plane_y * cos(-game->rot_speed);
	}
	if (key == ARROWLEFT)
	{
		player->old_dir_x = player->dir_x;
		player->dir_x = player->dir_x * cos(game->rot_speed) - player->dir_y * sin(game->rot_speed);
		player->dir_y = player->old_dir_x * sin(game->rot_speed) + player->dir_y * cos(game->rot_speed);
		player->old_plane_x = player->plane_x;
		player->plane_x = player->plane_x * cos(game->rot_speed) - player->plane_y * sin(game->rot_speed);
		player->plane_y = player->old_plane_x * sin(game->rot_speed) + player->plane_y * cos(game->rot_speed);
	}
}

int	key_hook(int key, t_game *game)
{
	if (key == ESC)
		free_success(game);
	else if (key == W || key == ARROWUP || key == A || key == S || key == ARROWDOWN || key == D)
		move(game, key);
	if (key == ARROWLEFT || key == ARROWRIGHT)
		rotate(game, &game->player, key);
	return (0);
}
