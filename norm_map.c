/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   norm_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jseidere <jseidere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/03 15:23:09 by jseidere          #+#    #+#             */
/*   Updated: 2024/07/17 16:03:19 by jseidere         ###   ########.fr       */
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

char	*norm_line(char *str)
{
	int		i;
	int		j;
	char	*result;
	char	*tmp;

	i = 0;
	j = 0;
	if (!str)
		return (NULL);
	result = ft_strdup("");
	tmp = NULL;
	while (str[i])
	{
		skip_spaces(str, &i);
		tmp = ft_substr(str, i, len_until_sc(str + i, ' '));
		result = ft_strjoin(result, tmp);
		if (is_dir(tmp) || is_fc(tmp))
			result = ft_strjoin(result, " ");
		i += len_until_sc(str + i, ' ');
		skip_spaces(str, &i);
		free(tmp);
	}
	printf("Result: %s\n", result);
	return (result);
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
	while (game->map[i])
	{
		if (!is_empty(game->map[i]))
		{
			new_map[j] = ft_strdup(game->map[i]);
			j++;
		}
		i++;
	}
	new_map[j] = NULL;
	free_map(game->map);
	game->map = new_map;
	game->rows = j;
	print_td_array(game->map);
}
