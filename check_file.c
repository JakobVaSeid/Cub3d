/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_file.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jseidere <jseidere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/02 12:40:54 by jseidere          #+#    #+#             */
/*   Updated: 2024/07/18 14:35:08 by jseidere         ###   ########.fr       */
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
bool	right_fileextension(char *file, char *end)
{
	char	*extension;

	if (ft_strlen(file) < 5)
		return (false);
	extension = ft_strrchr(file, '.');
	if (!extension)
		return (false);
	if (!ft_strncmp(extension, end, 4) && ft_strlen(extension))
		return (true);
	else
		return (false);
}

int	check_file(t_game *game, char *argv)
{
	if (!right_fileextension(argv, ".cub"))
		ft_error("Wrong fileextension!", game);
	if (!check_row(game, game->map))
		ft_error("Map error!", game);
	if (!check_pos(game))
		ft_error("Invalid map!", game);
	norm_map(game);
	if (game->player_amount != 1)
		ft_error("Wrong player amount!", game);
	if (!check_attributes(game))
		ft_error("Wrong map params", game);
	//wo anders sinnvoller?
	game->map[(int)game->player.y][(int)game->player.x] = '0';
	return (0);
}
