/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rokerjea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/17 15:25:02 by rokerjea          #+#    #+#             */
/*   Updated: 2022/02/17 15:25:05 by rokerjea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strchr(const char *s, int c)
{
	int				i;
	unsigned char	needle;

	needle = (unsigned char)c;
	i = 0;
	while (s[i])
	{
		if (s[i] == needle)
			return ((char *)s + i);
		i++;
	}
	if (s[i] == 0 && needle == 0)
		return ((char *)s + i);
	return (0);
}

unsigned long	ft_strlen(const char *s)
{
	unsigned long	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

char	*ft_strdup(const char *s1)
{
	char	*s2;
	int		i;

	i = 0;
	s2 = malloc(sizeof(char) * (ft_strlen(s1) + 1));
	if (!s2)
		return (NULL);
	while (s1[i])
	{
		s2[i] = s1[i];
		i++;
	}
	s2[i] = '\0';
	return (s2);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	unsigned long	j;
	char			*res;

	j = 0;
	if (!s)
		return (NULL);
	if ((ft_strlen(s) - start) < len && ft_strlen(s) > start)
		res = malloc(sizeof(char) * (ft_strlen(s) - start + 1));
	else if (ft_strlen(s) < start)
	{
		res = malloc(sizeof(char) * 1);
		if (!(res))
			return (NULL);
		res[j] = '\0';
		return (res);
	}
	else
		res = malloc(sizeof(char) * (len + 1));
	if (!(res))
		return (NULL);
	while (j < len && s[start] && start < ft_strlen(s))
		res[j++] = s[start++];
	res[j] = '\0';
	return (res);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		i;
	int		j;
	char	*str;

	i = 0;
	j = 0;
	if (!s1 || !s2)
		return (NULL);
	while (s1[i])
		i++;
	while (s2[j])
		j++;
	str = malloc(sizeof(char) * (i + j + 1));
	if (!str)
		return (NULL);
	i = 0;
	j = 0;
	while (s1[i])
		str[j++] = s1[i++];
	i = 0;
	while (s2[i])
		str[j++] = s2[i++];
	str[j] = '\0';
	return (str);
}
