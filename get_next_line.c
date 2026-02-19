/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ademirel <ademirel@student.42istanbul.com.tr>+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/17 22:47:52 by ademirel          #+#    #+#             */
/*   Updated: 2026/02/19 06:18:22 by ademirel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*ft_clear(char *trs, char **blp)
{
	free(trs);
	free(*blp);
	*blp = NULL;
	return (NULL);
}

static char	*ft_nbal(char *s)
{
	char	*new;
	char	*nptr;

	if (s == NULL)
		return (NULL);
	nptr = ft_strchr(s, '\n');
	if (nptr == NULL || *(nptr + 1) == '\0')
	{
		free(s);
		return (NULL);
	}
	new = ft_strdup(new + 1);
	free(s);
	return (new);
}

static char	*ft_lft(char *ms)
{
	char	*nws;
	size_t	i;
	size_t	j;

	if (ms == NULL || *ms == '\0')
		return (NULL);
	i = 0;
	j = 0;
	while (ms[i] != '\n' && ms[i] != '\0')
	{
		i++;
	}
	if (ms[i] == '\n')
		i++;
	nws = malloc(i + 1);
	if (nws == NULL)
		return (NULL);
	while (j < i)
	{
		nws[j] = ms[j];
		j++;
	}
	nws[j] = '\0';
	return (nws);
}

static char	*ft_read(int fd, char **blp, char *inc)
{
	int	rv;

	rv = 1;
	while (ft_strchr(*blp, '\n') == NULL && rv != 0)
	{
		rv = read(fd, inc, BUFFER_SIZE);
		if (rv == -1)
			return (ft_clear(inc, blp));
		inc[rv] = '\0';
		if (rv == 0)
			break ;
		*blp = ft_strjoin(*blp, inc);
		if (*blp == NULL)
			return (ft_clear(inc, blp));
	}
	free(inc);
	return (*blp);
}

char	*get_next_line(int fd)
{
	static char	*blp;
	char		*inc;
	char		*res;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	inc = malloc(BUFFER_SIZE + 1);
	if (inc == NULL)
		return (ft_clear(NULL, &blp));
	blp = ft_read(fd, &blp, inc);
	if (blp == NULL)
		return (NULL);
	res = ft_lft(blp);
	if (res == NULL)
		return (ft_clear(NULL, &blp));
	blp = ft_nbal(blp);
	return (res);
}
