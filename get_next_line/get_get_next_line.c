#include "get_next_line.h"

static char *extract_line_from_cache(char **cache)
{
    char *line;
    char *temp;
    size_t i;

    i = 0;
    while ((*cache)[i] && (*cache)[i] != '\n')
        i++;
    line = ft_substr(*cache, 0, i + ((*cache)[i] == '\n'));
    temp = ft_strdup(&(*cache)[i + ((*cache)[i] == '\n' ? 1 : 0)]);
    free(*cache);
    *cache = temp;
    return (line);
}

static char *read_line_cache(int fd, char **cache)
{
    char    buffer[BUFFER_SIZE + 1];
    ssize_t bytes_read;
    char    *temp;

    if (!*cache)
        *cache = ft_strdup("");
    while ((bytes_read = read(fd, buffer, BUFFER_SIZE)) > 0)
    {
        buffer[bytes_read] = '\0';
        temp = *cache;
        *cache = ft_strjoin(temp, buffer);
        free(temp);
        if (ft_strchr(buffer, '\n'))
            break;
    }
    if (bytes_read < 0 || (**cache == '\0' && bytes_read == 0))
    {
        free(*cache);
        *cache = NULL;
        return (NULL);
    }
    return (extract_line_from_cache(cache));
}

char *get_next_line(int fd)
{
    static char *cache = NULL;
    char        *line;

    if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0) < 0)
        return (NULL);
    line = read_line_cache(fd, &cache);
    if (!line || *line == '\0')
    {
        free(line);
        return (NULL);
    }
    return (line);
}
