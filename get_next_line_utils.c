/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echoubby <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 10:59:51 by echoubby          #+#    #+#             */
/*   Updated: 2023/12/04 11:01:30 by echoubby         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "get_next_line.h"

char	*ft_strchr(char *s, int c)
{
	while (*s)
	{
		if (*s == (char)c)
			return ((char *)s);
		s++;
	}
	return (0);
}

char	*ft_strjoin(char *s1, char *s2, int len)
{
	int		i;
	int		tol;
	int		j;
	char	*b;

	i = 0;
	j = 0;
	if (!s1 || !s2)
		return (NULL);
	tol = ft_strlen(s1);
	b = malloc((tol + len + 1) * sizeof(char));
	if (b == NULL)
		return (0);
	while (s1[i] && i < tol + len)
	{
		b[i] = s1[i];
		i++;
	}
	while (s2[j] && i < tol + len)
		b[i++] = s2[j++];
	b[i] = '\0';
	free (s1);
	return (b);
}

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}
