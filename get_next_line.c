/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echoubby <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 16:29:09 by echoubby          #+#    #+#             */
/*   Updated: 2023/12/11 14:23:16 by echoubby         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "get_next_line.h"
#include <fcntl.h>
#include <stdio.h>

static char	*reading(int fd)
{
	int		i;
	char	*buff;
	char	*s;
	char	*tmp;

	buff = malloc(BUFFER_SIZE + 1);
	if (!buff)
		return (NULL);
	s = NULL;
	i = 1;
	while (i > 0)
	{
		i = read(fd, buff, BUFFER_SIZE);
		if (i == -1)
			return (free(buff), NULL);
		buff[i] = '\0';
		tmp = s;
		s = ft_strjoin(tmp, buff);
		free(tmp);
		if (s == NULL)
			return (free(buff), NULL);
	}
	free (buff);
	return (s);
}

static	char	*read_free(char *s, int fd)
{
	char	*tmp;
	char	*read;

	tmp = s;
	read = reading(fd);
	s = ft_strjoin(tmp, read);
	free(tmp);
	if (s[0] == '\0' || !read)
	{
		free(read);
		free(s);
		s = NULL;
		return (NULL);
	}
	free(read);
	return (s);
}

static char	*extract_line(char *s)
{
	char	*tmp;
	int		j;

	j = 0;
	while (s[j])
	{
		if (s[j] == '\n')
		{
			tmp = ft_substr(s, j + 1, ft_strlen(s, 1));
			free(s);
			return (tmp);
		}
		j++;
	}
	free(s);
	return (NULL);
}

static char	*line(char *s, int len)
{
	char	*new_line;

	if (!s)
		return (NULL);
	new_line = ft_substr(s, 0, len);
	return (new_line);
}

char	*get_next_line(int fd)
{
	int			len;
	static char	*s;
	char		*new;

	if (fd < 0 || BUFFER_SIZE < 1)
		return (NULL);
	if (check(s) == 0)
	{
		s = read_free(s, fd);
		if (s == NULL)
			return (NULL);
	}
	len = ft_strlen(s, 2);
	new = line(s, len);
	if (s[len - 1])
	{
		s[len - 1] = '\n';
		s = extract_line(s);
	}
	return (new);
}
