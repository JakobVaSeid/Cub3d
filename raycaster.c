/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycaster.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caigner <caigner@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/18 15:59:43 by caigner           #+#    #+#             */
/*   Updated: 2024/06/27 19:58:32 by caigner          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./cub3d.h"

//SNIPPETS for later

void	get_delta(t_raycast *r)
{
	if (r->dir_x == 0)
		r->delta_x = 1e30;
	else
		r->delta_x = fabs(1 / r->dir_x);
	if (r->dir_y == 0)
		r->dir_y = 1e30;
	else
		r->delta_y = fabs(1 / r->dir_y);	
}

void	get_side_dist(t_raycast *r)
{
	get_delta(r);
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

void	calculate_dist(t_raycast *r, char **map)
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
		if (map[r->pos_x][r->pos_y] == WALL || map[r->pos_x][r->pos_y] == DOOR)
			r->hit = 1;
	}
	r->perp_wall_dist = 0;
	if (r->side == X)
		r->perp_wall_dist = r->side_dist_x - r->delta_x;
	else
		r->perp_wall_dist = r->side_dist_y - r->delta_y;
}

void	calculate_height(t_raycast *r)
{
	r->line_height = (int)(HEIGHT / r->perp_wall_dist);
	r->line_start = -r->line_height / 2 + HEIGHT / 2;
	if (r->line_start < 0)
		r->line_start = 0;
	r->line_end = r->line_height / 2 + HEIGHT / 2;
	if (r->line_end >= HEIGHT)
		r->line_end = HEIGHT - 1;
}
//

void	init_ray_struct(t_player *p, t_raycast *r)
{
	r->pos_x = p->x;
	r->pos_y = p->y;
	r->dir_x = p->dir_x; 
	r->dir_y = p->dir_y;
	r->hit = 0;
}

void	raycaster(t_game *cub, t_player *player)
{
	t_raycast ray;
	init_ray_struct(player, &ray);
	(void)cub;
	(void)player;

	
}
