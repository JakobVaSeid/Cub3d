/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycaster_2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caigner <caigner@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/01 17:25:24 by caigner           #+#    #+#             */
/*   Updated: 2024/07/15 13:03:37 by caigner          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./cub3d.h"

void	init_ray_struct(t_game *game, t_raycast *r, int x)
{
	r->cam_x = 2 * x / (double)WINDOW_WIDTH - 1;
	r->pos_x = (int)game->player.x;
	r->pos_y = (int)game->player.y;
	r->dir_x = game->player.dir_x + game->player.plane_x * r->cam_x;
	r->dir_y = game->player.dir_y + game->player.plane_y * r->cam_x;
	r->hit = 0;
	if (r->dir_x == 0.0)
		r->delta_x = 1e30;
	else
		r->delta_x = fabs(1 / r->dir_x);
	if (r->dir_y == 0.0)
		r->delta_y = 1e30;
	else
		r->delta_y = fabs(1 / r->dir_y);
}

void	get_side_dist(t_raycast *r)
{
	if (r->dir_x >= 0)
	{
		r->side_dist_x = (1 - r->pos_x % 1) * r->delta_x;
		r->step_x = 1;
	}
	else
	{
		r->side_dist_x = (r->pos_x % 1) * r->delta_x;
		r->step_x = -1;
	}
	if (r->dir_y >= 0)
	{
		r->side_dist_y = (1 - r->pos_y % 1) * r->delta_y;
		r->step_y = 1;
	}
	else
	{
		r->side_dist_y = (r->pos_y % 1) * r->delta_y;
		r->step_y = -1;
	}
}

void	calculate_dist(t_game *game, t_raycast *r, char **map)
{
	while (!r->hit)
	{
		if (r->side_dist_x < r->side_dist_y)
		{
			r->side_dist_x += r->delta_x;
			r->pos_x += r->step_x;
			r->side = X;
		}
		else
		{
			r->side_dist_y += r->delta_y;
			r->pos_y += r->step_y;
			r->side = Y;
		}
		if (r->pos_x < 0 || r->pos_x >= (int)ft_strlen(map[r->pos_x]) || r->pos_y < 0 || r->pos_y >= game->rows - 7)
			return ;
		if (map[r->pos_x][r->pos_y] == WALL || map[r->pos_x][r->pos_y] == DOOR)
			r->hit = 1;
	}
}

void	calculate_height(t_raycast *r)
{
	if (r->side == X)
		r->perp_wall_dist = r->side_dist_x - r->delta_x;
	else
		r->perp_wall_dist = r->side_dist_y - r->delta_y;
	r->line_height = (int)(HEIGHT / r->perp_wall_dist);
	r->line_start = HEIGHT / 2 - r->line_height / 2;
	if (r->line_start < 0)
		r->line_start = 0;
	r->line_end = HEIGHT / 2 + r->line_height / 2;
	if (r->line_end >= HEIGHT)
		r->line_end = HEIGHT - 1;
}
