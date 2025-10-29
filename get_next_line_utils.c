/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loup <loup@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/28 16:05:28 by mrojouan          #+#    #+#             */
/*   Updated: 2025/10/29 22:19:54 by loup             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

/** Retourne la taille de la string donnee */
int ft_strlen(char *str)
{
    int i;
    i = 0;
    while (str[i])
        i++;
    return (i);
}

/** Retourne, a partir d'une string donnee, une string allouer a partir de la valeur start et limitee par la taille fournie */
char    *ft_substr(const char *s, unsigned int start, size_t len)
{
        char    *str;
        size_t  i;
        size_t  slen;

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

/** Retourne un duplicata d'une string dans un duplicata allouer */
char    *ft_strdup(const char *s)
{
        char    *duplicata;
        int             i;
        int             len;

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
char    *ft_strchr(const char *str, int occ)
{
        size_t  i;

        i = 0;
        while (str[i])
        {
                if (str[i] == (unsigned char)occ)
                        return ((char *)&str[i]);
                i++;
        }
        if ((unsigned char)occ == '\0')
                return ((char *)&str[i]);
        return (NULL);
}

/** Retourne une string allouer, qui est le resultat des deux parametre joint */
char    *ft_strjoin(const char *s1, const char *s2)
{
        int             s1len;
        int             s2len;
        int             i;
        int             j;
        char    *tab;

        s1len = ft_strlen((char *)s1);
        s2len = ft_strlen((char *)s2);
        tab = NULL;
        tab = malloc(sizeof(char) * (s1len + s2len) + 1);
        if (!tab)
                return (0);
        i = 0;
        j = 0;
        while (s1[i])
                tab[j++] = s1[i++];
        i = 0;
        while (s2[i])
                tab[j++] = s2[i++];
        tab[j] = 0;
        return (tab);
}
