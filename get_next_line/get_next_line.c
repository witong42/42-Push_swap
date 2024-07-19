/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: witong <witong@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/19 16:45:00 by witong            #+#    #+#             */
/*   Updated: 2024/07/20 01:27:02 by witong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*extract(char **cache)
{
	char	*line;
	char	*tmp;
	size_t	i;

	i = 0;
	while ((*cache)[i] || (*cache)[i] != '\n')
		i++;
	line =
	tmp =
	free(*cache);
	*cache = tmp;
	return (line);
}

static char	*read_line_cache(int fd, char **cache)
{
	char	buffer[BUFFER_SIZE + 1];
	ssize_t	read_line;
	char	*tmp;

	if (!*cache)
		*cache = ft_strdup("");
	read_line = 1;
	while (read_line > 0)
	{
		read_line = read(fd, buffer, BUFFER_SIZE);
		buffer[read_line] = '\0';
		tmp = *cache;
		*cache = ft_strjoin(tmp, buffer);
		free(tmp);
		if (ft_strchr(buffer, '\n'))
			break;
	}
	if (b_read < 0 || (!**cache && read_line == 0))
	{
		free (*cache);
		*cache = NULL;
		return (NULL);
	}
	return (extract(cache));
}

char	*get_next_line(int fd)
{
	char		*line;
	static char	*cache;

	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0) < 0)
		return (NULL);
	line = read_line_cache(fd, &cache);
	if (!line)
		return (NULL);
	return (line);
}
