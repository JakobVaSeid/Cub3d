/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycaster_1.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caigner <caigner@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/18 15:59:43 by caigner           #+#    #+#             */
/*   Updated: 2024/07/15 14:05:30 by caigner          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./cub3d.h"

void	determine_texture(t_game *game, t_raycast *r)
{
	if (r->side == X && r->dir_x > 0)
		r->texture = game->texture[EAST];
	else if (r->side == X)
		r->texture = game->texture[WEST];
	else if (r->side == Y && r->dir_y > 0)
		r->texture = game->texture[SOUTH];
	else if (r->side == Y)
		r->texture = game->texture[NORTH];
}

void	my_mlx_pixel_put(t_game *game, int x, int y, unsigned int color)
{
	char	*dest;

	dest = game->addr + (y * game->line_length + x
			* (game->bits_per_pixel / 8));
	*(unsigned int *)dest = color;
}

void	draw_line(t_game *game, int x, t_raycast *r)
{
	int		y;
	double	step;
	double	tex_pos;
	int		tex_y;

	step = 0;
	if (r->line_height)
		step = r->texture->height / r->line_height;
	tex_pos = (r->line_start - WINDOW_HEIGHT / 2 + r->line_height / 2) * step;
	y = r->line_start;
	while (y < r->line_end)
	{
		tex_y = (int)tex_pos % r->texture->height;
		tex_pos += step;
		r->color = *(unsigned int *)(r->texture->addr + (tex_y * r->texture->line_length + x * (game->bits_per_pixel / 8)));
		my_mlx_pixel_put(game, x, y, r->color);
		y++;
	}
}

void	raycaster(t_game *game)
{
	t_raycast	ray;
	int			x;

	x = 0;
	while (x < WINDOW_WIDTH)
	{
		init_ray_struct(game, &ray, x);
		get_side_dist(&ray);
		calculate_dist(game, &ray, game->map);
		calculate_height(&ray);
		determine_texture(game, &ray);
		draw_line(game, x, &ray);
		x++;
	}
}
