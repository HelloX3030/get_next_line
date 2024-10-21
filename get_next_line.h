/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lseeger <lseeger@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 15:26:28 by lseeger           #+#    #+#             */
/*   Updated: 2024/10/21 13:56:13 by lseeger          ###   ########.fr       */
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
#  define BUFFER_SIZE 100
# endif

char	*get_next_line(int fd);
char	*get_next_nl(char *buffer, ssize_t bytes_read);
char	*re_nl(char *nl, char *buffer, char *next_nl);
void	custom_cpy(char *dest, const char *start, const char *end);
char	*get_str_end(const char *str);
void	update_buffer(char *buffer, char *next_nl);

#endif
