/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrojouan <mrojouan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/27 16:50:21 by loup              #+#    #+#             */
/*   Updated: 2025/11/04 16:55:55 by mrojouan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 100
# endif

#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>

char    *get_next_line(int fd);

char    *ft_strchr(const char *str, int occ);
char    *ft_strdup(const char *s);
char    *ft_substr(const char *s, unsigned int start, size_t len);
char	*ft_strjoin(char *s1, char *s2);
int	ft_strlen(char *str);

# endif