/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: josemigu <josemigu@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/05 15:57:00 by josemigu          #+#    #+#             */
/*   Updated: 2025/05/07 18:24:54 by josemigu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*add_to_raw(char *raw_line, char *buffer)
{
	char	*new_raw_line;

	new_raw_line = ft_strjoin(raw_line, buffer);
	free(raw_line);
	return (new_raw_line);	
}

char	*read_line(int fd, char *raw_line)
{
	char	buffer[BUFFER_SIZE];
	int		bytes_read;

	while (true)
	{
		if (ft_strrchr(raw_line, '\n'))
			return (raw_line);
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		if (bytes_read == 0)
			return (raw_line);
		raw_line = add_to_raw(raw_line, buffer);
		if (bytes_read < BUFFER_SIZE)
			return (raw_line);	
	}
}

char	*get_next_line(int fd)
{
	static char	buffer[BUFFER_SIZE + 1];
	char		*raw_line;
	
	raw_line = malloc(0);
	if (fd == -1 || BUFFER_SIZE <= 0)
		return (NULL);
	if (buffer[0] != '\0')
		ft_strjoin(raw_line, buffer);
	raw_line = read_line(fd, raw_line);

	printf("%s", raw_line);

	free(raw_line);
	return (NULL);
}

int	main(void)
{
	int	fd;

	fd = open("teste.txt", O_RDONLY);
	if (fd != -1)
		get_next_line(fd);
	return (0);
}
