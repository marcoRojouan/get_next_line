/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loup <loup@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/27 15:41:20 by loup              #+#    #+#             */
/*   Updated: 2025/11/04 21:49:44 by loup             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*get_rest(char *stockage)
{
	char	*rest;
	int		i;

	if (!stockage)
		return (NULL);
	i = 0;
	while (stockage[i] != '\n' && stockage[i])
		i++;
	if (!stockage[i])
	{
		free(stockage);
		return (NULL);
	}
	if (stockage[i] == '\n')
		i++;
	rest = ft_strdup(stockage + i);
	free(stockage);
	return (rest);
}

static char	*get_last_line(char *stockage)
{
	char	*last_line;
	int		i;

	i = 0;
	if (!stockage || !*stockage)
		return (NULL);
	while (stockage[i] != '\n' && stockage[i])
		i++;
	if (stockage[i] == '\n')
		i++;
	last_line = ft_substr(stockage, 0, i);
	return (last_line);
}

static char	*read_line_plus(char *stockage, char *buffer, int fd)
{
	int		read_count;
	char	*tmp;

	read_count = 1;
	while (!stockage || (!ft_strchr(stockage, '\n') && read_count != 0))
	{
		read_count = read(fd, buffer, BUFFER_SIZE);
		if (read_count < 0)
		{
			free(stockage);
			return (NULL);
		}
		buffer[read_count] = '\0';
		tmp = ft_strjoin(stockage, buffer);
		stockage = tmp;
	}
	return (stockage);
}

static char	*alloc_read_next(char *stockage, int fd)
{
	char	*buffer;

	buffer = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buffer)
		return (NULL);
	stockage = read_line_plus(stockage, buffer, fd);
	free(buffer);
	if (!stockage)
		return (NULL);
	if (*stockage == '\0')
	{
		free(stockage);
		return (NULL);
	}
	return (stockage);
}

char	*get_next_line(int fd)
{
	static char	*stockage;
	char		*last_line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	stockage = alloc_read_next(stockage, fd);
	if (!stockage)
		return (NULL);
	last_line = get_last_line(stockage);
	stockage = get_rest(stockage);
	return (last_line);
}
