/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rokerjea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/17 15:46:22 by rokerjea          #+#    #+#             */
/*   Updated: 2022/02/17 15:46:27 by rokerjea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_left_buffer(int nl_position, char **buffer)
{
	char	*res;
	char	*tmp;

	tmp = NULL;
	if (nl_position <= 0)
	{
		if (**buffer == '\0')
		{
			free(*buffer);
			*buffer = NULL;
			return (NULL);
		}
		res = *buffer;
		*buffer = NULL;
		return (res);
	}
	tmp = ft_substr(*buffer, nl_position, BUFFER_SIZE);
	if (!(tmp))
		return (NULL);
	res = *buffer;
	res[nl_position] = '\0';
	*buffer = tmp;
	return (res);
}

char	*ft_read_line(int fd, char **buffer, char *read_buffer)
{
	ssize_t	char_count;
	char	*nl;
	char	*tmp;

	nl = ft_strchr(*buffer, '\n');
	tmp = NULL;
	char_count = 0;
	while (nl == NULL)
	{
		char_count = read(fd, read_buffer, BUFFER_SIZE);
		if (char_count <= 0)
			return (ft_left_buffer(char_count, buffer));
		read_buffer[char_count] = '\0';
		tmp = ft_strjoin(*buffer, read_buffer);
		if (!(tmp))
			return (NULL);
		if (*buffer != NULL)
			free(*buffer);
		*buffer = tmp;
		nl = ft_strchr(*buffer, '\n');
	}
	return (ft_left_buffer(nl - *buffer + 1, buffer));
}

char	*get_next_line(int fd)
{
	char		*read_buffer;
	char		*line_res;
	static char	*buffer = NULL;

	if (fd < 0 || BUFFER_SIZE <= 0 || fd > 1024)
		return (NULL);
	read_buffer = (char *)malloc(sizeof(char) * BUFFER_SIZE + 1);
	if (!(read_buffer))
		return (NULL);
	if (!buffer)
	{
		buffer = ft_strdup("");
		if (!(buffer))
		{
			free(read_buffer);
			return (NULL);
		}
	}
	line_res = ft_read_line(fd, &buffer, read_buffer);
	free(read_buffer);
	return (line_res);
}
