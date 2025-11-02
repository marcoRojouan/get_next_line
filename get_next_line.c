/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loup <loup@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/27 15:41:20 by loup              #+#    #+#             */
/*   Updated: 2025/10/29 23:57:34 by loup             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char    *get_rest(char *stockage)
{
    char    *rest;
    int     len;

    len = 0;
    while (stockage[len] != '\n' && stockage[len] )
        len++;
    if (stockage[len] == '\n')
        len++;
    rest = ft_strdup(stockage + len);
    free(stockage);
    return (rest);
}

static char    *get_final_line(char *stockage)
{
    char *final_line;
    int len;

    len = 0;
    while (stockage[len] != '\n' && stockage[len])
        len++;
    if (stockage[len] == '\n')
        len++;
    final_line = ft_substr(stockage, 0, len);
    return (final_line);
}

static char    *get_stock(char *stockage, int fd)
{
    char    *buffer;
    char    *tmp;
    int     read_count;

    read_count = 1;
    buffer = malloc(sizeof(char) * (BUFFER + 1));
    if (!buffer)
        return (NULL);
    if (!stockage)
        stockage = ft_strdup("");
    while (!ft_strchr(stockage, '\n') && read_count > 0)
    {
        read_count = read(fd, buffer, BUFFER);
        if (read_count == 0)
        {
            free(stockage);
            free(buffer);
            return (NULL);
        }
        buffer[read_count] = '\0';
        tmp = ft_strjoin(stockage, buffer);
        free(stockage);
        stockage = tmp;
    }
    free(buffer);
    return (stockage);
}

char    *get_next_line(int fd)
{
    static char *stockage;
    char *final_line;

    stockage = get_stock(stockage, fd);
    if (!stockage)
        return (NULL);
    final_line = get_final_line(stockage);
    if (!final_line)
        return (NULL);
    stockage = get_rest(stockage);
    return (final_line);
}
