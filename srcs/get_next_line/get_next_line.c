/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_next_line.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: aheister <aheister@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/28 16:30:01 by aheister      #+#    #+#                 */
/*   Updated: 2021/05/27 11:49:45 by aheister      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_fillstr(char *s, int start, int c)
{
	char	*sub_s;
	int		n;
	int		len;

	if (!s)
		return (0);
	len = (int)ft_strlen(s);
	if (c == 1)
		len = ft_nl(s);
	else if (c == 2)
		len = len - ft_nl(s);
	sub_s = malloc((len + 1) * sizeof(char));
	if (!sub_s)
		return (0);
	n = 0;
	while (n < len)
	{
		sub_s[n] = s[start + n];
		n++;
	}
	sub_s[n] = '\0';
	if (c == 2)
		free(s);
	return (sub_s);
}

char	*fill_buf(int fd)
{
	char		*buf;
	int			ret;

	buf = (char *)malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buf)
		return (0);
	ret = (int)read(fd, buf, BUFFER_SIZE);
	if (ret == -1)
	{
		free(buf);
		return (0);
	}
	buf[ret] = '\0';
	return (buf);
}

char	*fill_left(char *left, char *buf)
{
	if (!buf)
		return (0);
	if (left)
	{
		left = ft_strjoin_gnl(left, buf);
		free(buf);
	}
	else
	{
		left = ft_fillstr(buf, 0, 0);
		free(buf);
	}
	if (!left)
	{
		free(left);
		return (0);
	}
	return (left);
}

int	get_line(int fd, char **line)
{
	static char	*left;
	char		*buf;

	if (!left)
		left = ft_fillstr("", 0, 0);
	while (ft_nl(left) == -1)
	{
		buf = fill_buf(fd);
		if (buf == 0)
			return (-1);
		if (buf[0] == '\0')
		{
			*line = left;
			free(buf);
			return (0);
		}
		left = fill_left(left, buf);
		if (!left)
			return (-1);
	}
	*line = ft_fillstr(left, 0, 1);
	left = ft_fillstr(left, (ft_nl(left) + 1), 2);
	return (1);
}

int	get_next_line(int fd, char **line)
{
	int			ret;

	if (!line || fd < 0 || BUFFER_SIZE < 1 || !BUFFER_SIZE)
		return (-1);
	ret = get_line(fd, line);
	return (ret);
}
