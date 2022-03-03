/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_atoi.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: aheister <aheister@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/10/30 13:11:09 by aheister      #+#    #+#                 */
/*   Updated: 2021/04/29 15:53:24 by aheister      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

int	ft_atoi(const char *str)
{
	int	i;
	int	b;
	int	result;

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
	while (str[i] >= '0' && str[i] <= '9')
	{
		if (result > (2147483648 / 10) && b == -1)
			return (0);
		if (result > (2147483648 / 10))
			return (-1);
		result = result * 10 + (str[i] - '0');
		i++;
	}
	return (result * b);
}
