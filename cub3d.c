/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jseidere <jseidere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/24 12:24:37 by jseidere          #+#    #+#             */
/*   Updated: 2024/06/28 12:43:56 by jseidere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void init_var(t_game *game)
{
    game->fd = 0;
    game->map = NULL;
   //game->map->map = NULL;
}

int main  (int argc, char **argv)
{
    t_game game;
    (void) **argv;
    

    if(argc == 2)
    {
        init_var(&game);
        init_map(&game, argv[1]);
        print_2D_array(game.map);
        check_map(&game, argv[1]);
    }
    else
        perror("Wrong input!");
}