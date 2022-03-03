/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   initialize_checks.c                                :+:    :+:            */
/*                                                     +:+                    */
/*   By: aheister <aheister@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/05/13 12:30:50 by aheister      #+#    #+#                 */
/*   Updated: 2021/06/25 16:13:17 by aheister      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

/*
** C_CHECK - counts the amount of comma's in the string
** SPLIT_CHECK - checks if every substrings contains only digits or a .
** STR_CHECK - checks if a string contains only digits or a .
*/

#include "minirt.h"

int	c_check(char *string, char c)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (string[i])
	{
		if (string[i] == c)
			count++;
		i++;
	}
	return (count);
}

int	split_check(char **split)
{
	int	i;
	int	j;

	i = 0;
	while (split[i])
	{
		j = 0;
		while (split[i][j])
		{
			if ((split[i][j] < '0' || split[i][j] > '9')
				&& split[i][j] != '-' && split[i][j] != '.')
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int	str_check(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if ((str[i] < '0' || str[i] > '9') && str[i] != '.')
			return (0);
		i++;
	}
	return (1);
}
