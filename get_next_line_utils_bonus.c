/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lseeger <lseeger@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 16:18:55 by lseeger           #+#    #+#             */
/*   Updated: 2024/11/01 09:20:13 by lseeger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*get_next_nl(char *s)
{
	size_t	i;

	i = 0;
	while (i < BUFFER_SIZE && s[i])
	{
		if (s[i] == '\n')
			return (s + i);
		i++;
	}
	return (NULL);
}

char	*rstr(const char *s, ssize_t *nl_r_len)
{
	char			*new_str;
	const ssize_t	s_len = ft_strlen(s);

	if (*nl_r_len < s_len)
		*nl_r_len = s_len;
	new_str = malloc(*nl_r_len + 1);
	if (!new_str)
		return (NULL);
	ft_memmove(new_str, s, s_len);
	new_str[s_len] = 0;
	return (new_str);
}

bool	buffer_join(char **nl, char const *buffer, ssize_t *nl_r_len)
{
	const ssize_t	nl_len = ft_strlen(*nl);
	const ssize_t	buffer_len = ft_strlen(buffer);
	char			*new_str;

	if (!*nl)
	{
		*nl_r_len = BUFFER_SIZE * 2;
		*nl = rstr(buffer, nl_r_len);
		return (false);
	}
	else if (nl_len + buffer_len < *nl_r_len)
	{
		ft_memmove(*nl + nl_len, buffer, buffer_len);
		(*nl)[nl_len + buffer_len] = 0;
		return (false);
	}
	*nl_r_len = buffer_len + (nl_len * 2);
	new_str = malloc(*nl_r_len + 1);
	if (!new_str)
		return (failure_cleanup(*nl), true);
	ft_memmove(new_str, *nl, nl_len);
	ft_memmove(new_str + nl_len, buffer, buffer_len + 1);
	free(*nl);
	*nl = new_str;
	return (false);
}

void	*ft_memmove(void *dst, const void *src, ssize_t len)
{
	unsigned char	*dst_ptr;
	unsigned char	*src_ptr;
	ssize_t			i;

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

ssize_t	ft_strlen(const char *s)
{
	ssize_t	i;

	if (!s)
		return (0);
	i = 0;
	while (s[i])
		i++;
	return (i);
}
