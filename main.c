
#include <stdio.h>
#include <fcntl.h>
#include <assert.h>
#include <string.h>
#include <stdlib.h>
#include "get_next_line.h"

void	print_line(char *line)
{
	// printf("----%s----\n", __func__);
	printf("%s|", line);
	printf("\n-------------------\n");
}

void	checker(char *line, char *expected)
{
	// assert(strcmp(line, expected) == 0);
	(void)expected;
	print_line(line);
	free(line);
}

void	std_in(void)
{
	printf("----%s----\n", __func__);
	char *line;
	while ((line = get_next_line(0)) != NULL)
	{
		print_line(line);
		free(line);
	}
}

int main(int ac, char **av)
{
	(void)ac;
	(void)av;
	std_in();
	return (0);
}
// ccw *.c -D BUFFER_SIZE=42 -o a.out && ./a.out < ./files/1char.txt