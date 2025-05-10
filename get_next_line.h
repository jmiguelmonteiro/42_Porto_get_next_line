/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: josemigu <josemigu@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/05 15:57:20 by josemigu          #+#    #+#             */
/*   Updated: 2025/05/10 12:45:30 by josemigu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <stdbool.h>
# include <stdio.h>
# include <limits.h>
# include <stdint.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1000
# endif

char	*get_next_line(int fd);
char	*add_buffer_to_raw(char *raw_line, char *buffer);
char	*read_fd(int fd, char *raw_line, char *buffer);
void	update_buffer(char *raw_line, char *buffer);
size_t	ft_strlen(const char *s);
char	*ft_strchr(const char *s, int c);
char	*ft_strjoin(char const *s1, char const *s2);
void	*ft_memmove(void *dest, const void *src, size_t n);
void	*ft_memset(void *s, int c, size_t n);
void	*ft_calloc(size_t nmemb, size_t size);
void	*ft_memchr(const void *s, int c, size_t n);
char	*ft_free_null(char *str);

#endif
