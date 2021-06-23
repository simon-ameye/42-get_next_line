#include "get_next_line.h"
#include <fcntl.h>
#include <stdio.h>

int		main(int argc, char **argv)
{
	int		fd;
	char	*line;

	(void) argc;
	(void) argv;

	fd = open("gnlTester/files/multiple_line_no_nl", O_RDONLY);

	while (get_next_line(fd, &line) == 1)
	{
		printf("%s", line);
		free(line);
		printf("\n");
	}

	printf("%s", line);
	free(line);
	close(fd);
}