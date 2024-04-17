/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ouboukou <ouboukou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/15 15:38:24 by ouboukou          #+#    #+#             */
/*   Updated: 2024/04/17 19:25:07 by ouboukou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
# define BUFFER_SIZE 5

char	*get_next_line(int fd)
{
	static char	    	*where_read_stops;						//that whre we gonna store what read() gets.
	char		    	buffer[BUFFER_SIZE];	// buffer_size + 1 to make sure to null terminate the string.
	ssize_t		    	read_bytes;					// to store the return values from read().

	if (-1 == fd)	// in case open() fail to return a valid FD!
		return (NULL);

	read_bytes = read(fd, buffer, BUFFER_SIZE);
		if (read_bytes <= 0)	// EOF has reached || or error occured while using read()!!
			return (NULL);
			
	while (!(strchr(buffer, '\n')))
	{
		where_read_stops = ft_strjoin(where_read_stops, buffer);
		bzero(buffer, BUFFER_SIZE);
		read_bytes = read(fd, buffer, BUFFER_SIZE);
			if (read_bytes <= 0)	// EOF has reached || or error occured while using read()!!
				return (NULL);
	}

	char *temp;
	if (temp = strchr(buffer, '\n'))
	{
		size_t length = temp - buffer;
		char *valid = ft_substr(buffer, 0, length);
		printf("valid content:\t%s\n", valid);
		where_read_stops = ft_strjoin (where_read_stops, valid);
		printf("2 Debuging:\t%s", where_read_stops);
	}


	return (where_read_stops);
}
