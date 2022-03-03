/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_itoa.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: aheister <aheister@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/03 19:48:23 by aheister      #+#    #+#                 */
/*   Updated: 2021/04/29 15:57:33 by aheister      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>
#include <limits.h>

static char	*ft_malloc(int len)
{
	char	*nbr;

	nbr = (char *)malloc((len + 1) * sizeof(char));
	return (nbr);
}

static int	ft_intlen(int n)
{
	int	i;
	int	len;

	len = 0;
	i = n;
	while (i != 0)
	{
		i = i / 10;
		len++;
	}
	if (n <= 0)
		len = len + 1;
	return (len);
}

char	*ft_itoa(int n)
{
	char	*nbr;
	int		len;

	if (n == INT_MIN)
		return (ft_strdup("-2147483648"));
	len = ft_intlen(n);
	nbr = ft_malloc(len);
	if (!nbr)
		return (0);
	if (n < 0)
	{
		nbr[0] = '-';
		n = n * -1;
	}
	if (n == 0)
		nbr[0] = '0';
	nbr[len] = '\0';
	while (n > 0)
	{
		len--;
		nbr[len] = n % 10 + '0';
		n = n / 10;
	}
	return (nbr);
}
