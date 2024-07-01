/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycaster_1.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caigner <caigner@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/18 15:59:43 by caigner           #+#    #+#             */
/*   Updated: 2024/07/01 17:26:05 by caigner          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./cub3d.h"

void	determine_texture(t_game *cub, t_raycast *r)
{
	if (r->side == X && r->dir_x > 0)
		r->texture = cub->texture[EAST];
	else if (r->side == X)
		r->texture = cub->texture[WEST];
	else if (r->side == Y && r->dir_y > 0)
		r->texture = cub->texture[SOUTH];
	else if (r->side == Y)
		r->texture = cub->texture[NORTH];
}

void	my_mlx_pixel_put(t_game *cub, int x, int y, unsigned int color)
{
	char	*dest;

	dest = cub->addr + (y * cub->line_length + x
			* (cub->bits_per_pixel / 8));
	*(unsigned int *)dest = color;
}

void	draw_line(t_game *cub, int x, t_raycast *r)
{
	int		y;
	double	step;
	double	tex_pos;
	int		tex_y;

	step = r->texture.height / r->line_height;
	tex_pos = (r->line_start - WINDOW_HEIGHT / 2 + r->line_height / 2) * step;
	y = r->line_start;
	while (y < r->line_end)
	{
		tex_y = (int)tex_pos % r->texture.height;
		tex_pos += step;
		r->color = *(unsigned int *)(r->texture.addr + (y * cub->line_length
					+ x * (cub->bits_per_pixel / 8)));
		my_mlx_pixel_put(cub, x, y, r->color);
		y++;
	}
}

void	raycaster(t_game *cub)
{
	t_raycast	ray;
	int			x;

	x = 0;
	while (x < WINDOW_WIDTH)
	{
		init_ray_struct(cub, &ray, x);
		get_side_dist(&ray);
		calculate_dist(&ray, cub->map.map);
		calculate_height(&ray);
		determine_texture(cub, &ray);
		draw_line(cub, x, &ray);
		x++;
	}
	mlx_put_image_to_window(cub->mlx, cub->win, cub->img, 0, 0);
}
