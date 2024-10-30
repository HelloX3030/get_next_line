/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lseeger <lseeger@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 16:16:52 by lseeger           #+#    #+#             */
/*   Updated: 2024/10/30 13:52:14 by lseeger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"
#include <string.h>

char	*get_next_line(int fd)
{
	static char	rest[MAX_FILE_DESCRIPTORS][BUFFER_SIZE + 1];
	char		buffer[BUFFER_SIZE];
	char		*next_nl;
	t_lst		*lst;
	ssize_t		bytes_read;

	next_nl = find_nl(rest[fd], BUFFER_SIZE);
	if (next_nl)
		return (handle_nl_in_rest(next_nl, rest[fd]));
	lst = lst_add(NULL, rest[fd], BUFFER_SIZE);
	if (!lst)
		return (NULL);
	while (1)
	{
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		if (bytes_read == -1)
			return (lst_clear(lst), NULL);
		else if (bytes_read == 0)
			return (handle_zero_read(lst, 0));
		next_nl = find_nl(buffer, bytes_read);
		if (next_nl != NULL)
			return (handle_nl_found(next_nl, buffer, lst, rest[fd]));
		if (!lst_add(lst, buffer, bytes_read))
			return (lst_clear(lst), NULL);
	}
}

char	*handle_nl_in_rest(char *next_nl, char *rest)
{
	char			*new_str;
	const ptrdiff_t	dif = next_nl - rest;

	new_str = malloc(dif + 2);
	if (!new_str)
		return (NULL);
	ft_memmove(new_str, rest, dif);
	new_str[dif] = '\n';
	new_str[dif + 1] = 0;
	ft_memmove(rest, next_nl + 1, BUFFER_SIZE - dif);
	rest[BUFFER_SIZE - dif] = 0;
	return (new_str);
}

char	*handle_zero_read(t_lst *lst, size_t bonus_len)
{
	const t_lst	*lst_start = lst;
	char		*new_str;
	size_t		len;

	len = 0;
	while (lst)
	{
		len += ft_strlen(lst->str);
		lst = lst->next;
	}
	if (len == 0 && bonus_len == 0)
		return (lst_clear((t_lst *)lst_start), NULL);
	new_str = malloc(len + bonus_len + 1);
	if (!new_str)
		return (lst_clear((t_lst *)lst_start), NULL);
	lst = (t_lst *)lst_start;
	len = 0;
	while (lst)
	{
		ft_memmove(new_str + len, lst->str, ft_strlen(lst->str));
		len += ft_strlen(lst->str);
		lst = lst->next;
	}
	new_str[len] = 0;
	return (lst_clear((t_lst *)lst_start), new_str);
}

char	*handle_nl_found(char *next_nl, char *buffer, t_lst *lst, char *rest)
{
	char			*new_str;
	size_t			len;
	const ptrdiff_t	dif = next_nl - buffer;

	new_str = handle_zero_read(lst, dif + 1);
	if (!new_str)
		return (NULL);
	len = ft_strlen(new_str);
	ft_memmove(new_str + len, buffer, dif + 1);
	ft_memmove(rest, next_nl + 1, BUFFER_SIZE - dif);
	rest[BUFFER_SIZE - dif] = 0;
	return (new_str);
}

// int	main(void)
// {
// 	char	*str;
// 	int		fd;

// 	fd = open("test.txt", O_RDONLY);
// 	str = get_next_line(fd);
// 	while (str)
// 	{
// 		printf("<%s>\n", str);
// 		free(str);
// 		str = get_next_line(fd);
// 	}
// 	return (0);
// }
