/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echoubby <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 16:29:09 by echoubby          #+#    #+#             */
/*   Updated: 2023/12/06 17:32:34 by echoubby         ###   ########.fr       */
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

	buff = malloc(BUFFER_SIZE + 1);
	if (!buff)
		return (free(buff), NULL);
	s = NULL;
	i = 1;
	while (i > 0)
	{
		i = read(fd, buff, BUFFER_SIZE);
		if (i == -1)
			return (free(s), free(buff), ft_strdup(""));
		buff[i] = '\0';
		s = ft_strjoin(s, buff);
	}
	free (buff);
	return (s);
}

static char	*line(char *s, int len)
{
	int		i;
	char	*new_line;

	i = 0;
	if (!s)
		return (NULL);
	new_line = malloc(len + 1);
	if (!new_line)
		return (NULL);
	while (i < len)
	{
		new_line[i] = s[i];
		i++;
	}
	new_line[i] = '\0';
	return (new_line);
}

char	*get_next_line(int fd)
{
	int			len;
	static char	*s;
	char		*new;

	if (fd < 0 || BUFFER_SIZE < 1)
		return (NULL);
	len = ft_strlen(s);
	if (len == 0)
	{
		s = reading(fd);
		if (s[0] == '\0')
		{
			free(s);
			s = NULL;
			return (NULL);
		}
	}
	len = len_line(s);
	new = line(s, len);
	if (new == NULL)
		return (NULL);
	s = s + len;
	return (new);
}

int main()
{
	int fd = open("file.txt", O_RDONLY);
	printf("%s", get_next_line(fd));
	printf("%s", get_next_line(fd));
	printf("%s", get_next_line(fd));
	printf("%s", get_next_line(fd));
	printf("%s", get_next_line(fd));
	printf("%s", get_next_line(fd));
	return 0;
}
