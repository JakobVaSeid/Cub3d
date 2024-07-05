/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils_check.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jseidere <jseidere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/02 11:11:01 by jseidere          #+#    #+#             */
/*   Updated: 2024/07/05 11:06:19 by jseidere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

bool is_dir(char *str)
{
	int len;

	len = len_until_sc(str, ' ');
	if(len != 2)
		return (false);
	if (!ft_strncmp(str, "NO", 2) || !ft_strncmp(str, "SO", 2) \
			|| !ft_strncmp(str, "WE", 2) || !ft_strncmp(str, "EA", 2))
		return (true);
	return (false);
}

bool is_fc(char *str)
{
	int len;

	len = len_until_sc(str, ' ');
	if(len != 1)
		return (false);
	if(ft_strchr(str, 'F') || ft_strchr(str, 'C'))
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
	if(!dir)
	{
		dir = ft_substr(str, i, 2);
		i += 3;
	}
	if(!path)
		path = ft_substr(str, i, ft_strlen(str + i));
	if(!valid_texture(game, path, dir))
	{
		free(dir);
		free(path);
		return (false);
	}
	free(dir);
	free(path);
	return (true);
}

int	xpm_to_img(void *mlx, char *path, void **img)
{
	int	height;
	int	width;

	*img = mlx_xpm_file_to_image(mlx, path, &height, &width);
	if (*img == 0)
		return (0);
	return (1);
}

bool valid_texture(t_game *game, char *path, char *dir)
{
	if(!ft_strncmp(dir, "NO", 2))
		game->texture[NORTH].path = ft_strdup(path);
	else if(!ft_strncmp(dir, "SO", 2))
		game->texture[SOUTH].path = ft_strdup(path);
	else if(!ft_strncmp(dir, "WE", 2))
		game->texture[WEST].path = ft_strdup(path);
	else if(!ft_strncmp(dir, "EA", 2))
		game->texture[EAST].path = ft_strdup(path);
	return (true);
}

bool valid_color(char *str)
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
	return (true);
}

int check_type(t_game *game, char *str)
{
	int len;

	len = len_until_sc(str, ' ');
	if(len > 2)
		return (false);
	if(is_fc(str))
	{
		if(!valid_color(str))
			return(false);
	}
	else if(is_dir(str))
	{
		if(!check_texture(game, str))
			return (false);
	}
	return (true);
}

bool	check_attributes(t_game *game)
{
	int	i;
	char *norm_input;

	i = 0;
	norm_input = NULL;
	while (i < 6)
	{
		norm_input = norm_line(game->map[i]);
		printf("Norm_Input: %s\n", norm_input);
		if(!check_type(game, norm_input))
		{
			free(norm_input);
			return (false);
		}
		free(norm_input);
		/* if (!check_texture(game, game->map[i]))
			return (false); */
		i++;
	}
	return (true);
}
