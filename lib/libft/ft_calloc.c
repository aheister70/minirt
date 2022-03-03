/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_calloc.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: aheister <aheister@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/01 10:05:52 by aheister      #+#    #+#                 */
/*   Updated: 2021/04/29 15:54:02 by aheister      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

void	*ft_calloc(size_t count, size_t size)
{
	void	*new_ptr;

	new_ptr = malloc(count * size);
	if (!new_ptr)
		return (0);
	ft_memset(new_ptr, 0, (count * size));
	return (new_ptr);
}
