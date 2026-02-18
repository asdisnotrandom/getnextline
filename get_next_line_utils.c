/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ademirel <ademirel@student.42istanbul.com.tr>+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/17 22:47:55 by ademirel          #+#    #+#             */
/*   Updated: 2026/02/19 02:17:37 by ademirel         ###   ########.fr       */
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
	size_t	lna;
	size_t	lnb;
	size_t	i;
	char	*d;

	if (s1 == 0)
		return (ft_strdup(s2));
	i = 0;
	lna = ft_strlen(s1);
	lnb = ft_strlen(s2);
	d = malloc(lna + lnb + 1);
	if (d == 0)
		return (0);
	while (i < lna + lnb)
	{
		if (i < lna)
			d[i] = s1[i];
		else if (i < lna + lnb)
			d[i] = s2[i - lna];
		i++;
	}
	d[i] = '\0';
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
