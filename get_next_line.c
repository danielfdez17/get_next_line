/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danfern3 <danfern3@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/08 16:54:42 by danfern3          #+#    #+#             */
/*   Updated: 2025/10/08 19:48:43 by danfern3         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

char	*get_next_line(int fd)
{
	static char		buffer[MAX_BUFFER_LEN];
	static char		*result;
	unsigned int	i;
	char			c;
	unsigned int	same_char;

	i = 0;
	same_char = 0;
	result = "";
	while (i < MAX_BUFFER_LEN && c != '\n' && c != EOF)
	{
		read(fd, &c, sizeof(char));
		// printf("%c -- %i\n", c, i);
		if (buffer[i] == c)
			same_char++;
		buffer[i++] = c;
		if (same_char == MAX_BUFFER_LEN)
			return (result);
		if (i == MAX_BUFFER_LEN && c != '\n' && c != EOF)
		{
			result = ft_strjoin(result, buffer);
			i = 0;
			same_char = 0;
		}
	}
	return (result);
}

#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
int	main(void)
{
	printf("%s|", get_next_line(0));
	// int fd = open("./test.txt", O_RDONLY);
	// if (fd != -1)
	// {
	// 	printf("%s|", get_next_line(fd));
	// }
	// else
	// 	printf("Error al leer el archivo\n");
	// close(fd);
	return (0);
}
// ccw -D BUFFER_SIZE=42 *.c -o a.out && ./a.out