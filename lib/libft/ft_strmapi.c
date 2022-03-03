/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strmapi.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: aheister <aheister@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/08 14:46:08 by aheister      #+#    #+#                 */
/*   Updated: 2020/11/19 12:56:15 by aheister      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	int		i;
	int		len;
	char	*it_s;

	if (!s || !f)
		return (0);
	len = ft_strlen(s);
	it_s = (char *)malloc((len + 1) * sizeof(char));
	if (!it_s)
		return (0);
	i = 0;
	while (s[i])
	{
		it_s[i] = f(i, s[i]);
		i++;
	}
	it_s[i] = '\0';
	return (it_s);
}
