/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echoubby <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 13:55:06 by echoubby          #+#    #+#             */
/*   Updated: 2023/12/11 13:57:15 by echoubby         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <fcntl.h>
#include "get_next_line.h"

int main(void)
{
	char		*line;
	int		fd;
	int		i;

	i = 0;
	fd = open("file.txt", O_RDONLY);
	while (i < 10)
	{
		line = get_next_line(fd);
		printf("===========================( main )===========================\n");
		printf("%s", line);
		printf("\n==============================================================\n");
		free(line);
		i++;
	}
	system ("leaks a.out");
	return (0);
}
