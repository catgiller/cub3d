/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ervsahin <ervsahin@student.42kocaeli.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/03 14:10:10 by ervsahin          #+#    #+#             */
/*   Updated: 2026/06/03 14:16:31 by ervsahin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <stdio.h>

int main(int argc,char **argv)
{
    int fd = 0;
    if (argc != 2)
        perror("invalid arguments!");
    fd = open(argv[1], O_RDONLY);
    if (fd == -1)
        perror("opening file failed!");
    
}