/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strtrim.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: aheister <aheister@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/02 12:59:05 by aheister      #+#    #+#                 */
/*   Updated: 2021/04/29 16:06:11 by aheister      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static int	ft_isset(char c, char const *set)
{
	int	n;

	n = 0;
	while (set[n] != '\0')
	{
		if (c == set[n])
			return (1);
		else
			n++;
	}
	return (0);
}

static unsigned int	find_start(char const *s1, char const *set)
{
	unsigned int	i;

	i = 0;
	while (s1[i] != '\0')
	{
		if (ft_isset(s1[i], set) == 1)
			i++;
		else
			break ;
	}
	return (i);
}

static unsigned int	find_end(char const *s1, char const *set,
unsigned int start)
{
	unsigned int	len;

	len = ft_strlen(s1);
	while (len > start)
	{
		if (ft_isset(s1[len - 1], set) == 1)
			len--;
		else
			break ;
	}
	return (len);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char			*cpy_s1;
	unsigned int	start;
	unsigned int	end;

	if (s1 && set)
	{
		start = find_start(s1, set);
		end = find_end(s1, set, start);
		cpy_s1 = ft_substr(s1, start, (end - start));
		return (cpy_s1);
	}
	else
		return (0);
}
