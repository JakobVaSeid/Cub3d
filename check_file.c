/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_file.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jseidere <jseidere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/02 12:40:54 by jseidere          #+#    #+#             */
/*   Updated: 2024/07/04 15:57:11 by jseidere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

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
		perror("Wrong fileextension!\n");
	if (!check_pos(game))
		perror("Invalid Map!");
	if (!check_row(game, game->map))
		perror("Map error!\n");
	if (game->player_amount != 1)
		perror("Wrong player amount!\n");
	if (!check_attributes(game))
		perror("Wrong map params!");
	return (0);
}
