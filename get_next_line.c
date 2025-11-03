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

#include <get_next_line.h>

char *read_line_rest(char *stockage, int fd)
{
	char	*tmp;
	char	*buffer;
	int		read_count;

	read_count = 1;
	if (!stockage)
		ft_strdup("");
	buffer = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if(!buffer)
		return (NULL);
	while (!strchr(stockage, '\n') && read_count > 0)
	{
		read_count = read(fd, buffer, BUFFER_SIZE);
		if (read_count == 0)
		{
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


char	get_next_line(int fd)
{
	char *stockage;

	stockage = read_line_rest(stockage, fd);
}
