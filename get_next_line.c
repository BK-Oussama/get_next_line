/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ouboukou <ouboukou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/15 15:38:24 by ouboukou          #+#    #+#             */
/*   Updated: 2024/04/22 02:56:09 by ouboukou         ###   ########.fr       */
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

char *ft_get_line(char **str)
{
	char *new_line_postion;
	char *valid_line;
	size_t sub_line_lenght;
	
	new_line_postion = ft_strchr(*str, '\n');
	valid_line = NULL;
	if(new_line_postion)
	{
		sub_line_lenght = (size_t)(new_line_postion - *str) + 1;
		valid_line = ft_substr(*str, 0, sub_line_lenght);
		char *tmp = ft_strdup(new_line_postion + 1);
		free(*str);
		*str = tmp;
	}
	else
	{
		valid_line = ft_strdup(*str);
		free (*str);
		*str = NULL;
	}
	return (valid_line);
}

char	*get_next_line(int fd)
{
	static char	*where_read_stops;
	char		*line;
		
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
		
	where_read_stops = ft_get_buffer(fd, where_read_stops);
	if (where_read_stops == NULL)
		return (NULL);

	line = ft_get_line(&where_read_stops);
	return (line);	

}

