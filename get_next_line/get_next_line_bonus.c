/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: witong <witong@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/19 16:45:00 by witong            #+#    #+#             */
/*   Updated: 2024/07/21 23:32:31 by witong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

static char	*extract_line(char **cache)
{
	char	*line;
	char	*tmp;
	size_t	i;

	i = 0;
	while ((*cache)[i] && (*cache)[i] != '\n')
		i++;
	if ((*cache)[i] == '\n')
	{
		line = ft_substr(*cache, 0, i + 1);
		tmp = ft_strdup(*cache + i + 1);
	}
	else
	{
		line = ft_strdup(*cache);
		tmp = NULL;
	}
	free(*cache);
	*cache = tmp;
	return (line);
}

static ssize_t	read_and_cache(char **cache, int fd)
{
	char	buffer[BUFFER_SIZE + 1];
	ssize_t	read_size;
	char	*tmp;

	read_size = read(fd, buffer, BUFFER_SIZE);
	while (read_size > 0)
	{
		buffer[read_size] = '\0';
		if (!*cache)
		{
			*cache = ft_strdup("");
		}
		tmp = ft_strjoin(*cache, buffer);
		free(*cache);
		*cache = tmp;
		if (ft_strchr(buffer, '\n'))
			break ;
		read_size = read(fd, buffer, BUFFER_SIZE);
	}
	return (read_size);
}

char	*get_next_line(int fd)
{
	static char	*cache[MAX_FD];
	ssize_t		read_size;

	if (fd < 0 || fd >= MAX_FD || BUFFER_SIZE <= 0)
		return (NULL);
	read_size = read_and_cache(&cache[fd], fd);
	if (read_size < 0 || !cache[fd] || !cache[fd][0])
	{
		free(cache[fd]);
		cache[fd] = NULL;
		return (NULL);
	}
	return (extract_line(&cache[fd]));
}
