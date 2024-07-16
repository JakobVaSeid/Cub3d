/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycaster_1.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caigner <caigner@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/18 15:59:43 by caigner           #+#    #+#             */
/*   Updated: 2024/07/16 18:51:01 by caigner          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./cub3d.h"

int	determine_texture(t_game *game, t_raycast *r)
{
	if (r->side == X && r->dir_x > 0)
	{
		return (r->texture->addr = mlx_get_data_addr(game->texture[EAST]->img,
				&game->bits_per_pixel, &game->texture[EAST]->line_length,
				&game->texture[EAST]->endian), r->tex_num = EAST, 0);
	}
	else if (r->side == X)
	{
		return (r->texture->addr = mlx_get_data_addr(game->texture[WEST]->img,
				&game->bits_per_pixel, &game->texture[WEST]->line_length,
				&game->texture[WEST]->endian), r->tex_num = WEST, 0);
	}
	else if (r->side == Y && r->dir_y > 0)
	{
		return (r->texture->addr = mlx_get_data_addr(game->texture[SOUTH]->img,
				&game->bits_per_pixel, &game->texture[SOUTH]->line_length,
				&game->texture[SOUTH]->endian), r->tex_num = SOUTH, 0);
	}
	else if (r->side == Y)
	{
		return (r->texture->addr = mlx_get_data_addr(game->texture[NORTH]->img,
				&game->bits_per_pixel, &game->texture[NORTH]->line_length,
				&game->texture[NORTH]->endian), r->tex_num = NORTH, 0);
	}
	return (1);
}

void	my_mlx_pixel_put(t_game *game, int x, int y, unsigned int color)
{
	char	*dest;

	dest = game->addr + (y * game->line_length + x
			* game->bits_per_pixel);
	*(unsigned int *)dest = color;
}

/* void	draw_line(t_game *game, int x, t_raycast *r)
{
	int		y;
	double	step;
	double	tex_pos;
	int		tex_y;

	step = 0;
	step = game->texture[r->tex_num]->height / r->line_height;
	tex_pos = (r->line_start - WINDOW_HEIGHT / 2 + r->line_height / 2) * step;
	y = r->line_start;
	while (y < r->line_end)
	{
		tex_y = (int)tex_pos % game->texture[r->tex_num]->height;
		tex_pos += step;
		r->color = *(unsigned int *)(r->texture->addr + (tex_y
			* r->texture->line_length + x * (game->bits_per_pixel / 8)));
		my_mlx_pixel_put(game, x, y, r->color);
		y++;
	}
} */

void	draw_line(t_game *game, int x, t_raycast *r)
{
	int		y;

	y = r->line_start;
	while (y < r->line_end)
	{
		r->color = 13172854;
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
		get_side_dist(game, &ray);
		calculate_dist(&ray, game->map);
		calculate_height(&ray);
	//	determine_texture(game, &ray);
		draw_line(game, x, &ray);
	//	printf("%d line start\n", ray.line_start);
	//	printf("%d line end\n", ray.line_end);
		x++;
	}
}
