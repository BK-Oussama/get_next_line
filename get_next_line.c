/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ouboukou <ouboukou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/15 15:38:24 by ouboukou          #+#    #+#             */
/*   Updated: 2024/04/18 23:48:11 by ouboukou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */





#include <unistd.h>
#include <stdlib.h>
#include "get_next_line.h"

#define BUFFER_SIZE 1

char	*get_next_line(int fd)
{
	static char	*where_read_stops = NULL;
	char		buffer[BUFFER_SIZE + 1];
	char		*line = NULL;
	ssize_t		read_bytes;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);

	if (!where_read_stops)
		where_read_stops = ft_strdup("");

	while ((read_bytes = read(fd, buffer, BUFFER_SIZE)) > 0)
	{
		buffer[read_bytes] = '\0'; // Ensure buffer is null-terminated
		where_read_stops = ft_strjoin(where_read_stops, buffer);
		if (strchr(buffer, '\n'))
			break; // Stop reading if newline is found
	}

	if (read_bytes < 0 || !*where_read_stops)
	{
		free(where_read_stops);
		return (NULL); // Error or end of file reached
	}

	// Extract line from where_read_stops
	char *newline_pos = strchr(where_read_stops, '\n');
	if (newline_pos)
	{
		size_t line_length = newline_pos - where_read_stops;
		line = ft_substr(where_read_stops, 0, line_length);
		char *temp = ft_strdup(newline_pos + 1); // Save the remaining part for next call
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































// #include "get_next_line.h"
// # define BUFFER_SIZE 3

// char	*get_next_line(int fd)
// {
// 	static char	    	*where_read_stops;		//that whre we gonna store what read() gets.
// 	char		    	buffer[BUFFER_SIZE + 1];	// buffer_size + 1 to make sure to null terminate the string.
// 	char				*valid_line = NULL;
// 	ssize_t		    	read_bytes;				// to store the return values from read().

// 	if (-1 == fd || BUFFER_SIZE <= 0)	// in case open() fail to return a valid FD!
// 		return (NULL);

// 	read_bytes = read(fd, buffer, BUFFER_SIZE);
// 		if (read_bytes <= 0)	// EOF has reached || or error occured while using read()!!
// 			return (NULL);
			
// 	while (!(strchr(buffer, '\n')))
// 	{
// 		valid_line = ft_strjoin(valid_line, buffer);
// 		bzero(buffer, BUFFER_SIZE);
// 		read_bytes = read(fd, buffer, BUFFER_SIZE);
// 			if (read_bytes <= 0)	// EOF has reached || or error occured while using read()!!
// 				return (NULL);
// 	}

// 	char *temp;
// 	if (temp = strchr(buffer, '\n'))
// 	{
// 		size_t length = temp - buffer;
// 		where_read_stops = temp + 1;
// 		char *valid = ft_substr(buffer, 0, length);
// 		valid_line = ft_strjoin (valid_line, valid);
// 	}

// 	return (where_read_stops);
// }