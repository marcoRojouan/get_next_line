/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrojouan <mrojouan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/27 15:41:20 by loup              #+#    #+#             */
/*   Updated: 2025/10/28 17:12:29 by mrojouan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char *get_buffer(char *buffer, int fd)
{
    int read_count;
    char error2[] = "erreur de lecture";

    read_count = 0;
    read_count = read(fd, buffer, BUFFER);
    if (read_count == -1)
    {    
        write(2, error2 , ft_strlen(error2));
        return (NULL);
    }
    buffer[read_count] = '\0';
    return (buffer);
}

char *get_next_line(int fd)
{
    char *buffer;

    buffer = malloc(sizeof(char) * (BUFFER + 1));
    if (!buffer)
        return (NULL);
    if (fd < 0)
        return (NULL);
    if (BUFFER <= 0)
        return (NULL);
    buffer = get_buffer(buffer, fd);
    return (buffer);
}

int main(void)
{
    char *buffer;
    int len;
    int fd = open("file.txt", O_RDONLY);
    buffer = get_next_line(fd);
    len = ft_strlen(buffer);
    if (!buffer)
    {
        free(buffer);
        return (0);
    }
    write(2, buffer, len);
    free(buffer);
}
// int main(void)
// {
//     char error1[] = "erreur avec le fichier";
//     char error2[] = "erreur de lecture";
//     char c;
//     unsigned long occ;
//     // char buffer[BUFFER];
//     unsigned long count;
//     int newfd;
    
//     occ = 0;
//     newfd = open("file.txt", O_RDONLY);
//     if (newfd == -1)
//     {
//         write(2, error1 , ft_strlen(error1));
//         return (newfd);
//     }
//     while ((count = read(newfd, &c, 1)) > 0)
//     {
//         if (c == 'a')
//             occ++;
//         write(1, &c, count);
//     }
//     if (count == -1)
//     {
//         write(2, error2, ft_strlen(error2));
//         return (count);
//     }
//     close(newfd);
//     return (occ);
// }