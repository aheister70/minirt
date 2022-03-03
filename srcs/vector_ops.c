/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   vector_ops.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: aheister <aheister@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/05/08 12:51:02 by aheister      #+#    #+#                 */
/*   Updated: 2021/06/25 16:14:05 by aheister      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

/*
** FILL_VECTOR - fills a vector with the 3 values that are inserted
** SUBSTRACT_VECTORS - substracts vector b from vector a
** ADD_VECTORS - adds vector b to a
** VECTOR_CONSTANT - calculates each direction with a constant value
*/

#include "minirt.h"

t_vector	fill_vector(float x, float y, float z)
{
	t_vector	vector;

	vector.x = x;
	vector.y = y;
	vector.z = z;
	return (vector);
}

t_vector	substract_vectors(t_vector a, t_vector b)
{
	a.x = a.x - b.x;
	a.y = a.y - b.y;
	a.z = a.z - b.z;
	return (a);
}

t_vector	add_vectors(t_vector a, t_vector b)
{
	a.x = a.x + b.x;
	a.y = a.y + b.y;
	a.z = a.z + b.z;
	return (a);
}

t_vector	vector_constant(t_vector vector, float constant)
{
	vector.x = vector.x * constant;
	vector.y = vector.y * constant;
	vector.z = vector.z * constant;
	return (vector);
}
