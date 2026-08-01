/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ervsahin <ervsahin@student.42kocaeli.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/03 14:10:10 by ervsahin          #+#    #+#             */
/*   Updated: 2026/08/01 02:25:46 by ervsahin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "../cub3d.h"

int main(int argc,char **argv)
{
    t_game game;

    if (argc != 2)
    {
        print_error("invalid arguments!");
        return(1);
    }
    parser(&game, argv[1]);
    
    
    
    
}