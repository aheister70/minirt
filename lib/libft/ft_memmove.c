/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_memmove.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: aheister <aheister@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/10/28 11:06:33 by aheister      #+#    #+#                 */
/*   Updated: 2020/11/18 10:02:33 by aheister      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned int	i;
	unsigned char	*dst_char;
	unsigned char	*src_char;

	if (!dst && !src)
		return (0);
	dst_char = (unsigned char *)dst;
	src_char = (unsigned char *)src;
	i = 0;
	while (i < len)
	{
		if (dst < src)
			dst_char[i] = src_char[i];
		else
			dst_char[len - i - 1] = src_char[len - i - 1];
		i++;
	}
	dst = dst_char;
	return (dst);
}
