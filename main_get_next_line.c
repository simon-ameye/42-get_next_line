#include "get_next_line.h"
#include <fcntl.h>
#include <stdio.h>

int		main(int argc, char **argv)
{
	int		fd;
	char	*line;
	char	chartemp;

	(void) argc;
	(void) argv;

	printf("start reading\n");
	fd = open("gnlTester/files/multiple_line_with_nl", O_RDONLY);
	printf("fd read : %i\n", fd);

	line = &chartemp;
	while (line != NULL)
	{
		line = get_next_line(fd);
		printf("%s", line);
		free(line);
	}

	free(line);
	close(fd);

}