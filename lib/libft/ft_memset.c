/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_memset.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: aheister <aheister@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/10/26 11:28:54 by aheister      #+#    #+#                 */
/*   Updated: 2020/11/18 10:02:48 by aheister      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

void	*ft_memset(void *b, int c, size_t len)
{
	unsigned int	i;
	unsigned char	*b_char;

	b_char = (unsigned char *)b;
	i = 0;
	while (i < len)
	{
		b_char[i] = c;
		i++;
	}
	b = b_char;
	return (b);
}
