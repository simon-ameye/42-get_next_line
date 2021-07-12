#include "get_next_line.h"
#include <fcntl.h>
#include <stdio.h>

int		main(int argc, char **argv)
{
	int		fd;
	char	*line;

	(void) argc;
	(void) argv;

	printf("start reading\n");
	fd = open("gnlTester/files/multiple_line_no_nl", O_RDONLY);
	printf("fd read : %i\n", fd);

	while ((line = get_next_line(fd)) != NULL)
	{
		printf("!%s!, %p", line, line);
		free(line);
		printf("\n");
	}

	printf("%s", line);
	free(line);
	close(fd);

}