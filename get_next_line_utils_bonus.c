/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lseeger <lseeger@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 16:18:55 by lseeger           #+#    #+#             */
/*   Updated: 2024/10/29 15:21:38 by lseeger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*find_nl(char *str)
{
	size_t	i;

	i = 0;
	while (str[i] && i < BUFFER_SIZE)
	{
		if (str[i] == '\n')
			return (str + i);
		i++;
	}
	return (NULL);
}

void	lst_clear(t_lst *lst)
{
	if (lst)
	{
		lst_clear(lst->next);
		free(lst);
	}
}

t_lst	*lst_add(t_lst *lst, char *buffer)
{
	t_lst	*new_element;
	size_t	i;

	new_element = malloc(sizeof(t_lst));
	if (!new_element)
		return (NULL);
	new_element->next = NULL;
	i = 0;
	while (buffer[i] && i < BUFFER_SIZE)
	{
		new_element->str[i] = buffer[i];
		i++;
	}
	if (i < BUFFER_SIZE)
		new_element->str[i] = 0;
	if (!lst)
		return (new_element);
	while (lst->next)
		lst = lst->next;
	lst->next = new_element;
	return (new_element);
}

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char	*dst_ptr;
	unsigned char	*src_ptr;
	size_t			i;

	if (dst == src || len <= 0)
		return (dst);
	dst_ptr = (unsigned char *)dst;
	src_ptr = (unsigned char *)src;
	if (dst > src)
	{
		while (--len)
			dst_ptr[len] = src_ptr[len];
		dst_ptr[len] = src_ptr[len];
	}
	else
	{
		i = 0;
		while (i < len)
		{
			dst_ptr[i] = src_ptr[i];
			i++;
		}
	}
	return (dst);
}

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}
