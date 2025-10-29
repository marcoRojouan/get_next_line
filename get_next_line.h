/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loup <loup@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/27 16:50:21 by loup              #+#    #+#             */
/*   Updated: 2025/10/29 22:24:11 by loup             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER
#  define BUFFER 500
# endif

#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>

char    *get_next_line(int fd);

char    *ft_strchr(const char *str, int occ);
char    *ft_strdup(const char *s);
char    *ft_substr(const char *s, unsigned int start, size_t len);
char	*ft_strjoin(const char *s1, const char *s2);
int	ft_strlen(char *str);

# endif