/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caigner <caigner@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/03 17:38:42 by caigner           #+#    #+#             */
/*   Updated: 2024/07/15 13:18:10 by caigner          ###   ########.fr       */
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

void	clear_image(t_game *game)
{
	ft_memset(game->addr, 0, WINDOW_WIDTH * WINDOW_HEIGHT * sizeof(int));
}

int	render(t_game *game)
{
	static double	old_time;
	double			time;
	double			frame_time;

	old_time = 0;
	time = get_time();
	frame_time = (time - old_time) / 1000.0;
//	while ((get_time() - old_time) < (1000 / FPS))
//		;
	old_time = time;
	clear_image(game->img);
	raycaster(game);
	mlx_put_image_to_window(game->mlx, game->win, game->img, 0, 0);
	game->move_speed = frame_time * MOVEMENT;
	game->rot_speed = frame_time * ROTATION;
	return (0);
}
