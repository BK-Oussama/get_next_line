/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ouboukou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/14 15:51:34 by ouboukou          #+#    #+#             */
/*   Updated: 2024/04/14 18:29:15 by ouboukou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

char	*get_next_line(int fd)
{
	int			bytes_read;
	char		*small_buff;
	static int	count = 1;

	printf("Calloc: [%d]\t", count++);
	small_buff = calloc(3 + 1, sizeof(char));
	if (!small_buff)
		return (NULL);
	bytes_read = read(fd, small_buff, 3);
	if (bytes_read <= 0)
	{
		free(small_buff);
		return (NULL);
	}
	return (small_buff);
}

int	main(void)
{
	int		fd;
	char	*new_txt;
	int		count;

	count = 0;
	fd = open("message.txt", O_RDONLY);
	while (1)
	{
		new_txt = get_next_line(fd);
		if (new_txt == NULL)
			break ;
		count++;
		printf("[%d]: %s\n", count, new_txt);
		free(new_txt);
		new_txt = NULL;
	}
	close(fd);
	return (0);
}
