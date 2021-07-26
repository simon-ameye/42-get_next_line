#include "get_next_line.h"
#include <fcntl.h>
#include <stdio.h>

int		main(int argc, char **argv)
{
	int		fd1;
	int		fd2;
	char	*line;
	char	chartemp;

	(void) argc;
	(void) argv;

	printf("start reading\n");
	fd1 = open("gnlTester/files/multiple_line_with_nl", O_RDONLY);
	fd2 = open("gnlTester/files/alternate_line_nl_no_nl", O_RDONLY);
	printf("fd read : %i\n", fd1);
	printf("fd read : %i\n", fd2);


	line = &chartemp;
	while (line != NULL)
	{
		line = get_next_line(fd1);
		printf("%s", line);
		line = get_next_line(fd2);
		printf("%s", line);
		free(line);
	}

	free(line);
	close(fd1);
	close(fd2);

}