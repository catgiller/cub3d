/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ervsahin <ervsahin@student.42kocaeli.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/03 14:31:29 by ervsahin          #+#    #+#             */
/*   Updated: 2026/08/03 14:31:32 by ervsahin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "libft.h"

static void	write_num(int n, int fd)
{
	char	digit;

	if (n >= 10)
		write_num(n / 10, fd);
	digit = '0' + (n % 10);
	write(fd, &digit, 1);
}

void	ft_putnbr_fd(int n, int fd)
{
	if (n < 0)
	{
		write(fd, "-", 1);
		write_num(-n, fd);
	}
	else
		write_num(n, fd);
}
