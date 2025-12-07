
#include <stdio.h>
#include <fcntl.h>
#include <assert.h>
#include <string.h>
#include <stdlib.h>
#include "get_next_line_bonus.h"

#define RESET "\033[0m"
#define RED "\033[31m"
#define GREEN "\033[32m"
#define YELLOW "\033[33m"
#define BLUE "\033[34m"
#define MAGENTA "\033[35m"
#define CYAN "\033[36m"
#define WHITE "\033[37m"

void	print_line(char *line, int fd)
{
	// printf("----%s----\n", __func__);
	printf("fd: %d --> %s|", fd, line);
	printf("\n-------------------\n"RESET);
}

void	std_in_bonus(void)
{
	printf("----%s----\n", __func__);
	char *line1, *line2;
	int fd1 = open("get_next_line_bonus.c", O_RDONLY);
	int fd2 = open("LICENSE", O_RDONLY);
	if (fd1 < 0 || fd2 < 0)
	{
		perror("Error opening file");
		return ;
	}
	line1 = get_next_line(fd1);
	line2 = get_next_line(fd2);
	// print_line(line1, fd1);
	// print_line(line2, fd2);
	while (line1 != NULL || line2 != NULL) {
		if (line1)
		{
			printf(YELLOW "fd1\n");
			print_line(line1, fd1);
			free(line1);
			line1 = NULL;
		}
		if (line2)
		{
			printf(CYAN "fd2\n");
			print_line(line2, fd2);
			free(line2);
			line2 = NULL;
		}
		line1 = get_next_line(fd1);
		line2 = get_next_line(fd2);
	}
	if (line1)
	{
		printf("fd1\n");
		print_line(line1, fd1);
		free(line1);
	}
	if (line2)
	{
		printf("fd2\n");
		print_line(line2, fd2);
		free(line2);
	}
	close(fd1);
	close(fd2);
}

int main(int ac, char **av)
{
	(void)ac;
	(void)av;
	std_in_bonus();
	return (0);
}
// clear && ccw main_bonus.c get_next_line_bonus.c get_next_line_utils_bonus.c -o a.out && ./a.out
// clear && cc -Wall -Wextra -Werror main_bonus.c get_next_line_bonus.c get_next_line_utils_bonus.c -o a.out && ./a.out