/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lseeger <lseeger@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 15:25:13 by lseeger           #+#    #+#             */
/*   Updated: 2024/10/18 16:00:57 by lseeger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static char	buffer[BUFFER_SIZE];
	char		*nl;
	char		*next_nl;
	ssize_t		bytes_read;

	if (!*buffer)
		bytes_read = read(fd, buffer, BUFFER_SIZE);
	else
		bytes_read = BUFFER_SIZE;
	next_nl = get_next_nl(buffer, bytes_read);
	printf("%s: %s\n", buffer, next_nl);
	while (*next_nl != '\n')
	{
		nl = re_nl(nl, buffer, next_nl);
		if (!nl)
			return (NULL);
		bytes_read = read(fd, buffer, BUFFER_SIZE);
	}
	update_buffer(buffer, next_nl);
	return (nl);
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
		printf("%s", next_line);
		next_line = get_next_line(fd);
	}
	close(fd);
	return (0);
}
