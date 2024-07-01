/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jseidere <jseidere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/24 12:36:26 by jseidere          #+#    #+#             */
/*   Updated: 2024/06/28 12:46:08 by jseidere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int free_map(char **map)
{
    int i;

    i = 0;
    
    while(map[i])
    {
        free(map[i]);
        i++;
    }
    free(map);
    return (0);
}

int ft_error(char *str, t_game *game)
{
    if(game->fd)
        close(game->fd);
    if(game->map)
        free_map(game->map);
    perror(str);
    return(0);
}