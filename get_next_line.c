/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echoubby <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 16:29:09 by echoubby          #+#    #+#             */
/*   Updated: 2023/12/04 14:21:08 by echoubby         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "get_next_line.h"
#include <fcntl.h>
#include <stdio.h>

char	*reading(int fd)
{
	int		i;
	char	*buff;
	char	*s;

	buff = malloc(BUFFER_SIZE + 1);
	if (!buff)
		return (0);
	s = NULL;
	i = 1;
	while (!(ft_strchr(s, '\n')) && i > 0)
	{
		i = read(fd, buff, BUFFER_SIZE);
		if (i == -1)
		{
			free(buff);
			free(s);
			return (0);
		}
		buff[i] = '\0';
		s = ft_strjoin(s, buff, i);
	}
	free (buff);
	return (s);
}

char	*line(char *s, int len)
{
	int	i;
	char	*new_line;

	i = 0;
	if (!s)
		return (NULL);
	new_line = malloc(len + 1);
	if (!new_line)
		return (NULL);
	while (i <= len)
	{
		new_line[i] = s[i];
		i++;
	}
	new_line[i] = '\0';
	return (new_line);
}

char	*get_next_line(int fd)
{
	int		len;
	static char	*s;
	char	*new;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	if (!(ft_strchr(s , '\n')))
	{
		s = reading(fd);
		if (s == NULL)
			return (NULL);
	}
	len = len_line(s);
	new = line(s, len);
	if (new == NULL)
		return (NULL);
	s = s + len + 1;
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
	return 0;
}
