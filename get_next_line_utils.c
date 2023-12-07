/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echoubby <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 10:59:51 by echoubby          #+#    #+#             */
/*   Updated: 2023/12/06 13:07:42 by echoubby         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "get_next_line.h"

char	*ft_strdup(const char *s)
{
	char	*pt;
	int		i;
	int		len;

	i = 0;
	if (!s)
		return (0);
	len = ft_strlen(s);
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
	len = ft_strlen(s1) + ft_strlen(s2);
	b = malloc((len + 1) * sizeof(char));
	if (b == NULL)
		return (0);
	while (s1[i] && i < len)
	{
		b[i] = s1[i];
		i++;
	}
	while (s2[j] && i < len)
		b[i++] = s2[j++];
	b[i] = '\0';
	free (s1);
	return (b);
}

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	if (!str)
		return (0);
	while (*str++)
		i++;
	return (i);
}

int	len_line(char const *str)
{
	int	i;

	i = 0;
	if (!str)
		return (0);
	while (*str && *str != '\n')
	{
		i++;
		str++;
	}
	if (*str && *str == '\n')
		return (i + 1);
	return (i);
}
