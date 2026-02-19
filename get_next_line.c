/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ademirel <ademirel@student.42istanbul.com.tr>+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/17 22:47:52 by ademirel          #+#    #+#             */
/*   Updated: 2026/02/19 03:50:48 by ademirel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*ft_clear(char *a, char **c)
{
	free(a);
	free(*c);
	*c = NULL;
	return (NULL);
}

static char	*ft_nbal(char *s, int c)
{
	char	*a;
	char	*b;

	if (s == NULL)
		return (NULL);
	if (c == 0)
	{
		free(s);
		return (NULL);
	}
	b = ft_strchr(s, '\n');
	if (b == NULL || *(b + 1) == '\0')
	{
		free(s);
		return (NULL);
	}
	a = ft_strdup(b + 1);
	free(s);
	return (a);
}

static char	*ft_lft(char *a)
{
	char	*b;
	size_t	i;
	size_t	j;

	if (a == NULL || *a == '\0')
		return (NULL);
	i = 0;
	j = 0;
	while (a[i] != '\n' && a[i] != '\0')
	{
		i++;
	}
	if (a[i] == '\n')
		i++;
	b = malloc(i + 1);
	if (b == NULL)
		return (NULL);
	while (j < i)
	{
		b[j] = a[j];
		j++;
	}
	b[j] = '\0';
	return (b);
}

char	*get_next_line(int fd)
{
	static char	*blp;
	char		*inc;
	char		*res;
	int			c;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	inc = malloc(BUFFER_SIZE + 1);
	if (inc == NULL)
		return (ft_clear(NULL, &blp));
	c = 1;
	while (ft_strchr(blp, '\n') == NULL && c != 0)
	{
		c = read(fd, inc, BUFFER_SIZE);
		if (c == -1)
			return (ft_clear(inc, &blp));
		inc[c] = '\0';
		if (c == 0)
			break ;
		blp = ft_strjoin(blp, inc);
		if (blp == NULL)
			return (ft_clear(inc, &blp));
	}
	free(inc);
	res = ft_lft(blp);
	if (res == NULL)
		return (ft_clear(NULL, &blp));
	blp = ft_nbal(blp, c);
	return (res);
}
