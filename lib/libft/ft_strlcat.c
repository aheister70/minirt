/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strlcat.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: aheister <aheister@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/10/27 07:47:30 by aheister      #+#    #+#                 */
/*   Updated: 2021/04/29 16:01:19 by aheister      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stddef.h>

static int	ft_strnlen(char *str, unsigned int size)
{
	unsigned int	len;

	len = 0;
	while (len < size && *str)
	{
		len++;
		str++;
	}
	return (len);
}

static char	*ft_strncpy(char *dst, unsigned int len_dst,
const char *src, unsigned int n)
{
	unsigned int	i;

	dst = dst + len_dst;
	i = 0;
	while (i < n && src[i] != '\0')
	{
		dst[i] = src[i];
		i++;
	}
	while (i < n)
	{
		dst[i] = '\0';
		i++;
	}
	return (dst);
}

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	unsigned int	len_dst;
	unsigned int	len_src;

	if (!dst && !src)
		return (0);
	len_dst = (unsigned int)ft_strnlen(dst, dstsize);
	len_src = (unsigned int)ft_strlen(src);
	if (len_dst == dstsize)
		return (dstsize + len_src);
	if (len_src < dstsize - len_dst)
		ft_strncpy(dst, len_dst, src, len_src + 1);
	else
	{
		ft_strncpy(dst, len_dst, src, dstsize - len_dst - 1);
		dst[dstsize - 1] = '\0';
	}
	return (len_dst + len_src);
}
