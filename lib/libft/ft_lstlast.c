/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_lstlast.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: aheister <aheister@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/17 13:55:21 by aheister      #+#    #+#                 */
/*   Updated: 2020/11/18 11:03:08 by aheister      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstlast(t_list *lst)
{
	int	len;
	int	i;

	i = 0;
	len = ft_lstsize(lst);
	while (i < len - 1)
	{
		lst = lst->next;
		i++;
	}
	return (lst);
}
