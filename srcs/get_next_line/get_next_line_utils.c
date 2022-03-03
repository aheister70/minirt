/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_next_line_utils.c                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: aheister <aheister@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/26 14:20:17 by aheister      #+#    #+#                 */
/*   Updated: 2021/05/27 11:50:39 by aheister      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *s)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

char	*ft_realloc(char *left, int new_len)
{
	char	*new_left;

	if (left)
	{
		new_left = malloc((new_len + 1) * sizeof(char));
		if (!new_left)
			return (0);
		return (new_left);
	}
	new_left = malloc((new_len + 1) * sizeof(char));
	if (!new_left)
		return (0);
	return (new_left);
}

int	ft_nl(char *s)
{
	int	i;

	if (!s)
		return (-1);
	i = 0;
	while (s[i])
	{
		if (s[i] == '\n')
			return (i);
		else
			i++;
	}
	return (-1);
}

char	*ft_filljoin(char *s1, char *s2,
char *join_s, int len)
{
	int		i;
	int		n;

	i = 0;
	n = 0;
	while ((i + n) < len)
	{
		while (s1[i])
		{
			join_s[i] = s1[i];
			i++;
		}
		while (s2[n])
		{
			join_s[i + n] = s2[n];
			n++;
		}
	}
	join_s[i + n] = '\0';
	return (join_s);
}

char	*ft_strjoin_gnl(char *s1, char *s2)
{
	char	*join_s;
	int		len;

	if (s1 || s2)
	{
		len = (int)ft_strlen(s1) + (int)ft_strlen(s2);
		join_s = ft_realloc(s1, len);
		if (!join_s)
			return (0);
		join_s = ft_filljoin(s1, s2, join_s, len);
		if (s1)
			free(s1);
		return (join_s);
	}
	else
		return (0);
}
