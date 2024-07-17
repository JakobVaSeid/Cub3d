/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_checker.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jseidere <jseidere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/24 12:39:32 by jseidere          #+#    #+#             */
/*   Updated: 2024/07/17 12:19:10 by jseidere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

//check row for allowed chars
bool	only_allowed_chars(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (!ft_strchr("NSEW01 ", str[i]))
			return (false);
		i++;
	}
	return (true);
}

//check if only walls
bool	only_walls(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		skip_spaces(str, &i);
		if (!ft_strchr("1 ", str[i]))
			return (false);
		skip_spaces(str, &i);
		i++;
	}
	return (true);
}

//check each row if no norm errors
bool	check_row(t_game *game, char **map)
{
	int	i;

	i = 6;
	while (map[i])
	{
		if (is_empty(map[i]))
			return (false);
		if (!only_walls(map[6]) && !only_walls(map[game->rows]))
			return (false);
		if (!only_allowed_chars(map[i]))
			return (false);
		count_player(game, map[i]);
		i++;
	}
	return (true);
}

bool	check_surr(t_game *game, int y, int x)
{
	if (game->map[y + 1][x] == ' ' || !game->map[y + 1][x])
		return (false);
	if (game->map[y - 1][x] == ' ' || !game->map[y - 1][x])
		return (false);
	if (game->map[y][x + 1] == ' ' || !game->map[y][x + 1])
		return (false);
	if (game->map[y][x - 1] == ' ' || !game->map[y][x - 1])
		return (false);
	return (true);
}

bool	check_pos(t_game *game)
{
	int	x;
	int	y;

	y = 6;
	while (y < game->rows)
	{
		x = 0;
		while (game->map[y][x])
		{
			if (strchr("0NSWE", game->map[y][x]))
			{
				if (!check_surr(game, y, x))
					return (false);
			}
			x++;
		}
		y++;
	}
	return (true);
}
