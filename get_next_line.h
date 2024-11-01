/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lseeger <lseeger@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 15:26:28 by lseeger           #+#    #+#             */
/*   Updated: 2024/10/25 15:44:00 by lseeger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
#define GET_NEXT_LINE_H

#include <fcntl.h>
#include <stdbool.h>
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#ifndef BUFFER_SIZE
#define BUFFER_SIZE 1
#endif

#define MAX_FILE_DESCRIPTOR 1024

// Handle Functions
char *get_next_line(int fd);
void failure_cleanup(char *nl);
char *handle_found_nl(char *buffer, char *next_nl, char *nl);
bool handle_start_buffer(char *buffer, char **nl, ssize_t *nl_r_len);
bool read_buffer(int fd, char *buffer, char **nl, ssize_t *nl_r_len);

// Utility Functions
char *get_next_nl(char *s);
ssize_t ft_strlen(const char *s);
char *rstr(const char *s, ssize_t *nl_r_len);
bool buffer_join(char **nl, char const *buffer, ssize_t *nl_r_len);
void *ft_memmove(void *dst, const void *src, ssize_t len);

#endif
