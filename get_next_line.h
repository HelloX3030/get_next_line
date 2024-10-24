/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lseeger <lseeger@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 15:26:28 by lseeger           #+#    #+#             */
/*   Updated: 2024/10/24 13:56:35 by lseeger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <fcntl.h>
# include <stdbool.h>
# include <stddef.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1
# endif

// Handle Functions
char	*get_next_line(int fd);
void	failure_cleanup(char *nl);
char	*handle_found_nl(char *buffer, char *next_nl, char *nl);
int		handle_start_buffer(char *buffer, char **nl);

// Utilitz Functions
char	*get_next_nl(char *s);
ssize_t	ft_strlen(const char *s);
char	*ft_strdup(const char *s);
char	*ft_strjoin(const char *s1, char const *s2);
void	*ft_memmove(void *dst, const void *src, size_t len);

#endif
