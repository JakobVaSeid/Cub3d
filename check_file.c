/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_file.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caigner <caigner@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/02 12:40:54 by jseidere          #+#    #+#             */
/*   Updated: 2024/07/17 13:08:23 by caigner          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	get_rows(t_game *game)
{
	int	i;

	i = 0;
	while (game->map[i])
	{
		game->rows++;
		i++;
	}
}

//check for right fileextension
bool	right_fileextension(char *file)
{
	char	*extension;

	extension = strchr(file, '.');
	if (!strcmp(extension, ".cub"))
		return (true);
	else
		return (false);
}

int	check_file(t_game *game, char *argv)
{
	if (!right_fileextension(argv))
		ft_error("Wrong fileextension!", game);
	if (!check_pos(game))
		ft_error("Invalid map!", game);
	if (!check_row(game, game->map))
		ft_error("Map error!", game);
	norm_map(game);
	if (game->player_amount != 1)
		ft_error("Wrong player amount!", game);
	if (!check_attributes(game))
		ft_error("Wrong map params", game);
	game->map[(int)game->player.y][(int)game->player.y] = '0'; //wo anders sinnvoller?
	return (0);
}
