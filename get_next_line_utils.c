/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lseeger <lseeger@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 15:25:32 by lseeger           #+#    #+#             */
/*   Updated: 2024/10/18 16:00:36 by lseeger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_nl(char *buffer, ssize_t bytes_read)
{
	const char	*buffer_start = buffer;

	while ((buffer - buffer_start) < bytes_read && *buffer != '\n' && *buffer)
		buffer++;
	return (buffer);
}

long	ft_strlen(char *str)
{
	const char	*str_start = str;

	if (!str)
		return (-1);
	else
	{
		while (*str)
			str++;
		return (str - str_start);
	}
}

char	*re_nl(char *nl, char *buffer, char *next_nl)
{
	const long	nl_len = ft_strlen(nl);
	char		*new_nl;
	long		i;

	i = -1;
	if (!nl)
	{
		new_nl = malloc(sizeof(char) * (next_nl - buffer + 1));
		if (new_nl == NULL)
			return (NULL);
		while (++i < (next_nl - buffer))
			new_nl[i] = buffer[i];
		new_nl[i] = 0;
		return (new_nl);
	}
	new_nl = malloc(sizeof(char) * (nl_len + next_nl - buffer + 1));
	if (!new_nl)
		return (NULL);
	while (++i < nl_len)
		new_nl[i] = nl[i];
	i = -1;
	while (++i < (next_nl - buffer))
		new_nl[i + nl_len] = buffer[i];
	new_nl[i + nl_len] = 0;
	return (free(nl), new_nl);
}

void	update_buffer(char *buffer, char *next_nl)
{
	long	i;

	i = next_nl - buffer;
	while (--i >= 0)
		buffer[i] = buffer[next_nl - buffer + i];
}
