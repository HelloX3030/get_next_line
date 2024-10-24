/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lseeger <lseeger@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 15:25:13 by lseeger           #+#    #+#             */
/*   Updated: 2024/10/24 12:34:06 by lseeger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	failure_cleanup(char *nl)
{
	if (nl)
		free(nl);
}

char	*handle_found_nl(char *buffer, char *next_nl, char *nl)
{
	const ssize_t	nl_len = ft_strlen(nl);
	char			*new_nl;

	new_nl = malloc(buffer - next_nl + nl_len + 1);
	if (!new_nl)
	{
		failure_cleanup(nl);
		return (NULL);
	}
	ft_memmove(new_nl, nl, nl_len);
	ft_memmove(new_nl + nl_len, buffer, next_nl - buffer);
	ft_memmove(buffer, next_nl + 1, ft_strlen(next_nl + 1) + 1);
	return (new_nl);
}

char	*handle_zero_read(char *buffer, char *nl)
{
	char	*new_str;

	if (*buffer)
	{
		new_str = ft_strjoin(nl, buffer);
		if (!new_str)
			return (failure_cleanup(nl), NULL);
		*buffer = 0;
		return (failure_cleanup(nl), new_str);
	}
	else
		return (NULL);
}

int	handle_start_buffer(char *buffer, char **nl)
{
	char	*next_nl;

	if (!*buffer)
		return (0);
	next_nl = get_next_nl(buffer);
	if (next_nl)
		return (*nl = handle_found_nl(buffer, next_nl, *nl), 1);
	else
	{
		*nl = ft_strdup(buffer);
		if (!*nl)
			return (*nl = NULL, 1);
		else
			return (0);
	}
}

char	*get_next_line(int fd)
{
	static char	buffer[BUFFER_SIZE + 1] = {0};
	char		*next_nl;
	char		*nl;
	ssize_t		bytes_read;
	char		*new_nl;

	nl = NULL;
	if (handle_start_buffer(buffer, &nl))
		return (nl);
	while (1)
	{
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		if (bytes_read == -1)
			return (*buffer = 0, failure_cleanup(nl), NULL);
		else if (bytes_read == 0)
			return (handle_zero_read(buffer, nl));
		buffer[bytes_read] = 0;
		next_nl = get_next_nl(buffer);
		if (next_nl)
			return (handle_found_nl(buffer, next_nl, nl));
		new_nl = ft_strjoin(nl, buffer);
		failure_cleanup(nl);
		if (!new_nl)
			return (NULL);
		nl = new_nl;
	}
}

int	main(void)
{
	int		fd;
	char	*next_line;

	fd = open("e.txt", O_RDONLY);
	if (fd == -1)
	{
		perror("Failed to open e.txt");
		return (-1);
	}
	next_line = get_next_line(fd);
	while (next_line)
	{
		printf("%s\n-----------------------\n", next_line);
		free(next_line);
		next_line = get_next_line(fd);
	}
	close(fd);
	return (0);
}
