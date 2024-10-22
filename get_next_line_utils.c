/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lseeger <lseeger@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 15:25:32 by lseeger           #+#    #+#             */
/*   Updated: 2024/10/22 13:59:04 by lseeger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_nl(char *buffer, ssize_t bytes_read)
{
	ssize_t	i;

	i = 0;
	while (i < BUFFER_SIZE && buffer[i] && i < bytes_read && buffer[i] != '\n')
		i++;
	return (&buffer[i]);
}

char	*re_nl(char *nl, char *buffer, char *next_nl)
{
	const ptrdiff_t	nl_len = ft_strlen(nl);
	char			*new_nl;
	ptrdiff_t		new_nl_len;

	new_nl_len = nl_len;
	if (*next_nl == '\n')
		next_nl++;
	new_nl_len += (next_nl - buffer);
	new_nl = malloc(new_nl_len + 1);
	if (!new_nl)
		return (NULL);
	custom_cpy(new_nl, nl, nl_len);
	custom_cpy(new_nl + nl_len, buffer, next_nl - buffer);
	new_nl[new_nl_len] = 0;
	return (free(nl), new_nl);
}

ptrdiff_t	custom_cpy(char *dest, const char *src, ptrdiff_t len)
{
	ptrdiff_t	i;

	i = 0;
	while (i < len)
	{
		dest[i] = src[i];
		i++;
	}
	return (i);
}

ptrdiff_t	ft_strlen(const char *s)
{
	ptrdiff_t	i;

	if (!s || !*s)
		return (0);
	i = 0;
	while (s[i])
		i++;
	return (i);
}

char	*update_buffer(char *buffer, char *nl, char *next_nl,
		ssize_t bytes_read)
{
	ptrdiff_t	shift;
	size_t		i;

	i = 0;
	if (bytes_read <= -1)
	{
		while (i <= BUFFER_SIZE)
			buffer[i++] = 0;
		if (nl)
			free(nl);
		return (NULL);
	}
	else
	{
		shift = next_nl - buffer + 1;
		while (i + shift < BUFFER_SIZE && buffer[i + shift])
		{
			buffer[i] = buffer[i + shift];
			i++;
		}
		while (i < BUFFER_SIZE)
			buffer[i++] = 0;
		return (nl);
	}
}
