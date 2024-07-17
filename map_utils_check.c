/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils_check.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jseidere <jseidere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/02 11:11:01 by jseidere          #+#    #+#             */
/*   Updated: 2024/07/17 12:47:43 by jseidere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

bool	is_dir(char *str)
{
	int	len;

	len = len_until_sc(str, ' ');
	if (len != 2)
		return (false);
	if (!ft_strncmp(str, "NO", 2) || !ft_strncmp(str, "SO", 2) \
			|| !ft_strncmp(str, "WE", 2) || !ft_strncmp(str, "EA", 2))
		return (true);
	return (false);
}

bool	is_fc(char *str)
{
	int	len;

	len = len_until_sc(str, ' ');
	if (len != 1)
		return (false);
	if (ft_strchr(str, 'F') || ft_strchr(str, 'C'))
		return (true);
	return (false);
}

bool	check_texture(t_game *game, char *str)
{
	int		i;
	char	*dir;
	char	*path;

	i = 0;
	dir = NULL;
	path = NULL;
	if (!dir)
	{
		dir = ft_substr(str, i, 2);
		i += 3;
	}
	if (!path)
		path = ft_substr(str, i, ft_strlen(str + i));
	if (!valid_texture(game, path, dir))
	{
		free(dir);
		free(path);
		return (false);
	}
	free(dir);
	free(path);
	return (true);
}

bool	valid_texture(t_game *game, char *path, char *dir)
{
	game->map_param++;
	if (!ft_strncmp(dir, "NO", 2) && right_path(path))
	{
		game->texture[NORTH].path = ft_strdup(path);
		return (true);
	}
	else if (!ft_strncmp(dir, "SO", 2) && right_path(path))
	{
		game->texture[SOUTH].path = ft_strdup(path);
		return (true);
	}
	else if (!ft_strncmp(dir, "WE", 2) && right_path(path))
	{
		game->texture[WEST].path = ft_strdup(path);
		return (true);
	}
	else if (!ft_strncmp(dir, "EA", 2) && right_path(path))
	{
		game->texture[EAST].path = ft_strdup(path);
		return (true);
	}
	return (false);
}

bool	valid_color(t_game *game, char *str)
{
	int		i;
	char	*number;
	int		num;
	int		len;

	i = 2;
	number = NULL;
	while (str[i])
	{
		if (!ft_isdigit(str[i]))
			return (false);
		len = len_until_sc(str + i, ',');
		number = ft_substr(str, i, len);
		if (str[i + len] == ',')
			i += len + 1;
		else
			i += len;
		num = ft_atoi(number);
		free(number);
		if (num > 255 || num < 0)
			return (false);
	}
	game->map_param++;
	return (true);
}
