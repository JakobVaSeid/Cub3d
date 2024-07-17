/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caigner <caigner@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/24 12:43:54 by jseidere          #+#    #+#             */
/*   Updated: 2024/07/17 17:02:09 by caigner          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	move_helper(t_game *game, double dir_x, double dir_y)
{
	double	new_x;
	double	new_y;

	new_x = game->player.x + dir_x * game->move_speed;
	new_y = game->player.y + dir_y * game->move_speed;
	if ((int)new_y >= 6 && (int)new_y < game->rows && (int)new_x >= 0 && \
		(int)new_x < (int)ft_strlen(game->map[(int)new_y]))
	{
		if (game->map[(int)new_y][(int)game->player.x] != WALL && \
			game->map[(int)new_y][(int)game->player.x] != DOOR)
			game->player.y = new_y;
		if (game->map[(int)game->player.y][(int)new_x] != WALL && \
			game->map[(int)game->player.y][(int)new_x] != DOOR)
			game->player.x = new_x;
	}
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
	double	rot_speed;
	double	cos_rot;
	double	sin_rot;
	double	old_dir_x;
	double	old_plane_x;

	if (key == ARROWLEFT)
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

void	handle_input(t_game *game)
{
	double move_x = 0;
	double move_y = 0;

	if (game->key_state[W] || game->key_state[ARROWUP])
	{
		move_x += game->player.dir_x;
		move_y += game->player.dir_y;
	}
	if (game->key_state[S] || game->key_state[ARROWDOWN])
	{
		move_x -= game->player.dir_x;
		move_y -= game->player.dir_y;
	}
	if (game->key_state[A])
	{
		move_x -= game->player.plane_x;
		move_y -= game->player.plane_y;
	}
	if (game->key_state[D])
	{
		move_x += game->player.plane_x;
		move_y += game->player.plane_y;
	}
	if (move_x != 0 && move_y != 0)
	{
		double length = sqrt(move_x * move_x + move_y * move_y);
		move_x /= length;
		move_y /= length;
	}
	move_helper(game, move_x, move_y);
	if (game->key_state[ARROWLEFT])
		rotate(game, &game->player, ARROWLEFT);
	if (game->key_state[ARROWRIGHT])
		rotate(game, &game->player, ARROWRIGHT);
	if (game->key_state[ESC])
		free_success(game);
}
