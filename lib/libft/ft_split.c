/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_split.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: aheister <aheister@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/11 20:01:17 by aheister      #+#    #+#                 */
/*   Updated: 2021/05/27 11:43:01 by aheister      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>

static int	ft_amount_sub_s(char const *s, char c)
{
	int	i;
	int	sub_s;

	i = 0;
	sub_s = 0;
	while (s[i])
	{
		if (i == 0 && s[i] != c)
			sub_s++;
		if (s[i] == c && s[i + 1] != c && s[i + 1] != '\0')
			sub_s++;
		i++;
	}
	return (sub_s);
}

static char	*ft_fill_sub(char const *s, int i, int len)
{
	int		j;
	char	*sub_array;

	sub_array = (char *)malloc((len + 1) * sizeof(char));
	if (!sub_array)
		return (0);
	j = 0;
	while (j < len)
	{
		sub_array[j] = s[i - len + j];
		j++;
	}
	sub_array[j] = '\0';
	return (sub_array);
}

static char	**ft_fill_s(char const *s, char **array, char c, int amount_sub)
{
	int	i;
	int	len;
	int	n;

	i = 0;
	n = 0;
	while (n < amount_sub && s[i])
	{
		len = 0;
		while (s[i] != c && s[i])
		{
			len++;
			i++;
		}
		if ((s[i] == c || s[i] == '\0') && len > 0)
		{
			array[n] = ft_fill_sub(s, i, len);
			if (array[n] == 0)
				return (0);
			n++;
		}
		i++;
	}
	array[n] = NULL;
	return (array);
}

char	**ft_split(char const *s, char c)
{
	char	**array;
	int		amount_sub;

	if (!s)
		return (0);
	amount_sub = ft_amount_sub_s(s, c);
	array = (char **)malloc((amount_sub + 1) * sizeof(char *));
	if (!array)
		return (0);
	array = ft_fill_s(s, array, c, amount_sub);
	if (array == 0)
	{
		while (amount_sub > 0)
		{
			if (array[amount_sub])
				free(array[amount_sub]);
			amount_sub--;
		}
		free(array);
		return (0);
	}
	return (array);
}
