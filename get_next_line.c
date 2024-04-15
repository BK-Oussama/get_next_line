/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ouboukou <ouboukou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/15 15:38:24 by ouboukou          #+#    #+#             */
/*   Updated: 2024/04/15 20:10:07 by ouboukou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include "get_next_line.h"

#include<unistd.h>
#include<fcntl.h>
#include<stdio.h>
#include<stdlib.h>
# define BUFFER_SIZE 3

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i] != '\0')
	{
		i++;
	}
	return (i);
}

char	*ft_strdup(const char *str)
{
	size_t	len;
	char	*ptr;
	size_t	i;

	len = ft_strlen(str);
	ptr = malloc((len + 1) * (sizeof(char)));
	if (ptr == NULL)
		return (NULL);
	i = 0;
	while (str[i])
	{
		ptr[i] = str[i];
		i++;
	}
	ptr[i] = '\0';
	return (ptr);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	j;
	size_t	i;
	char	*str;

	i = 0;
	if (s == NULL)
		return (ft_strdup(""));
	j = ft_strlen(s);
	while (i + start < j && i < len)
		i++;
	str = malloc(i + 1);
	if (str == NULL)
		return (0);
	j = 0;
	while (i > 0)
	{
		str[j++] = s[start++];
		i--;
	}
	str[j] = '\0';
	return (str);
}

char	*ft_strchr(const char *s, int arg)
{
	while (*s && *s != (char)arg)
	{
		s++;
		if (*s == (char)arg)
		{
			return ((char *)s);
		}
	}
	if (*s == (char)arg)
	{
		return ((char *)s);
	}
	return (NULL);
}

size_t	ft_strlcpy(char *dest, const char *src, size_t dsize)
{
	size_t	i;

	i = 0;
	if (src && !dsize)
		return (ft_strlen(src));
	while (i < dsize - 1 && src[i] != '\0')
	{
		dest[i] = src[i];
		i++;
	}
	if (i < dsize)
	{
		dest[i] = '\0';
	}
	while (src[i] != '\0')
	{
		i++;
	}
	return (i);
}

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	unsigned int	i;
	unsigned int	j;
	unsigned int	dest_length;
	unsigned int	src_length;

	if (dest == NULL && size == 0)
		return (ft_strlen(src));
	dest_length = ft_strlen(dest);
	src_length = ft_strlen(src);
	j = ft_strlen(dest);
	if (dest_length >= size || size == 0)
		return (size + src_length);
	i = 0;
	while (i < (size - j - 1) && src[i] != '\0')
	{
		dest[dest_length] = src[i];
		i++;
		dest_length++;
	}
	dest[dest_length] = '\0';
	return (j + src_length);
}

char	*ft_strjoin(const char *s1, const char *s2)
{
	size_t	len;
	char	*str;

	if (s1 == NULL || s2 == NULL)
		return (NULL);
	len = ft_strlen(s1) + ft_strlen(s2);
	str = malloc((len + 1) * sizeof(char));
	if (str == NULL)
		return (NULL);
	ft_strlcpy(str, s1, len + 1);
	ft_strlcat(str, s2, len + 1);
	return (str);
}


char	*get_next_line(int fd)
{
	static char		*reads;
	char			buffer[BUFFER_SIZE];
	ssize_t			rd;
	unsigned int	i;
	char			*valid_line;

	if (-1 == fd)	// in case open() fail to return a valid FD!
		return (NULL);

	rd = read(fd, buffer, BUFFER_SIZE + 1);
	if (rd <= 0)	// end of file has reached || or error occured while using read()!!
		return (NULL);
	if (rd > 0)
		valid_line = ft_strdup(buffer);
	i = 0;
	while (valid_line[i])
	{
		if ((valid_line[i] != '\0' || valid_line[i] != '\n'))
			i++;
		else
			valid_line = ft_substr(valid_line, 0, i);
	}
	reads = ft_strjoin(reads, valid_line);
	return (reads);
}

int main()
{
	int fd;
	char *str;
	fd = open("file.txt", O_RDONLY);
	str = get_next_line(fd);
	printf("output:\t\t%s", str);
	close(fd);
	return 0;

}
