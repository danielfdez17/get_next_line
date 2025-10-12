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

static char	*ft_free_join(char *result, char *buffer)
{
	char	*ret;

	ret = ft_strjoin(result, buffer);
	if (!ret)
		free(buffer);
	free(result);
	return (ret);
}

char	*ft_till_endl(char const *s)
{
	size_t	new_size;

	new_size = 0;
	while (s[new_size] && s[new_size] != '\n')
		++new_size;
	return (ft_substr(s, 0, new_size));
}

char	*get_next_line(int fd)
{
	static char		*buffer;
	static char		*result;
	char 			*endl;
	size_t 		read_bytes;

	result = malloc(sizeof(char) * 1);
	if (!result)
		return (result);
	buffer = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buffer)
		return (buffer);
	while ((read_bytes = read(fd, buffer, sizeof(BUFFER_SIZE))) > 0)
	{
		endl = ft_strchr(buffer, '\n');
		if (!endl)
			result = ft_free_join(result, buffer);
		else {
			result = ft_free_join(result, ft_till_endl(buffer));
			break;
		}
	}
	return (result);
}

#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
int	main(int ac, char **av)
{
	(void)ac;
	(void)av;
	// printf("%s|\n", get_next_line(0));
	int fd;
	if ((fd = open(av[1], O_RDONLY)) != -1)
	{
		printf("%s\n", get_next_line(fd));
	}
	else
		printf("Error al leer el archivo\n");
	close(fd);
	return (0);
}
// ccw -D BUFFER_SIZE=42 *.c -o a.out && ./a.out


// int main(int ac, char **av) {
// 	(void)ac;
//     char *buffer;
//     // size_t tamano_buffer = 100;
//     ssize_t bytes_leidos;

//     int fd = open(av[1], O_RDONLY);
// 	printf("hola hola hola\n");

//     if (fd == -1) {
//         printf("No se pudo abrir el archivo.\n");
//         return 1;
//     }

//     buffer = (char *) malloc(BUFFER_SIZE);

//     while ((bytes_leidos = read(fd, buffer, BUFFER_SIZE)) > 0) {
//         char *nuevo_buffer = (char *) realloc(buffer, BUFFER_SIZE * 2);
//         if (nuevo_buffer == NULL) {
//             printf("No se pudo asignar memoria.\n");
//             free(buffer);
//             close(fd);
//             return 1;
//         }
//         buffer = nuevo_buffer;
//     }
// 	printf("%s\n", buffer);
//     free(buffer);
//     close(fd);

//     return 0;
// }