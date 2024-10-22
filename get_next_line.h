/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lseeger <lseeger@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 15:26:28 by lseeger           #+#    #+#             */
/*   Updated: 2024/10/22 13:54:03 by lseeger          ###   ########.fr       */
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

char		*get_next_line(int fd);
char		*get_next_nl(char *buffer, ssize_t bytes_read);
char		*re_nl(char *nl, char *buffer, char *next_nl);
ptrdiff_t	custom_cpy(char *dest, const char *src, ptrdiff_t len);
ptrdiff_t	ft_strlen(const char *s);
char		*update_buffer(char *buffer, char *nl, char *next_nl,
				ssize_t bytes_read);

#endif
