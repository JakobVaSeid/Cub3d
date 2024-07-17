/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   attribute_checker.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jseidere <jseidere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/17 12:43:05 by jseidere          #+#    #+#             */
/*   Updated: 2024/07/17 12:47:51 by jseidere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	check_type(t_game *game, char *str)
{
	int	len;

	len = len_until_sc(str, ' ');
	if (len > 2)
		return (false);
	if (is_fc(str))
	{
		if (!valid_color(game, str))
			return (false);
	}
	else if (is_dir(str))
	{
		if (!check_texture(game, str))
			return (false);
	}
	return (true);
}

bool	check_attributes(t_game *game)
{
	int		i;
	char	*norm_input;

	i = 0;
	norm_input = NULL;
	while (i < 6)
	{
		norm_input = norm_line(game->map[i]);
		if (!check_type(game, norm_input))
		{
			free(norm_input);
			return (false);
		}
		free(norm_input);
		i++;
	}
	if (game->map_param != 6)
		return (false);
	return (true);
}

//check if correct file
bool	right_path(char *path)
{
	int	fd;

	fd = open(path, O_RDONLY);
	if (fd < 0)
		return (false);
	else
	{
		close(fd);
		return (true);
	}
}
