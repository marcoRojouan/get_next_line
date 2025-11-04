/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrojouan <mrojouan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/29 22:09:23 by loup              #+#    #+#             */
/*   Updated: 2025/11/04 11:01:20 by mrojouan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

int main(void)
{
	char *line;
	// char *line3;
	int fd;
	fd = open("file.txt", O_RDONLY);
	line = get_next_line(fd);
	while(line)
	{
		printf("%s\n", line);
		free(line);
		line = get_next_line(fd);
	}	
	close(fd);
}
