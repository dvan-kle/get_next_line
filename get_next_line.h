/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_next_line.h                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: dvan-kle <dvan-kle@student.42.fr>            +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/31 17:36:35 by dvan-kle      #+#    #+#                 */
/*   Updated: 2022/11/09 15:11:31 by dvan-kle      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>

char	*ft_calloc(size_t count, size_t size);
int		ft_strchr(char *str, int c);
size_t	ft_strlen(const char *str);
char	*ft_strjoin(char *s1, char *s2);
char	*ft_strdup(const char *src);
char	*get_next_line(int fd);
char	*get_str(int fd, char *str);
char	*new_line(char *str2);
char	*leftover(char *str);

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1000
# endif

#endif