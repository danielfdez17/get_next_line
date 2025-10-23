/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danfern3 <danfern3@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/08 16:54:36 by danfern3          #+#    #+#             */
/*   Updated: 2025/10/15 16:07:13 by danfern3         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
#define GET_NEXT_LINE_BONUS_H
#ifndef BUFFER_SIZE
#define BUFFER_SIZE 128
#endif

#ifndef MAX_FD
#define MAX_FD 256
#endif

#include <unistd.h>
#include <stdlib.h>

// !REMOVE
#include <stdio.h>

void print_line(char *line, int fd);

char *get_next_line(int fd);
char *ft_strjoin(char *s1, char *s2);
size_t ft_strlen(const char *s);
char *ft_strchr(const char *s, int c);
char *ft_substr(char *s, unsigned int start, size_t len);
char *ft_strdup(const char *s);

#endif