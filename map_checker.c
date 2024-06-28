/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_checker.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jseidere <jseidere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/24 12:39:32 by jseidere          #+#    #+#             */
/*   Updated: 2024/06/28 10:36:12 by jseidere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

//check for right fileextension
bool    right_fileextension(char *file)
{
    char *extension;

    extension = strchr(file, '.');

    if(!strcmp(extension, ".cub"))
        return (true);
    else
        return (false);
}

//check row for allowed chars
bool only_allowed_chars(char *str)
{
    int i;

    i = 0;
    while(str[i])
    {
        if(str[i] != 'N' || str[i] != 'S' || str[i] != 'E' || str[i] != 'W' \
        || str[i] != '0' || str[i] != '1')
            return (false);
        i++;
    }
    return (true);
}

bool skip_spaces(char *str)
{
    while(*str)
    {
        if(*str == ' ')
            str++;
        else
            return (false);
    }
    return (true);
    
}

//check each row if no norm errors
bool check_row(char **map)
{
    int i;

    i = 0;

    while(map[i])
    {
        if(!only_allowed_chars(map[i]))
            return(false);
        i++;
    }
    return (true);
}

//check if surrounded by wall

int check_map(t_game *game, char *argv)
{    
    if(!right_fileextension(argv))
        perror("Wrong fileextension!\n");
    if(!check_row(game->map->map))
        perror("Map error!\n");

    return (0);
}