/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lseeger <lseeger@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 15:25:32 by lseeger           #+#    #+#             */
/*   Updated: 2024/10/24 12:08:55 by lseeger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

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

char	*ft_strdup(const char *s)
{
	char		*new_str;
	const int	s_len = ft_strlen(s);

	new_str = malloc(s_len + 1);
	if (!new_str)
		return (NULL);
	ft_memmove(new_str, s, s_len + 1);
	return (new_str);
}

char	*ft_strjoin(const char *s1, char const *s2)
{
	const int	len1 = ft_strlen(s1);
	const int	len2 = ft_strlen(s2);
	char		*new_str;
	int			i;
	int			j;

	if (s1 && !s2)
		return (ft_strdup(s1));
	else if (!s1 && s2)
		return (ft_strdup(s2));
	new_str = malloc(sizeof(char) * (len1 + len2 + 1));
	if (!new_str)
		return (NULL);
	i = -1;
	while (++i < len1)
		new_str[i] = s1[i];
	j = -1;
	while (++j < len2)
		new_str[i + j] = s2[j];
	new_str[i + j] = 0;
	return (new_str);
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
