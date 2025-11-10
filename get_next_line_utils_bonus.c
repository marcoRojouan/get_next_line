/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrojouan <mrojouan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/10 11:46:58 by mrojouan          #+#    #+#             */
/*   Updated: 2025/11/10 11:47:00 by mrojouan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

/** Retourne la taille de la string donnee */
int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

/** Retourne, a partir d'une string donnee,
 *  une string allouer a partir de la valeur start et
 *  limitee par la taille fournie */
char	*ft_substr(const char *s, unsigned int start, size_t len)
{
	char	*str;
	size_t	i;
	size_t	slen;

	if (!s)
		return (0);
	slen = ft_strlen((char *)s);
	if (len > slen - start)
		len = slen - start;
	if (start > slen)
	{
		str = ft_strdup("");
		return (str);
	}
	str = malloc(sizeof(char) * (len + 1));
	if (!str)
		return (0);
	i = 0;
	while (i < len && s[start + i])
	{
		str[i] = s[start + i];
		i++;
	}
	str[i] = '\0';
	return (str);
}

/** Retourne un duplicata d'une
 *  string dans un duplicata allouer */
char	*ft_strdup(const char *s)
{
	char	*duplicata;
	int		i;
	int		len;

	len = ft_strlen((char *)s);
	duplicata = NULL;
	duplicata = malloc(sizeof(char) * len + 1);
	if (!duplicata)
		return (0);
	i = 0;
	while (i < len)
	{
		duplicata[i] = s[i];
		i++;
	}
	duplicata[i] = '\0';
	return (duplicata);
}

/** Retourne la string envoyer a partir de l'occurence recherchee */
char	*ft_strchr(const char *str, int occ)
{
	size_t	i;

	i = 0;
	if (!str)
		return (NULL);
	if ((char)occ == '\0')
		return ((char *)&str[i]);
	while (str[i])
	{
		if (str[i] == (char)occ)
			return ((char *)&str[i]);
		i++;
	}
	return (NULL);
}

/** Retourne une string allouer, qui est le resultat des deux parametre joint */
char	*ft_strjoin(char *s1, char *s2)
{
	int		i;
	int		j;
	char	*tab;

	if (!s1)
	{
		s1 = malloc(sizeof(char) * 1);
		if (!s1)
			return (NULL);
		s1[0] = '\0';
	}
	tab = malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!tab)
		return (NULL);
	i = 0;
	j = 0;
	while (s1[i])
		tab[j++] = s1[i++];
	i = 0;
	while (s2[i])
		tab[j++] = s2[i++];
	tab[j] = 0;
	free(s1);
	return (tab);
}