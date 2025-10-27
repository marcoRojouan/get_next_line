/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loup <loup@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/27 15:41:20 by loup              #+#    #+#             */
/*   Updated: 2025/10/27 18:22:11 by loup             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdlib.h>
#include <fcntl.h>
# define BUFFER 5

int ft_strlen(char *str)
{
    int i;
    i = 0;
    while (str[i])
        i++;
    return (i);
}

int main(void)
{
    char error1[] = "erreur avec le fichier";
    char error2[] = "erreur de lecture";
    char c;
    unsigned long occ;
    // char buffer[BUFFER];
    unsigned long count;
    int newfd;
    
    occ = 0;
    newfd = open("file.txt", O_RDONLY);
    if (newfd == -1)
    {
        write(2, error1 , ft_strlen(error1));
        return (newfd);
    }
    while ((count = read(newfd, &c, 1)) > 0)
    {
        if (c == 'a')
            occ++;
        write(1, &c, count);
    }
    if (count == -1)
    {
        write(2, error2, ft_strlen(error2));
        return (count);
    }
    close(newfd);
    return (occ);
}