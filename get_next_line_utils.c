/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danfern3 <danfern3@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/08 16:54:44 by danfern3          #+#    #+#             */
/*   Updated: 2025/10/08 17:50:17 by danfern3         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		++i;
	return (i);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*result;
	size_t	size;
	size_t	i;

	i = 0;
	size = ft_strlen(s1) + ft_strlen(s2) + 1;
	result = malloc(sizeof(char) * size);
	if (!result)
		return (NULL);
	while (*s1)
		result[i++] = *s1++;
	while (*s2)
		result[i++] = *s2++;
	result[i] = '\0';
	return (result);
}
