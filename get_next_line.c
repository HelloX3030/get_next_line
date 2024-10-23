/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lseeger <lseeger@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 15:25:13 by lseeger           #+#    #+#             */
/*   Updated: 2024/10/23 16:53:21 by lseeger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	failure_cleanup(char *buffer, char *nl)
{
	*buffer = 0;
	if (nl)
		free(nl);
}

char	*handle_found_nl(char *buffer, char *next_nl, char *nl)
{
	*next_nl = 0;
	nl = ft_strjoin(nl, buffer);
	if (!nl)
		return (NULL);
	ft_memmove(buffer, next_nl + 1, ft_strlen(next_nl + 1));
	return (nl);
}

char	*handle_zero_read(char *buffer, char *nl)
{
	char	*new_str;

	if (*buffer)
	{
		new_str = ft_strjoin(nl, buffer);
		if (!new_str)
			return (NULL);
		*buffer = 0;
		return (new_str);
	}
	else
		return (NULL);
}

char	*get_next_line(int fd)
{
	static char	buffer[BUFFER_SIZE + 1];
	char		*next_nl;
	char		*nl;
	ssize_t		bytes_read;

	nl = NULL;
	while (1)
	{
		next_nl = get_next_nl(buffer);
		if (next_nl)
			return (handle_found_nl(buffer, next_nl, nl));
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		if (bytes_read == -1)
			return (failure_cleanup(buffer, nl), NULL);
		else if (bytes_read == 0)
			return (handle_zero_read(buffer, nl));
		nl = ft_strjoin(nl, buffer);
		if (!nl)
			return (NULL);
	}
}

// int	main(void)
// {
// 	int		fd;
// 	char	*next_line;

// 	fd = open("e.txt", O_RDONLY);
// 	if (fd == -1)
// 	{
// 		perror("Failed to open e.txt");
// 		return (-1);
// 	}
// 	next_line = get_next_line(fd);
// 	while (next_line)
// 	{
// 		printf("%s\n-----------------------\n", next_line);
// 		free(next_line);
// 		next_line = get_next_line(fd);
// 	}
// 	close(fd);
// 	return (0);
// }

// char	*get_next_line(int fd)
// {
// 	static char	buffer[BUFFER_SIZE + 1];
// 	char		*nl;
// 	char		*next_nl;
// 	ssize_t		bytes_read;

// 	if (!*buffer)
// 		bytes_read = read(fd, buffer, BUFFER_SIZE);
// 	else
// 		bytes_read = BUFFER_SIZE;
// 	nl = NULL;
// 	if (bytes_read <= 0)
// 		return (update_buffer(buffer, nl, NULL, bytes_read));
// 	while (bytes_read > 0)
// 	{
// 		next_nl = get_next_nl(buffer, bytes_read);
// 		nl = re_nl(nl, buffer, next_nl);
// 		if (!nl)
// 			return (NULL);
// 		if (*next_nl == '\n')
// 			return (update_buffer(buffer, nl, next_nl, bytes_read));
// 		bytes_read = read(fd, buffer, BUFFER_SIZE);
// 	}
// 	return (update_buffer(buffer, nl, next_nl, bytes_read));
// }
