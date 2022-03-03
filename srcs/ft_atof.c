/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_atof.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: aheister <aheister@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/10/30 13:11:09 by aheister      #+#    #+#                 */
/*   Updated: 2021/06/25 16:12:59 by aheister      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

/*
** CALCULATE_RESULT - calculates the final number
** FT_ATOF - Transforms a string with numbers into a float
*/

float	calculate_result(const char *str, float result, int i, int b)
{
	int		j;

	j = 0;
	while ((str[i] >= '0' && str[i] <= '9') || str[i] == '.')
	{
		if (result > (2147483648 / 10) && b == -1)
			return (0);
		if (result > (2147483648 / 10))
			return (-1);
		if (str[i] == '.')
		{
			i++;
			j++;
		}
		if (j > 0)
			j++;
		result = result * 10 + (str[i] - '0');
		i++;
	}
	while (j > 1)
	{
		result = result / 10;
		j--;
	}
	return (result);
}

float	ft_atof(const char *str)
{
	int		i;
	int		b;
	float	result;

	i = 0;
	b = 1;
	result = 0;
	while (str[i] == 32 || (str[i] >= 8 && str[i] <= 14))
		i++;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			b = -1;
		i++;
	}
	result = calculate_result(str, result, i, b);
	return (result * b);
}
