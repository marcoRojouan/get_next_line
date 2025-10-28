/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrojouan <mrojouan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/27 16:50:21 by loup              #+#    #+#             */
/*   Updated: 2025/10/28 16:41:47 by mrojouan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# define BUFFER 500

#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>

char	*ft_strjoin(const char *s1, const char *s2);
int	ft_strlen(char *str);

# endif