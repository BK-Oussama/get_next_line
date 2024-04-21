/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ouboukou <ouboukou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/15 15:38:24 by ouboukou          #+#    #+#             */
/*   Updated: 2024/04/21 18:29:26 by ouboukou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdlib.h>
#include <unistd.h>

#define BUFFER_SIZE 50

char	*get_next_line(int fd)
{
	static char	*where_read_stops = NULL;
	char		*line;
	char		*temp;
	char		buffer[BUFFER_SIZE];
	ssize_t		read_bytes;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	if (!where_read_stops)
		where_read_stops = ft_strdup("");

	temp = NULL;
	read_bytes = read(fd, buffer, BUFFER_SIZE);
	while (read_bytes > 0)
	{
		buffer[read_bytes] = '\0'; // Ensure buffer is null-terminated
		temp = where_read_stops;
		where_read_stops = ft_strjoin(where_read_stops, buffer);
		free(temp);
		if (ft_strchr(buffer, '\n'))
			break; // Stop reading if newline is found
		read_bytes = read(fd, buffer, BUFFER_SIZE);	
	}

	if (read_bytes < 0 || !*where_read_stops)
	{
		
		return (free(where_read_stops), NULL); // Error or end of file reached
	}
	
	// Extract line from where_read_stops
	line = NULL;
	char		*newline_pos;
	size_t		line_length;
	newline_pos = ft_strchr(where_read_stops, '\n');
	if (newline_pos)
	{
		line_length = newline_pos - where_read_stops;
		line = ft_substr(where_read_stops, 0, line_length);
		char *temp = ft_strdup(newline_pos + 1);
			// Save the remaining part for next call
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