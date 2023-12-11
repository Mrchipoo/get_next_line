/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echoubby <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 10:59:51 by echoubby          #+#    #+#             */
/*   Updated: 2023/12/11 14:25:54 by echoubby         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "get_next_line.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t		i;
	char		*subs;
	size_t		tol;

	i = 0;
	if (!s)
		return (0);
	tol = ft_strlen(s, 1);
	if (start >= tol)
		return (ft_strdup(""));
	if (tol - start <= len)
		len = tol - start;
	subs = malloc(len + 1);
	if (subs == NULL)
		return (0);
	while (i < len && s[start + i] != '\0')
	{
		subs[i] = s[start + i];
		i++;
	}
	subs[i] = '\0';
	return (subs);
}

int	check(char *s)
{
	if (!s)
		return (0);
	while (*s != '\0')
	{
		if (*s == '\n')
			return (1);
		s++;
	}
	return (0);
}

char	*ft_strdup(char *s)
{
	char	*pt;
	int		i;
	int		len;

	i = 0;
	if (!s)
		return (NULL);
	len = ft_strlen(s, 1);
	pt = malloc(sizeof(char) * (len + 1));
	if (pt == NULL)
		return (NULL);
	while (s[i])
	{
		pt[i] = s[i];
		i++;
	}
	pt[i] = '\0';
	return (pt);
}

char	*ft_strjoin(char *s1, char *s2)
{
	int		i;
	int		len;
	int		j;
	char	*b;

	i = 0;
	j = 0;
	if (!s2)
		return (NULL);
	if (!s1)
		return (ft_strdup(s2));
	len = ft_strlen(s1, 1) + ft_strlen(s2, 1);
	b = malloc((len + 1) * sizeof(char));
	if (b == NULL)
		return (NULL);
	while (s1[i] && i < len)
	{
		b[i] = s1[i];
		i++;
	}
	while (s2[j] && i < len)
		b[i++] = s2[j++];
	b[i] = '\0';
	return (b);
}

size_t	ft_strlen(const char *str, int mode)
{
	size_t	i;

	i = 0;
	if (!str)
		return (0);
	if (mode == 1)
	{
		while (*str != '\0')
		{
			i++;
			str++;
		}
	}
	else if (mode == 2)
	{
		while (*str != '\0' && *str != '\n')
		{	
			i++;
			str++;
		}
		if (*str && *str == '\n')
			return (i + 1);
	}
	return (i);
}
