/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ervsahin <ervsahin@student.42kocaeli.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/02 00:00:00 by ervsahin          #+#    #+#             */
/*   Updated: 2026/08/03 14:29:19 by ervsahin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdlib.h>
#include <unistd.h>

static char	*join_and_free(char *s1, char *s2)
{
	char	*joined;
	size_t	len1;
	size_t	len2;

	len1 = 0;
	len2 = 0;
	if (s1)
		len1 = ft_strlen(s1);
	if (s2)
		len2 = ft_strlen(s2);
	joined = malloc(len1 + len2 + 1);
	if (!joined)
		return (NULL);
	if (s1)
		ft_memcpy(joined, s1, len1);
	if (s2)
		ft_memcpy(joined + len1, s2, len2);
	joined[len1 + len2] = '\0';
	free(s1);
	return (joined);
}

char	*get_next_line(int fd)
{
	static char	*stash = NULL;
	char		buffer[BUFFER_SIZE + 1];
	ssize_t		n;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	if (stash && ft_strchr(stash, '\n'))
		return (stash);
	n = read(fd, buffer, BUFFER_SIZE);
	if (n <= 0)
	{
		free(stash);
		stash = NULL;
		return (NULL);
	}
	buffer[n] = '\0';
	stash = join_and_free(stash, buffer);
	if (!stash)
		return (NULL);
	return (get_next_line(fd));
}
