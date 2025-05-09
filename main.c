#include "get_next_line.h"

int	main(void)
{
	int		fd;
	char	*line;
	int		i = 0;
	
	fd = open("tests/empty.txt", O_RDONLY);
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
