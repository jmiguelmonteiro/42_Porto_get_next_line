/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: josemigu <josemigu@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/05 15:57:00 by josemigu          #+#    #+#             */
/*   Updated: 2025/05/08 22:40:35 by josemigu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*extract_line(char *raw_line)
{
	char	*next_line;
	char	*nl_pos;
	int		pos;

	nl_pos = ft_strchr(raw_line, '\n');
	pos = nl_pos - raw_line;
	next_line = ft_calloc((pos + 1), sizeof (char));
	ft_memmove(next_line, raw_line, pos + 1);
	return (next_line);	
}

char	*add_to_raw(char *raw_line, char *buffer)
{
	char	*new_raw_line;

	new_raw_line = ft_strjoin(raw_line, buffer);
	free(raw_line);
	return (new_raw_line);	
}

char	*read_fd(int fd, char *raw_line)
{
	char	buffer[BUFFER_SIZE + 1];
	int		bytes_read;

	bytes_read = 0;
	while (true)
	{
		if (ft_strchr(raw_line, '\n'))
			return (raw_line);
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		if (bytes_read == 0)
			return (raw_line);
		buffer[bytes_read] = '\0';
		raw_line = add_to_raw(raw_line, buffer);
		if (bytes_read < BUFFER_SIZE)
			return (raw_line);
	}
}

char	*get_next_line(int fd)
{
	static char	buffer[BUFFER_SIZE + 1];
	char		*raw_line;
	char		*next_line;
	
	if (fd < 0 || fd > 1024 || BUFFER_SIZE <= 0)
		return (NULL);
	raw_line = ft_calloc(BUFFER_SIZE + 1, sizeof(char));
	ft_memmove(raw_line, buffer, BUFFER_SIZE);
	raw_line[BUFFER_SIZE] = '\0';
	raw_line = read_fd(fd, raw_line);
	next_line = extract_line(raw_line);
	
	free(raw_line);
	return (next_line);
}

int	main(void)
{
	int		fd;
	char	*str;

	fd = open("teste.txt", O_RDONLY);
	if (fd != -1)
	{
		printf("%s", str = get_next_line(fd));
	}
	free(str);
	return (0);
}
