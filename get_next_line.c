/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ouboukou <ouboukou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/15 15:38:24 by ouboukou          #+#    #+#             */
/*   Updated: 2024/04/24 23:55:09 by ouboukou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

// Function: read_file
// Description: Reads characters from a file descriptor into a string buffer.
// Parameters:
//   - fd: File descriptor to read from.
//   - str: String buffer to store the read characters.
// Return Value: A pointer to the updated string buffer.
char	*read_file(int fd, char *str)
{
	char	*buffer;
	ssize_t	read_bytes;
	char	*tmp;

	buffer = malloc(sizeof(char) * ((size_t)BUFFER_SIZE + 1));
	if (!buffer)
		return (NULL);
	read_bytes = 1;
	while (read_bytes != 0 && !ft_strchr(str, '\n'))
	{
		read_bytes = read(fd, buffer, BUFFER_SIZE);
		if (read_bytes <= 0)
			break ;
		buffer[read_bytes] = '\0';
		tmp = str;
		str = ft_strjoin(tmp, buffer);
		free(tmp);
	}
	if (read_bytes < 0 || !str || ft_strlen(str) == 0) //This condition handles the case when the read function reaches the end-of-file (EOF). Within the loop above, we set the last character of the buffer to '\0' to ensure that it forms a valid null-terminated string.
	{
		free(str);
		str = NULL;
	}
	return (free(buffer), str);
}

// Function: extract_line
// Description: Extracts a line from the string buffer up to the newline character '\n'.
// Parameters:
//   - str: Pointer to the string buffer.
// Return Value: A pointer to the extracted line.

char	*extract_line(char **str)
{
	char	*new_line_postion;
	char	*valid_line;
	size_t	sub_line_lenght;
	char	*tmp;

	new_line_postion = ft_strchr(*str, '\n');
	valid_line = NULL;
	if (new_line_postion)
	{
		sub_line_lenght = (size_t)(new_line_postion - *str) + 1;
		valid_line = ft_substr(*str, 0, sub_line_lenght);
		tmp = ft_strdup(new_line_postion + 1);
		free(*str);
		*str = tmp;
	}
	else
	{
		valid_line = ft_strdup(*str);
		free(*str);
		*str = NULL;
	}
	return (valid_line);
}

// Function: get_next_line
// Description: Reads the next line from the file descriptor.
// Parameters:
//   - fd: File descriptor to read from.
// Return Value: A pointer to the next line read from the file descriptor.

char	*get_next_line(int fd)
{
	static char	*where_read_stops;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	where_read_stops = read_file(fd, where_read_stops);
	if (where_read_stops == NULL)
		return (NULL);
	line = extract_line(&where_read_stops);
	return (line);
}
