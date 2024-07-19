/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   norm_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jseidere <jseidere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/03 15:23:09 by jseidere          #+#    #+#             */
/*   Updated: 2024/07/19 15:10:50 by jseidere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	len_until_sc(char *str, char c)
{
	int	i;

	i = 0;
	while (str[i] && str[i] != c)
		i++;
	return (i);
}

char	*norm_line(t_game *game, char *str)
{
	int		i;
	char	*result;
	char	*tmp;
	char	*tmp2;

	i = 0;
	if (!str)
		return (NULL);
	result = ft_strdup("");
	if (!result)
		return (NULL);
	tmp = NULL;
	while (str[i])
	{
		skip_spaces(str, &i);
		tmp = ft_substr(str, i, len_until_sc(str + i, ' ')); //protection
		concat_string(&result, &tmp2, tmp);
		if (is_dir(game, tmp) || is_fc(game, tmp))
			concat_string(&result, &tmp2, " ");
		i += len_until_sc(str + i, ' ');
		skip_spaces(str, &i);
		free(tmp);
	}
	return (result);
}

void	concat_string(char **result, char **tmp2, char *tmp)
{
	*tmp2 = ft_strdup(*result);
	free(*result);
	*result = ft_strjoin(*tmp2, tmp);
	free(*tmp2);
}

//delete lines with only spaces
bool	is_empty(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] != ' ')
			return (false);
		i++;
	}
	return (true);
}

//delete empty lines
void	norm_map(t_game *game)
{
	int		i;
	int		j;
	char	**new_map;

	i = 0;
	j = 0;
	new_map = malloc(sizeof(char *) * (game->rows + 1));
	if (!new_map)
		ft_error("Norm map failed!", game);
	while (game->map[i])
	{
		if (!is_empty(game->map[i]))
		{
			new_map[j] = ft_strdup(game->map[i]);
			if (!new_map[j])
			{
				free_map(new_map);
				ft_error("Creating normed map failed!", game);
			}
			j++;
		}
		i++;
	}
	new_map[j] = NULL;
	free_map(game->map);
	game->map = new_map;
	game->rows = j;
}
