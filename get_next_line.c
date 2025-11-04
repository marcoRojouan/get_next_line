/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loup <loup@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/27 15:41:20 by loup              #+#    #+#             */
/*   Updated: 2025/11/04 18:08:46 by loup             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <get_next_line.h>

static char *get_rest(char *stockage)
{
	char *rest;
	int i;
	int restlen;

	i = 0;
	while (stockage[i] != '\n' || stockage[i])
		i++;
	if (stockage[i] == '\n')
	{
		i++;
	}	
	restlen = ft_strlen(stockage + i);
	rest = ft_substr(stockage, i, restlen);
	return (rest);
}

static char	*get_last_line(char *stockage)
{
	char	*last_line;
	int		i;

	i = 0;
	while (stockage[i] != '\n' || stockage[i])
		i++;
	if (stockage[i] == '\n')
		i++;
	last_line = ft_substr(stockage, 0, i);
	return (last_line); 
}

static char	*read_line_plus(char *stockage, int fd)
{
	int		read_count;
	char	*buffer;

	read_count = 1;
	buffer = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buffer)
		return (NULL);
	while (!ft_strchr(stockage, '\n') && read_count != 0)
	{
		read_count = read(fd, buffer, BUFFER_SIZE);
		if (read_count  == -1)
		{
			free(buffer);
			return (NULL);
		}
		stockage = ft_strjoin(stockage, buffer);
	}
	stockage[read_count] = '\0';
	free(buffer);
	return (stockage);
}

char	*get_next_line(int fd)
{
	static char	*stockage;
	char	*last_line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	stockage = read_line_plus(stockage, fd);
	if (!stockage)
		return (NULL);
	last_line = get_last_line(stockage);
	if (!last_line)
		return (NULL);
	stockage = get_rest(stockage);
	return (last_line);
}
