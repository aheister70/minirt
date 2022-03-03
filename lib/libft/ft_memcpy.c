/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_memcpy.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: aheister <aheister@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/10/30 08:30:21 by aheister      #+#    #+#                 */
/*   Updated: 2020/11/18 10:02:18 by aheister      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	unsigned int	i;
	unsigned char	*dst_char;
	unsigned char	*src_char;

	if (!dst && !src)
		return (0);
	dst_char = (unsigned char *)dst;
	src_char = (unsigned char *)src;
	i = 0;
	while (i < n)
	{
		dst_char[i] = src_char[i];
		i++;
	}
	if (dst_char != 0)
		dst = dst_char;
	return (dst);
}
