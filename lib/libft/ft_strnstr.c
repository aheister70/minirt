/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strnstr.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: aheister <aheister@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/10/27 19:12:06 by aheister      #+#    #+#                 */
/*   Updated: 2020/11/19 12:56:56 by aheister      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

char	*ft_strnstr(char *haystack, char *needle, size_t len)
{
	unsigned int	i;
	unsigned int	n;

	i = 0;
	if (needle[0] == 0)
		return (haystack);
	while (haystack[i] && i < len)
	{
		n = 0;
		while (haystack[i + n] == needle[n])
		{
			if ((needle[n + 1] == '\0') && (i + n < len))
				return (&haystack[i]);
			n++;
		}
		i++;
	}
	return (0);
}
