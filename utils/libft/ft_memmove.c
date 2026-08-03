/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ervsahin <ervsahin@student.42kocaeli.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/03 14:31:59 by ervsahin          #+#    #+#             */
/*   Updated: 2026/08/03 14:32:00 by ervsahin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char	*dst;
	unsigned char	*src_ptr;

	dst = (unsigned char *)dest;
	src_ptr = (unsigned char *)src;
	if (dst < src_ptr)
	{
		while (n--)
			*dst++ = *src_ptr++;
	}
	else
	{
		dst += n;
		src_ptr += n;
		while (n--)
			*--dst = *--src_ptr;
	}
	return (dest);
}
