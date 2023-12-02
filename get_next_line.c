/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echoubby <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 16:29:09 by echoubby          #+#    #+#             */
/*   Updated: 2023/12/02 17:40:21 by echoubby         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "get_next_line.h"
#include <fcntl.h>
#include <stdio.h>

int	reading(int fd, char	*s)
{
	char	*buff;
	int	i;
	
	buff = malloc(BUFFER_SIZE + 1);
	s = NULL;
	if (!buff)
		return (0);
	i = 1;
	while(!(ft_strchr(s, '\n')) && i > 0)
	{
		i = read(fd, buff, BUFFER_SIZE);
		if (i == -1)
		{
			free(buff);
			return (0);
		}
		buff[i] = '\0';
		s = ft_strjoin(s, buff, i);
	}
	free (buff);
	return (i);
}
char	*line(char *s, int len)
{
	int	i;
	char	*new_line;

	i = 0;
	if(!s)
		return (NULL);
	new_line = malloc(len + 1);
	if (!new_line)
		return (NULL);
	while (s[i] && s[i] != '\n')
		i++;
	while (i >= 0)
	{
		*new_line = *s;
		new_line++;
		s++;
		i--;
	}
	*new_line = '\0';
	return (new_line);
}

char	*get_next_line(int fd)
{
	static char	*s;
	char	*new;
	int	len;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	len = reading(fd, s);
	printf("%s\n",s);
	if (s == NULL)
		return (NULL);
	new = line(s, len);
	if (new == NULL)
		return (NULL);
	return (new);
}

int main()
{
	int fd = open("file.txt", O_RDONLY);
	if (fd < 0)
		exit(1);
	printf("%d",fd);
	printf("%s",get_next_line(fd));
	printf("%s",get_next_line(fd));
	return 0;
}
