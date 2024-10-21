/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lseeger <lseeger@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 15:25:32 by lseeger           #+#    #+#             */
/*   Updated: 2024/10/21 14:36:09 by lseeger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_nl(char *buffer, ssize_t bytes_read)
{
	ssize_t	i;

	i = 0;
	while (buffer[i] && i < bytes_read && buffer[i] != '\n')
		i++;
	return (&buffer[i]);
}

char	*re_nl(char *nl, char *buffer, char *next_nl)
{
	char	*new_nl;
	char	*nl_end;

	if (!nl)
	{
		new_nl = malloc(sizeof(char) * (next_nl - buffer + 1));
		if (!new_nl)
			return (NULL);
		custom_cpy(new_nl, buffer, next_nl);
		new_nl[next_nl - buffer] = '\0';
	}
	else
	{
		nl_end = get_str_end(nl);
		new_nl = malloc(sizeof(char) * (nl_end - nl + next_nl - buffer + 1));
		if (!new_nl)
			return (NULL);
		custom_cpy(new_nl, nl, nl_end);
		custom_cpy(&new_nl[nl_end - nl + 1], buffer, next_nl);
		new_nl[(nl_end - nl) + (next_nl - buffer)] = '\0';
	}
	return (free(nl), new_nl);
}

void	custom_cpy(char *dest, const char *start, const char *end)
{
	size_t	i;

	i = 0;
	while (start + i <= end)
	{
		dest[i] = start[i];
		i++;
	}
}

char	*get_str_end(const char *str)
{
	size_t	i;

	if (!str)
		return (NULL);
	if (!*str)
		return ((char *)str);
	i = 0;
	while (str[i + 1])
		i++;
	return ((char *)&str[i]);
}

void	update_buffer(char *buffer, char *next_nl)
{
	const ptrdiff_t	shift = next_nl - buffer + 1;
	ptrdiff_t		i;

	i = 0;
	while (i + shift < BUFFER_SIZE && buffer[i + shift])
	{
		buffer[i] = buffer[i + shift];
		i++;
	}
	while (i < BUFFER_SIZE)
		buffer[i++] = 0;
}
