/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_memccpy.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: aheister <aheister@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/10/29 16:48:11 by aheister      #+#    #+#                 */
/*   Updated: 2020/11/19 12:37:57 by aheister      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	unsigned int	i;
	unsigned char	*dest_char;
	unsigned char	*src_char;

	dest_char = (unsigned char *)dst;
	src_char = (unsigned char *)src;
	i = 0;
	while (i < n)
	{
		dest_char[i] = src_char[i];
		if (src_char[i] != (unsigned char)c)
			i++;
		else
			return (&dest_char[i + 1]);
	}
	return (0);
}
