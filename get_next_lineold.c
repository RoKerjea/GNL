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

void	free_null(char **ptr)
{
	if (*ptr != NULL)
	{
		free(*ptr);
		ptr = NULL;
	}
}

/*char	*join_line(int nl_position, char **buffer)
{
	char	*res;
	char	*tmp;

	tmp = NULL;
	if (nl_position <= 0 )
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
	res = *buffer;

	res[nl_position] = 0;
	*buffer = tmp;
	return (res);
}*/

char	*ft_join_read_buffer(int nl_position, char **buffer)
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
	res = *buffer;
	res[nl_position] = '\0';
	*buffer = tmp;
	return (res);
}

/*char	*read_line(int fd, char **buffer, char *read_return)
{
	ssize_t	bytes_read;
	char	*tmp;
	char	*nl;

	nl = ft_strchr(*buffer, '\n');
	tmp = NULL;
	bytes_read = 0;
	while (nl == NULL)
	{
		bytes_read = read(fd, read_return, BUFFER_SIZE);
		if (bytes_read <= 0)
			return (ft_join_read_buffer(bytes_read, buffer));
		read_return[bytes_read] = '\0';
		tmp = ft_strjoin(*buffer, read_return);
		free_null(buffer);
		*buffer = tmp;
		nl = ft_strchr(*buffer, '\n');
	}
	return (ft_join_read_buffer(nl - *buffer + 1, buffer));
}*/

char	*ft_read_line(int fd, char **buffer, char *read_return)
{
	ssize_t	char_count;
	char	*nl;
	char	*tmp;

	nl = ft_strchr(*buffer, '\n');
	tmp = NULL;
	char_count = 0;
	while (nl == NULL)
	{
		char_count = read(fd, read_return, BUFFER_SIZE);
		if (char_count <= 0)
			return (ft_join_read_buffer(char_count, buffer));
		read_return[char_count] = '\0';
		tmp = ft_strjoin(*buffer, read_return);
		free_null(buffer);
		*buffer = tmp;
		nl = ft_strchr(*buffer, '\n');
	}
	return (ft_join_read_buffer(nl - *buffer + 1, buffer));
}

//could get rid of read_return and only use res?
/*
char	*get_next_line(int fd)
{
	static char	*buffer[1];
	char		*read_return;
	char		*res;

	if (fd < 0 || BUFFER_SIZE <= 0 || fd > MAX_FD)
		return (NULL);
	read_return = (char *)malloc(sizeof(char) * BUFFER_SIZE + 1);
	if (read_return == NULL)
		return (NULL);
	if (!buffer[0])
	{
		//buffer[0] = ft_strdup("");
		*buffer[0] = (char * )malloc(sizeof(char) * BUFFER_SIZE);
		if (buffer[0] == NULL)
		return (NULL);
	}
	res = ft_read_line(fd, &buffer[0], read_return);
	free_null(&read_return);
	return (res);
}
*/
char	*get_next_line(int fd)
{
	char		*read_return;
	char		*line_res;
	static char	*buffer[1024 + 1];

	if (fd < 0 || BUFFER_SIZE <= 0 || fd > 1024)
		return (NULL);
	read_return = (char *)malloc(sizeof(char) * BUFFER_SIZE + 1);
	if (read_return == NULL)
		return (NULL);
	if (!buffer[1024])
	{
		buffer[1024] = ft_strdup("");
	/*
		buffer[0] = (char * )malloc(sizeof(char) * BUFFER_SIZE);
		if (buffer[0] == NULL)
			return (NULL);
	
	*/
	}
	line_res = ft_read_line(fd, &buffer[1024], read_return);
	free_null(&read_return);
	/*if (read_return != NULL)
	{
		free(read_return);
		read_return = NULL;
	}
*/
	return (line_res);
}
