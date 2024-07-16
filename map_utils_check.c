/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils_check.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caigner <caigner@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/02 11:11:01 by jseidere          #+#    #+#             */
/*   Updated: 2024/07/16 12:38:18 by caigner          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

bool	check_texture(char *str)
{
	int		i;
	char	*dir;

	i = 0;
	dir = NULL;
	while (str[i])
	{
		if (str[i] == ' ')
			skip_spaces(str, &i);
		dir = ft_substr(str, i, 2);
		if (!ft_strncmp(dir, "NO", 2) || !ft_strncmp(dir, "SO", 2) \
			|| !ft_strncmp(dir, "WE", 2) || !ft_strncmp(dir, "EA", 2))
		{
			free(dir);
			return (true);
		}
		else
			break ;
	}
	free(dir);
	return (false);
}

void	add_texture(t_texture *texture, char *str)
{
	char	**s;

	s = ft_split(str, ' ');
	texture->path = ft_strdup(s[1]);
	ft_free_split(s);
}

bool	check_attributes(t_game *game)
{
	int	i;

	i = 0;
	while (i < 4)
	{
		if (!check_texture(game->map[i]))
			return (false);
		add_texture(game->texture[i], game->map[i]);
		i++;
	}
	return (true);
}
