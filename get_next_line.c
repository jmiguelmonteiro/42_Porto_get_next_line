/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: josemigu <josemigu@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/05 15:57:00 by josemigu          #+#    #+#             */
/*   Updated: 2025/05/10 13:07:57 by josemigu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*extract_line(char *raw_line)
{
	char	*next_line;
	int		pos;

	if (!*raw_line)
		return (NULL);
	pos = 0;
	while ((raw_line[pos] != '\n') && (raw_line[pos] != '\0'))
		pos++;
	next_line = ft_calloc((pos + 2), sizeof (char));
	ft_memmove(next_line, raw_line, pos + 1);
	next_line[pos + 1] = '\0';
	if (next_line && *next_line)
		return (next_line);
	return (ft_free_null(next_line));
}

char	*add_buffer_to_raw(char *raw_line, char *buffer)
{
	char	*new_raw_line;

	new_raw_line = ft_strjoin(raw_line, buffer);
	free(raw_line);
	ft_memset(buffer, '\0', BUFFER_SIZE + 1);
	return (new_raw_line);
}

void	update_buffer(char *raw_line, char *buffer)
{
	char	*pos_nl;
	int		i;

	i = 0;
	ft_memset(buffer, '\0', BUFFER_SIZE + 1);
	pos_nl = ft_strchr(raw_line, '\n');
	if (!pos_nl)
		return ;
	while (pos_nl[i + 1])
	{
		buffer[i] = pos_nl[i + 1];
		i++;
	}
}

char	*read_fd(int fd, char *raw_line, char *buffer)
{
	int		bytes_read;

	bytes_read = 0;
	while (true)
	{
		if (ft_strchr(raw_line, '\n'))
			return (raw_line);
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		if (bytes_read == -1)
			return (ft_free_null(raw_line));
		buffer[bytes_read] = '\0';
		raw_line = add_buffer_to_raw(raw_line, buffer);
		if (bytes_read < BUFFER_SIZE)
			return (raw_line);
	}
}

char	*get_next_line(int fd)
{
	static char	buffer[BUFFER_SIZE + 1];
	char		*raw_line;
	char		*next_line;

	raw_line = NULL;
	next_line = NULL;
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);

	raw_line = malloc(1 * sizeof(char));
	if (!raw_line)
		return (NULL);
 	if (buffer[0])
		raw_line = add_buffer_to_raw(raw_line, buffer);
	raw_line = read_fd(fd, raw_line, buffer);
	if (raw_line)
	{
		next_line = extract_line(raw_line);
		update_buffer(raw_line, buffer);
		free(raw_line);
	}
	else
		ft_memset(buffer, '\0', BUFFER_SIZE + 1);

	return (next_line);
}
