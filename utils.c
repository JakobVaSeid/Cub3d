/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jseidere <jseidere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/28 11:53:58 by jseidere          #+#    #+#             */
/*   Updated: 2024/07/02 12:50:59 by jseidere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	print_td_array(char **str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		printf("%s\n", str[i]);
		i++;
	}
	return (0);
}

//skip spaces
bool	skip_spaces(char *str, int *j)
{
	while (str[*j])
	{
		if (str[*j] == ' ')
			(*j)++;
		else
			return (false);
	}
	return (true);
}

//check parameter
void	count_player(t_game *game, char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (ft_strchr("NSWE", str[i]))
			game->player++;
		i++;
	}
}
