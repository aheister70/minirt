/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strlcpy.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: aheister <aheister@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/10/29 15:42:44 by aheister      #+#    #+#                 */
/*   Updated: 2020/11/19 12:55:48 by aheister      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stddef.h>

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	unsigned int	i;
	size_t			sizecmp;

	if (!dst && !src)
		return (0);
	i = 0;
	if (dstsize > 0)
	{
		while (src[i] && (i < (dstsize - 1)))
		{
			dst[i] = src[i];
			i++;
		}
		dst[i] = '\0';
		if (i < ft_strlen(src))
			return (ft_strlen(src));
		else
		{
			sizecmp = i;
			return (sizecmp);
		}
	}
	else
		return (ft_strlen(src));
}
