/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strchr.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: aheister <aheister@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/10/30 10:07:31 by aheister      #+#    #+#                 */
/*   Updated: 2020/11/01 14:40:23 by aheister      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(char *s, int c)
{
	unsigned int	i;
	char			*temp;

	i = 0;
	while (i <= ft_strlen(s))
	{
		if (s[i] == c)
		{
			temp = &s[i];
			return (temp);
		}
		i++;
	}
	return (0);
}
