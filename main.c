/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ouboukou <ouboukou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/16 18:39:27 by ouboukou          #+#    #+#             */
/*   Updated: 2024/04/21 00:55:35 by ouboukou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	main(void)
{
	int		fd;
	char	*new_line;
	int		count;

	count = 0;
	fd = open("file.txt", O_RDONLY);
	while (1)
	{
		new_line = get_next_line(fd);
		if (new_line == NULL)
			break ;
		count++;
		printf("[%d]: %s\n", count, new_line);
		free(new_line);
		new_line = NULL;
	}
	close(fd);
	return (0);
}
