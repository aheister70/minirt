/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strncmp.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: aheister <aheister@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/10/27 19:11:49 by aheister      #+#    #+#                 */
/*   Updated: 2021/04/29 16:01:58 by aheister      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	unsigned int	a;
	unsigned int	i;
	unsigned char	*cpy_s1;
	unsigned char	*cpy_s2;

	if (n == 0 || (!s1 && !s2))
		return (0);
	cpy_s1 = (unsigned char *)s1;
	cpy_s2 = (unsigned char *)s2;
	i = 0;
	while ((i < n) && (cpy_s1[i] || cpy_s2[i]))
	{
		if (cpy_s1[i] != cpy_s2[i])
		{
			a = cpy_s1[i] - cpy_s2[i];
			return (a);
		}
		i++;
	}
	return (0);
}
