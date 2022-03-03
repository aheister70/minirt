/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strdup.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: aheister <aheister@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/01 10:04:09 by aheister      #+#    #+#                 */
/*   Updated: 2020/11/19 12:50:25 by aheister      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strdup(const char *s1)
{
	unsigned int	c;
	char			*pt_scopy;

	c = ft_strlen(s1) + 1;
	pt_scopy = (char *)malloc(c * sizeof(char));
	if (!pt_scopy)
		return (0);
	c = 0;
	while (s1[c])
	{
		pt_scopy[c] = s1[c];
		c++;
	}
	pt_scopy[c] = '\0';
	return (pt_scopy);
}
