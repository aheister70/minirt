/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strrchr.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: aheister <aheister@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/10/30 10:43:51 by aheister      #+#    #+#                 */
/*   Updated: 2020/11/06 16:50:30 by aheister      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(char *s, int c)
{
	unsigned int	i;
	char			*temp;
	unsigned int	str_len;
	int				temp_exists;

	temp_exists = 0;
	str_len = ft_strlen(s);
	i = 0;
	while (i <= (str_len))
	{
		if (s[i] == c)
		{
			temp = &s[i];
			temp_exists = 1;
		}
		i++;
	}
	if (temp_exists == 1)
		return (temp);
	else
		return (0);
}
