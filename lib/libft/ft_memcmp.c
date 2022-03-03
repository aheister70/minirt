/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_memcmp.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: aheister <aheister@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/10/28 16:08:55 by aheister      #+#    #+#                 */
/*   Updated: 2021/04/29 15:58:27 by aheister      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned int	i;
	unsigned int	diff;
	unsigned char	*s1_char;
	unsigned char	*s2_char;

	s1_char = (unsigned char *)s1;
	s2_char = (unsigned char *)s2;
	i = 0;
	while (i < n)
	{
		if (s1_char[i] != s2_char[i])
		{
			diff = s1_char[i] - s2_char[i];
			return (diff);
		}
		else if (s1_char[i] == s2_char[i])
			i++;
	}
	return (0);
}
