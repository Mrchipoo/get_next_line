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

static	int	len_line(char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (0);
	while (*str != '\0' && *str != '\n')
	{	
		i++;
		str++;
	}
	if (*str && *str == '\n')
		return (i + 1);
	return (i);
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
			tmp = ft_substr(s, j + 1, ft_strlen(s));
			free(s);
			return (tmp);
		}
		j++;
	}
	free(s);
	return (NULL);
}

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
	char		*read;
	char		*tmp;

	if (fd < 0 || BUFFER_SIZE < 1)
		return (NULL);
	if (check(s) == 0)
	{
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
	}
	len = len_line(s);
	new = line(s, len);
	if (s[len - 1] == '\n')
		s = extract_line(s);
	if (s == NULL)
		return (NULL);
	return (new);
}
