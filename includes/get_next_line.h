/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_next_line.h                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: aheister <aheister@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/21 13:33:37 by aheister      #+#    #+#                 */
/*   Updated: 2021/04/29 16:21:07 by aheister      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# define BUFFER_SIZE 100

# include <unistd.h>
# include <stdlib.h>

char			*ft_realloc(char *left, int new_len);
char			*ft_fillstr(char *s, int start, int c);
char			*fill_buf(int fd);
char			*fill_left(char *left, char *buf);
char			*ft_filljoin(char *s1, char *s2, char *join_s, int len);
int				get_next_line(int fd, char **line);
int				get_line(int fd, char **line);
int				ft_nl(char *s);
char			*ft_strjoin_gnl(char *left, char *buf);
size_t			ft_strlen(const char *s);
#endif
