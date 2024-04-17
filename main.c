/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ouboukou <ouboukou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/16 18:39:27 by ouboukou          #+#    #+#             */
/*   Updated: 2024/04/17 18:06:29 by ouboukou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"



int main()
{
   // int i;

	char *str;
	int fd;
	fd = open("file.txt", O_RDONLY);
    str = get_next_line(fd);
    // printf("Main:\t%s\n", str);
    
	// size_t length;
    // i = 0;
    // while(1)
    // {
    //     str = get_next_line(fd);
	//     if (NULL == str)
    //         break;
    //     i++;
    //     length = ft_strlen(str);
    //     printf("System Call Number #%d\tString Length: %ld\tOutput:\t%s\n\n",i, length, str);
    //     free(str);
    //     str = NULL;
    // }
    
    close(fd);
	return 0;
}
