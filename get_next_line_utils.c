/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ademirel <ademirel@student.42istanbul.com.tr>+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/17 22:47:55 by ademirel          #+#    #+#             */
/*   Updated: 2026/02/19 03:37:13 by ademirel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *s)
{
	size_t	cnt;

	cnt = 0;
	while (s[cnt] != '\0')
	{
		cnt++;
	}
	return (cnt);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	i;
	char	*d;

	if (s1 == NULL)
		return (ft_strdup(s2));
	d = malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	if (d != NULL)
	{
		i = 0;
		while (s1[i] != '\0')
		{
			d[i] = s1[i];
			i++;
		}
		while (*s2 != '\0')
		{
			d[i] = *s2;
			i++;
			s2++;
		}
		d[i] = '\0';
	}
	free((char *)s1);
	return (d);
}

char	*ft_strchr(const char *s, int c)
{
	if (s == NULL)
		return (NULL);
	while (*s != '\0')
	{
		if (*s == (char)c)
			return ((char *)s);
		s++;
	}
	if ((char)c == '\0')
		return ((char *)s);
	return (0);
}

char	*ft_strdup(const char *s)
{
	size_t	sz;
	char	*a;
	size_t	i;

	sz = ft_strlen(s) + 1;
	a = malloc(sz);
	i = 0;
	if (a == 0)
		return (0);
	while (s[i] != '\0')
	{
		a[i] = s[i];
		i++;
	}
	if (s[i] == '\0')
		a[i] = s[i];
	return (a);
}
