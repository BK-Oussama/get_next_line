/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ouboukou <ouboukou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/16 18:39:27 by ouboukou          #+#    #+#             */
/*   Updated: 2024/04/22 02:01:24 by ouboukou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	main(void)
{
	int		fd;
	char	*new_line;
	int		count;
	int i = 0;

	count = 0;
	fd = open("file.txt", O_RDONLY);
	while (i < 3)
	{
		new_line = get_next_line(fd);
		if (new_line == NULL)
			break ;
		count++;
		printf("[%d]: %s", count, new_line);
		free(new_line);
		new_line = NULL;
		i++;
	}
	close(fd);
	return (0);
}
