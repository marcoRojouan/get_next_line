/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loup <loup@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/29 22:09:23 by loup              #+#    #+#             */
/*   Updated: 2025/10/29 22:24:53 by loup             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

int main(void)
{
    char *line;
    char *line2;
    int fd;
    fd = open("file.txt", O_RDONLY);
    line = get_next_line(fd);
    printf("%s\n", line);
    line2 = get_next_line(fd);
    printf("%s\n", line2);
    close(fd);
}