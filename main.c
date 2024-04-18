/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ouboukou <ouboukou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/16 18:39:27 by ouboukou          #+#    #+#             */
/*   Updated: 2024/04/18 19:30:08 by ouboukou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int main()
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
			break;
		count++;
		printf("[%d]: %s\n", count, new_line);
		free(new_line);
		new_line = NULL;
	}
	close(fd);
	return (0);
}


// int main()
// {
//    // int i;

// 	char *str;
// 	int fd;
// 	fd = open("file.txt", O_RDONLY);
//     str = get_next_line(fd);
//     // printf("Main:\t%s\n", str);
    
// 	// size_t length;
//     // i = 0;
//     // while(1)
//     // {
//     //     str = get_next_line(fd);
// 	//     if (NULL == str)
//     //         break;
//     //     i++;
//     //     length = ft_strlen(str);
//     //     printf("System Call Number #%d\tString Length: %ld\tOutput:\t%s\n\n",i, length, str);
//     //     free(str);
//     //     str = NULL;
//     // }
    
//     close(fd);
// 	return 0;
// }
