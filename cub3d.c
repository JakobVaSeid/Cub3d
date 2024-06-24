/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jseidere <jseidere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/24 12:24:37 by jseidere          #+#    #+#             */
/*   Updated: 2024/06/24 12:45:00 by jseidere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int main  (int argc, char **argv)
{
    //t_game *cub3d;
    (void) **argv;
    
    if(argc == 2)
    {
        printf("Hello World");
    }
    else
        perror("Wrong input!");
}