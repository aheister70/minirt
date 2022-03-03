/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_bzero.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: aheister <aheister@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/10/27 19:19:05 by aheister      #+#    #+#                 */
/*   Updated: 2020/11/19 12:29:05 by aheister      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stddef.h>

void	ft_bzero(void *s, size_t n)
{
	unsigned char	*s_char;

	s_char = (unsigned char *)s;
	ft_memset(s_char, 0, n);
	s = s_char;
}
