/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ouboukou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/15 17:19:19 by ouboukou          #+#    #+#             */
/*   Updated: 2024/04/15 19:52:46 by ouboukou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int main()
{
	int fd;
	char *str;
	fd = open("file.txt", O_RDONLY);
	str = get_next_line(fd);
	printf("output:\t", str);
	return 0;

