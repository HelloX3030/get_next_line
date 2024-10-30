/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lseeger <lseeger@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 16:17:13 by lseeger           #+#    #+#             */
/*   Updated: 2024/10/30 13:32:58 by lseeger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# include <fcntl.h>
# include <stddef.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 5
# endif

# define MAX_FILE_DESCRIPTORS 1024

typedef struct s_lst
{
	struct s_lst	*next;
	char			str[BUFFER_SIZE + 1];
}					t_lst;

// handle functions
char				*get_next_line(int fd);
char				*handle_nl_in_rest(char *next_nl, char *rest);
char				*handle_zero_read(t_lst *lst, size_t bonus_len);
char				*handle_nl_found(char *next_nl, char *buffer, t_lst *lst,
						char *rest);

// utils
char				*find_nl(char *str, ssize_t bytes_read);
t_lst				*lst_add(t_lst *lst, char *buffer, ssize_t bytes_read);
void				lst_clear(t_lst *lst);
void				*ft_memmove(void *dst, const void *src, size_t len);
size_t				ft_strlen(const char *s);

#endif
