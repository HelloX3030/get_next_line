/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lseeger <lseeger@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 16:16:52 by lseeger           #+#    #+#             */
/*   Updated: 2024/10/29 15:48:02 by lseeger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*get_next_line(int fd)
{
	static char	rest[MAX_FILE_DESCRIPTORS][BUFFER_SIZE];
	char		buffer[BUFFER_SIZE];
	char		*next_nl;
	t_lst		*lst;
	ssize_t		result;

	next_nl = find_nl(rest[fd]);
	if (next_nl)
		return (handle_nl_in_rest(next_nl, rest));
	lst = lst_add(NULL, rest[fd]);
	if (!lst)
		return (NULL);
	while (1)
	{
		result = read(fd, buffer, BUFFER_SIZE);
		if (result == -1)
			return (lst_clear(lst), NULL);
		else if (result == 0)
			return (handle_zero_read(lst));
		next_nl = find_nl(buffer);
		if (next_nl != NULL)
			return (handle_nl_found(next_nl, buffer, lst, rest[fd]));
		if (!lst_add(lst, buffer))
			return (lst_clear(lst), NULL);
	}
}

char	*handle_nl_in_rest(char *next_nl, char *rest)
{
	char			*new_str;
	const ptrdiff_t	dif = next_nl - rest;

	new_str = malloc(dif + 1);
	if (!new_str)
		return (NULL);
	ft_memmove(new_str, rest, dif);
	new_str[dif] = 0;
	ft_memmove(rest, next_nl, BUFFER_SIZE - dif);
	rest[BUFFER_SIZE - dif] = 0;
	return (new_str);
}

char	*handle_nl_found(char *next_nl, char *buffer, t_lst *lst, char *rest)
{
	char		*new_str;
	size_t		len;
	const t_lst	*lst_start = lst;

	len = ft_strlen(buffer) + 1;
	while (lst)
	{
		len += ft_strlen(lst->str);
		lst = lst->next;
	}
	new_str = malloc(len);
	if (!new_str)
		return (NULL);
	len = ft_strlen(buffer);
	ft_memmove(new_str, buffer, len);
	lst = lst_start;
	while (lst)
	{
		ft_memmove(new_str + len, lst->str, ft_strlen(lst->str));
		len += ft_strlen(lst->str);
		lst = lst->next;
	}
	return (lst_clear(lst), new_str);
}

// create new_str => buffer bis next_nl + lst
// update rest => buffer after next_nl