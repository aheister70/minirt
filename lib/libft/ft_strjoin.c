/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strjoin.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: aheister <aheister@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/02 09:23:05 by aheister      #+#    #+#                 */
/*   Updated: 2021/04/29 16:00:06 by aheister      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static char	*ft_filljoin(char const *s1, char const *s2,
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

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*join_s;
	int		len;

	if (s1 && s2)
	{
		len = ft_strlen(s1) + ft_strlen(s2);
		join_s = (char *)malloc((len + 1) * sizeof(char));
		if (join_s == NULL)
			return (0);
		ft_filljoin(s1, s2, join_s, len);
		return (join_s);
	}
	else
		return (0);
}
