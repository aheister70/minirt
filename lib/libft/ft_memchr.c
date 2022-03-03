/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_memchr.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: aheister <aheister@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/10/28 13:22:56 by aheister      #+#    #+#                 */
/*   Updated: 2020/11/19 12:38:46 by aheister      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned int	i;
	unsigned char	*str_char;

	str_char = (unsigned char *)s;
	i = 0;
	while (i < n)
	{
		if (str_char[i] == (unsigned char)c)
			return (&str_char[i]);
		i++;
	}
	return (0);
}
