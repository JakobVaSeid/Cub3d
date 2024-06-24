/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycaster.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caigner <caigner@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/18 15:59:43 by caigner           #+#    #+#             */
/*   Updated: 2024/06/24 14:42:39 by caigner          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./cub3d.h"

void	init_ray_struct(t_player *p, t_raycast *r)
{
	r->pos_x = p->x;
	r->pos_y = p->y;
	r->ray_x = p->dx; 
	r->ray_y = p->dy;
}

void	raycaster(t_game *cub, t_player *player)
{
	t_raycast ray;
	init_ray_struct(player, &ray);
	(void)cub;
	(void)player;

	
}
