/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danfern3 <danfern3@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/08 16:54:42 by danfern3          #+#    #+#             */
/*   Updated: 2025/10/14 12:23:08 by danfern3         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

static char	*clean_buffer(char *buffer)
{
	size_t	i;
	size_t	j;
	char	*new_buffer;

	i = 0;
	j = 0;
	while (buffer[i] && buffer[i] != '\n')
		i++;
	if (!buffer[i])
	{
		free(buffer);
		return (NULL);
	}
	new_buffer = malloc(ft_strlen(buffer) - i + 1);
	if (!new_buffer)
		return (NULL);
	i++;
	while (buffer[i])
		new_buffer[j++] = buffer[i++];
	new_buffer[j] = '\0';
	free(buffer);
	return (new_buffer);
}

// char	*ft_strjoin_endl(char const *s1, char const *s2)
// {
// 	char	*result;
// 	size_t	size;
// 	size_t	i;

// 	i = 0;
// 	// printf("%s: s1 != null -> %d \n", __func__, s1 != NULL);
// 	if (!s1 && !s2)
// 		return (NULL);
// 	size = ft_strlen(s1) + ft_strlen(s2) + 1;
// 	// printf("%s: tras obtener total size: %zu \n", __func__, size);
// 	result = malloc(sizeof(char) * size);
// 	if (!result)
// 		return (NULL);
// 	while (s1 && *s1)
// 		result[i++] = *(s1++);
// 	while (*s2)
// 	{
// 		if (*s2 == '\n')
// 		{
// 			// printf("encontrado endl en buffer\n");
// 			result[i++] = '\n';
// 			result[i] = '\0';
// 			// printf("%s: tras recorrer s2 (a.k.a buffer): %zu %s| \n", __func__, i, result);
// 			return (result);
// 		}
// 		result[i++] = *s2++;
// 	}
// 	result[i] = '\0';
// 	// printf("result: %s|\n", result);
// 	return (result);
// }

// char	*ft_free_join_endl(char *line, char *buffer)
// {
// 	char	*ret;

// 	// printf("%s: %s\n", __func__, line);
// 	if (line == NULL)
// 	{
// 		// printf("%s: line == NULL\n", __func__);
// 		line = ft_strdup("");
// 		if (!line)
// 			return (NULL);
// 	}
// 	// printf("%s: line != NULL: %s\n", __func__, line);
// 	ret = ft_strjoin_endl(line, buffer);
// 	// printf("%s: ret: %s|\n", __func__, ret);
// 	free(line);
// 	return (ret);
// }

// char	*ft_free_join(char *line, char *buffer)
// {
// 	char	*ret;

// 	if (!line)
// 	{
// 		line = ft_strdup("");
// 		if (!line)
// 			return (NULL);
// 	}
// 	ret = ft_strjoin(line, buffer);
// 	free(line);
// 	return (ret);
// }

static char	*ft_till_endl(char *s)
{
	size_t	new_size;

	if (!s || !s[0])
		return (NULL);
	new_size = 0;
	while (s[new_size])
	{
		if (s[new_size] == '\n')
			return (ft_substr(s, 0, new_size + 1));
		++new_size;
	}
	return (ft_substr(s, 0, new_size));
}

// char	*get_next_line(int fd)
// {
// 	char		*line;
// 	static char	*buffer;
// 	ssize_t		endl;
// 	ssize_t		bytes;

// 	buffer = malloc(sizeof(char) * (BUFFER_SIZE + 1));
// 	if (!buffer)
// 		return (buffer);
// 	line = NULL;
// 	buffer[BUFFER_SIZE] = '\0';
// 	bytes = read(fd, buffer, BUFFER_SIZE);
// 	// printf("%s: bytes leidos: %zu\n", __func__, bytes);
// 	while (bytes > 0)
// 	{
// 		endl = ft_strchr(buffer, '\n');
// 		// printf("%s: endl pos: %zd\n", __func__, endl);
// 		if (endl < 0)
// 			line = ft_free_join(line, buffer);
// 		else
// 		{
// 			printf("%s: %s\n", __func__, line);
// 			line = ft_free_join_endl(line, buffer);
// 			printf("%s: antes de llamar a print_line\n", __func__);
// 			print_line(line);
// 			free(buffer);
// 			return (line);
// 		}
// 		bytes = read(fd, buffer, BUFFER_SIZE);
// 	}
// 	free(buffer);
// 	return (line);
// }

static char	*ft_read_file(int fd, char *line)
{
	char	*buffer;
	ssize_t	bytes;

	// printf("%s\n", __func__);
	buffer = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buffer)
		return (buffer);
	bytes = 1;
	while (!ft_strchr(line, '\n') && bytes > 0)
	{
		// printf("%s asdf\n", __func__);
		bytes = read(fd, buffer, BUFFER_SIZE);
		if (bytes == -1)
		{
			free(buffer);
			free(line);
			return (NULL);
		}
		buffer[bytes] = '\0';
		// printf("%s\n", __func__);
		line = ft_strjoin(line, buffer);
		// printf("%s\n", __func__);
	}
	free(buffer);
	// printf("%s\n", __func__);
	return (line);
}

char	*get_next_line(int fd)
{
	static char	*buffer;
	char		*line;

	if (fd < 0 || fd > MAX_FD || BUFFER_SIZE <= 0)
		return (NULL);
	buffer = NULL;
	buffer = ft_read_file(fd, buffer);
	if (!buffer)
		return (NULL);
	line = ft_till_endl(buffer);
	buffer = clean_buffer(buffer);
	return (line);
}
