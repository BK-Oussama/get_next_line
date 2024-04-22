/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus_main.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ouboukou <ouboukou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 21:10:51 by ouboukou          #+#    #+#             */
/*   Updated: 2024/04/22 22:29:15 by ouboukou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

int	main(void)
{
	int count;
	int i;
	char *str;
	int fd1, fd2, fd3;

	fd1 = open("file1.txt", O_RDONLY);
	fd2 = open("file2.txt", O_RDONLY);
	fd3 = open("file3.txt", O_RDONLY);
	str = NULL;
	count = 0;
	i = 0;
	printf("first fd\n");
	while (i < 3)
	{
		str = get_next_line_bonus(fd1);
		if (str == NULL)
			return (0);
		count++;
		i++;
		printf("Call number:\t%d\t\tLine:\t%s", count, str);
		free(str);
		str = NULL;
	}

	printf("second fd\n");
	i = 0;
	while (i < 3)
	{
		str = get_next_line_bonus(fd2);
		if (str == NULL)
			return (0);
		count++;
		i++;
		printf("Call number:\t%d\t\tLine:\t%s", count, str);
		free(str);
		str = NULL;
	}

	printf("Third fd\n");
	i = 0;
	while (i < 3)
	{
		str = get_next_line_bonus(fd3);
		if (str == NULL)
			return (0);
		count++;
		i++;
		printf("Call number:\t%d\t\tLine:\t%s", count, str);
		free(str);
		str = NULL;
	}

	return (0);
}