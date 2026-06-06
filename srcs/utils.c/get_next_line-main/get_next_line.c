/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ervsahin <ervsahin@student.42kocaeli.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/25 17:42:05 by ervsahin          #+#    #+#             */
/*   Updated: 2025/07/30 15:11:59 by ervsahin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include "get_next_line.h"

void	free_all(char **stash)
{
	if (stash && *stash)
	{
		free(*stash);
		*stash = NULL;
	}
}

char	*read_and_store(int fd, char **stash)
{
	ssize_t		byt_read;
	char		*buf;
	char		*tmp;

	byt_read = 1;
	while ((!*stash || !ft_strchr(*stash, '\n')) && byt_read > 0)
	{
		buf = malloc(BUFFER_SIZE + 1);
		if (!buf)
			return (free_all(stash), NULL);
		byt_read = read(fd, buf, BUFFER_SIZE);
		if (byt_read < 0 || (byt_read == 0 && !*stash))
		{
			free(buf);
			return (free_all(stash), NULL);
		}
		buf[byt_read] = '\0';
		tmp = *stash;
		*stash = ft_strjoin(tmp, buf);
		free(tmp);
		free(buf);
		if (!*stash)
			return (free_all(stash), NULL);
	}
	return (*stash);
}

char	*extract_line(char *stash)
{
	int		i;
	char	*line;

	i = 0;
	if (!stash)
		return (NULL);
	while (stash[i] != '\n' && stash[i] != '\0')
		i++;
	if (stash[i] == '\n')
		line = ft_substr(stash, 0, i + 1);
	else
		line = ft_substr(stash, 0, ft_strlen(stash));
	if (!line)
		return (NULL);
	return (line);
}

char	*update_stash(char **stash)
{
	char	*tmp;
	int		len;

	if (!stash || !*stash)
		return (NULL);
	if (ft_strchr(*stash, '\n'))
		len = ft_strlen(ft_strchr(*stash, '\n') + 1);
	else
		return (free_all(stash), NULL);
	tmp = malloc(len + 1);
	if (!tmp)
		return (free_all(stash), NULL);
	ft_strlcpy(tmp, ft_strchr(*stash, '\n') + 1, len + 1);
	free_all(stash);
	return (tmp);
}

char	*get_next_line(int fd)
{
	static char	*stash;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	stash = read_and_store(fd, &stash);
	if (!stash)
		return (NULL);
	if (ft_strlen(stash) == 0)
		return (free_all(&stash), NULL);
	line = extract_line(stash);
	if (!line)
		return (free_all(&stash), NULL);
	stash = update_stash(&stash);
	return (line);
}
