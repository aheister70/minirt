/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_substr.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: aheister <aheister@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/10/31 08:56:54 by aheister      #+#    #+#                 */
/*   Updated: 2020/11/18 10:11:29 by aheister      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stddef.h>
#include <stdlib.h>

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char			*sub_s;
	unsigned int	n;

	if (!len || !s)
		return (ft_strdup(""));
	if (start > ft_strlen(s))
		return (ft_strdup(""));
	sub_s = (char *)malloc((len + 1) * sizeof(char));
	if (sub_s == NULL)
		return (0);
	n = 0;
	while (n < len)
	{
		sub_s[n] = s[start + n];
		n++;
	}
	sub_s[n] = '\0';
	return (sub_s);
}
