/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caigner <caigner@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/24 12:43:54 by jseidere          #+#    #+#             */
/*   Updated: 2024/07/16 18:55:46 by caigner          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/* void	move_helper(t_game *game, double dir_x, double dir_y)
{
	int	new_x;
	int	new_y;

	new_x = (int)(game->player.x + dir_x * game->move_speed);
	new_y = (int)(game->player.y + dir_y * game->move_speed);
	if (new_x >= 0 && new_x < game->rows && new_y >= 0 && new_y
		< (int)ft_strlen(game->map[new_x]))
	{
		if (game->map[(int)new_x][(int)game->player.y] != WALL &&
			game->map[(int)new_x][(int)game->player.y] != DOOR)
			game->player.x = new_x;
		if (game->map[(int)game->player.x][(int)new_y] != WALL &&
			game->map[(int)game->player.x][(int)new_y] != DOOR)
			game->player.y = new_y;
	}
} */

void	move_helper(t_game *game, double dir_x, double dir_y)
{
	if (!game->map[(int)(game->player.x + dir_x * game->move_speed)][(int)game->player.y])
		game->player.x += dir_x * game->move_speed;
	if (!game->map[(int)game->player.x][(int)(game->player.y + dir_y * game->move_speed)])
		game->player.y += dir_y * game->move_speed;
}

void	move(t_game *game, int key)
{
	write(1, "move registered\n", 16);
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
	double	rot_speed;
	double	cos_rot;
	double	sin_rot;
	double	old_dir_x;
	double	old_plane_x;

	write(1, "rotate registered\n", 18);
	if (key == ARROWRIGHT)
		rot_speed = -game->rot_speed;
	else
		rot_speed = game->rot_speed;
	cos_rot = cos(rot_speed);
	sin_rot = sin(rot_speed);
	old_dir_x = player->dir_x;
	player->dir_x = player->dir_x * cos_rot - player->dir_y * sin_rot;
	player->dir_y = old_dir_x * sin_rot + player->dir_y * cos_rot;
	old_plane_x = player->plane_x;
	player->plane_x = player->plane_x * cos_rot - player->plane_y * sin_rot;
	player->plane_y = old_plane_x * sin_rot + player->plane_y * cos_rot;
}

int	key_hook(int key, t_game *game)
{
	if (key == ESC)
		free_success(game);
	else if (key == W || key == ARROWUP || key == A || key == S
		|| key == ARROWDOWN || key == D)
		move(game, key);
	else if (key == ARROWLEFT || key == ARROWRIGHT)
		rotate(game, &game->player, key);
	return (0);
}
