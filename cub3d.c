/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jseidere <jseidere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/24 12:24:37 by jseidere          #+#    #+#             */
/*   Updated: 2024/06/28 10:37:48 by jseidere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int main  (int argc, char **argv)
{
    t_game *game;
    (void) **argv;
    
    game = NULL;

    if(argc == 2)
    {
        init_map(game, argv[1]);
        check_map(game, argv[1]);
    }
    else
        perror("Wrong input!");
}