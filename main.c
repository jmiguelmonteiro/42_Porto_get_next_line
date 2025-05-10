/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: josemigu <josemigu@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/10 10:53:12 by josemigu          #+#    #+#             */
/*   Updated: 2025/05/10 11:54:33 by josemigu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	main(void)
{
	int		fd;
	char	*line;
	int		i;

	i = 0;
	fd = open("tests/1char.txt", O_RDONLY);
	if (fd == -1)
		printf("Error opening file\n");
	while (++i)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		printf("line [%02d]: %p %s", i, &line, line);
		free(line);
	}
	close(fd);
	return (0);
}
