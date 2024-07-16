/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caigner <caigner@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/03 17:38:42 by caigner           #+#    #+#             */
/*   Updated: 2024/07/16 18:54:49 by caigner          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./cub3d.h"

double	get_time(void)
{
	struct timeval	tv;

	if (gettimeofday(&tv, NULL) == -1)
		return (ft_putstr_fd("gettimeofday failed \n", 2), -1);
	return (tv.tv_sec * 1000 + tv.tv_usec / 1000);
}

void	ft_new_image(t_game *game)
{
	game->img = mlx_new_image(game->mlx, WINDOW_WIDTH, WINDOW_HEIGHT);
	if (!game->img)
	{
		ft_error("mlx_new_image failed\n", game);
	}
	game->addr = mlx_get_data_addr(game->img, &game->bits_per_pixel,
			&game->line_length, &game->endian);
	if (!game->addr)
		ft_error("mlx_get_data_addr", game);
	game->bits_per_pixel /= 8;
}

void	draw_background(t_game *game, int x, int y, unsigned int color)
{
	char	*dest;

	dest = game->addr + (WINDOW_WIDTH * y + x) * game->bits_per_pixel;
	*(unsigned int *)dest = color;
}

void	ft_background(t_game *game)
{
	int		x;
	int		y;

	x = 0;
	while (x < WINDOW_WIDTH)
	{
		y = 0;
		while (y < WINDOW_HEIGHT / 2)
			draw_background(game, x, y++, CCOLOR);
		x++;
	}
	x = 0;
	while (x < WINDOW_WIDTH)
	{
		y = WINDOW_HEIGHT / 2;
		while (y < WINDOW_HEIGHT)
			draw_background(game, x, y++, FCOLOR);
		x++;
	}
}

int	render(t_game *game)
{
	ft_new_image(game);
	ft_background(game);
	raycaster(game);
	mlx_put_image_to_window(game->mlx, game->win, game->img, 0, 0);
	mlx_destroy_image(game->mlx, game->img);
	return (0);
}

/*	int	render(t_game *game)
{
	static double	old_time = 0;
	double			time;
	double			frame_time;

	time = get_time();
	frame_time = (time - old_time) / 1000.0;
	ft_memset(game->addr, 0, WINDOW_HEIGHT * WINDOW_WIDTH
		* (game->bits_per_pixel / 8));
	while ((get_time() - old_time) < (1000 / FPS))
		raycaster(game);
	old_time = time;
	mlx_put_image_to_window(game->mlx, game->win, game->img, 0, 0);
	game->move_speed = frame_time * MOVEMENT;
	game->rot_speed = frame_time * ROTATION;
	return (0);
} */
