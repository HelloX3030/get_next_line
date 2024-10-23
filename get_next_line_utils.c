/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lseeger <lseeger@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 15:25:32 by lseeger           #+#    #+#             */
/*   Updated: 2024/10/23 16:51:54 by lseeger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_nl(char *s)
{
	while (*s)
	{
		if (*s == '\n')
			return (s);
		s++;
	}
	return (NULL);
}

char	*ft_strdup(const char *s)
{
	char		*new_str;
	const int	s_len = ft_strlen(s);

	new_str = malloc(sizeof(char) * (s_len) + 1);
	if (new_str == NULL)
		return (NULL);
	ft_memmove(new_str, s, s_len + 1);
	return (new_str);
}

char	*ft_strjoin(char *s1, char const *s2)
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
	if (new_str == NULL)
		return (NULL);
	i = -1;
	while (++i < len1)
		new_str[i] = s1[i];
	j = -1;
	while (++j < len2)
		new_str[i + j] = s2[j];
	new_str[i + j] = 0;
	free(s1);
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

// char	*get_next_nl(char *buffer, ssize_t bytes_read)
// {
// 	ssize_t	i;

// 	i = 0;
// 	while (i < BUFFER_SIZE && buffer[i] && i < bytes_read && buffer[i] != '\n')
// 		i++;
// 	return (&buffer[i]);
// }

// char	*re_nl(char *nl, char *buffer, char *next_nl)
// {
// 	const ptrdiff_t	nl_len = ft_strlen(nl);
// 	char			*new_nl;
// 	ptrdiff_t		new_nl_len;

// 	new_nl_len = nl_len;
// 	if (*next_nl == '\n')
// 		next_nl++;
// 	new_nl_len += (next_nl - buffer);
// 	new_nl = malloc(new_nl_len + 1);
// 	if (!new_nl)
// 		return (NULL);
// 	custom_cpy(new_nl, nl, nl_len);
// 	custom_cpy(new_nl + nl_len, buffer, next_nl - buffer);
// 	new_nl[new_nl_len] = 0;
// 	return (free(nl), new_nl);
// }

// ptrdiff_t	custom_cpy(char *dest, const char *src, ptrdiff_t len)
// {
// 	ptrdiff_t	i;

// 	i = 0;
// 	while (i < len)
// 	{
// 		dest[i] = src[i];
// 		i++;
// 	}
// 	return (i);
// }

// ptrdiff_t	ft_strlen(const char *s)
// {
// 	ptrdiff_t	i;

// 	if (!s || !*s)
// 		return (0);
// 	i = 0;
// 	while (s[i])
// 		i++;
// 	return (i);
// }

// char	*update_buffer(char *buffer, char *nl, char *next_nl,
// 		ssize_t bytes_read)
// {
// 	ptrdiff_t	shift;
// 	size_t		i;

// 	// printf("buffer:%s", buffer);
// 	// printf("nl:%s", nl);
// 	// printf("next_nl:%s", next_nl);
// 	// printf("bytes_read:%ld\n", bytes_read);
// 	i = 0;
// 	if (bytes_read <= 0)
// 	{
// 		while (i <= BUFFER_SIZE)
// 			buffer[i++] = 0;
// 		if (bytes_read <= -1 && nl)
// 			return (free(nl), NULL);
// 		return (nl);
// 	}
// 	else
// 	{
// 		shift = next_nl - buffer + 1;
// 		while (i + shift < BUFFER_SIZE && buffer[i + shift])
// 		{
// 			buffer[i] = buffer[i + shift];
// 			i++;
// 		}
// 		while (i <= BUFFER_SIZE)
// 			buffer[i++] = 0;
// 		return (nl);
// 	}
// }
