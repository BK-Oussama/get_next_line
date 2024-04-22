/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ouboukou <ouboukou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/15 15:38:24 by ouboukou          #+#    #+#             */
/*   Updated: 2024/04/22 02:34:48 by ouboukou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdlib.h>
#include <unistd.h>

#define BUFFER_SIZE 15

char *ft_get_buffer(int fd, char *str)
{
	char *buffer;
	ssize_t read_bytes;
	char *tmp;
	buffer = malloc(sizeof(char) * ((size_t )BUFFER_SIZE + 1));
	if (!buffer)
		return NULL;
	read_bytes = 1;
	while (read_bytes != 0 && !ft_strchr(str, '\n'))
	{
		read_bytes = read(fd, buffer, BUFFER_SIZE);
		if (read_bytes <= 0)
			break;
		buffer[read_bytes] = '\0'; // Ensure buffer is null-terminated
		tmp = str;
		str = ft_strjoin(tmp, buffer);
		free(tmp);
	}
	free(buffer);
	if (read_bytes < 0)
	{
		free(str);
		str = NULL;
	}
	return (str);
}

// char *ft_get_line(char *str)
// {
	
// }

char	*get_next_line(int fd)
{
	static char	*where_read_stops;
	char		*line;
	char		*temp;
	char		*newline_pos;
	size_t		line_length;
	
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	where_read_stops = ft_get_buffer(fd, where_read_stops);
	if (where_read_stops == NULL)
		return (NULL);
	line = NULL;
	newline_pos = ft_strchr(where_read_stops, '\n');
	if (newline_pos)
	{
		line_length = (newline_pos - where_read_stops) + 1;
		line = ft_substr(where_read_stops, 0, line_length);
		temp = ft_strdup(newline_pos + 1);
		free(where_read_stops);
		where_read_stops = temp;
	}
	else
	{
		line = ft_strdup(where_read_stops);
		free(where_read_stops);
		where_read_stops = NULL;
	}
	return (line);
}
