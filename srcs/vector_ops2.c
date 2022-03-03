/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   vector_ops2.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: aheister <aheister@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/05/08 12:51:02 by aheister      #+#    #+#                 */
/*   Updated: 2021/06/25 16:14:10 by aheister      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

/*
** DOT_VECTORS - calculates the dot product of 2 vectors (0 means perpendicul)
** PRODUCT_VECTORS - calculates the vector perpendicular to vector a and b
** NORMALIZE_VECTOR - tranforms the vector to a length 1: normalizing
** MULTIPLY_BY_MATRIX - multiplies a point with translation/rotation matrix
** VECTOR_MATRIX - calculates the total of a vector multiplied with a constant
*/

#include "minirt.h"

float	dot_vectors(t_vector a, t_vector b)
{
	return (a.x * b.x + a.y * b.y + a.z * b.z);
}

t_vector	product_vectors(t_vector a, t_vector b)
{
	t_vector	product;

	product.x = a.y * b.z - a.z * b.y;
	if (product.x == -0.000000)
		product.x = 0;
	product.y = a.z * b.x - a.x * b.z;
	if (product.y == -0.000000)
		product.y = 0;
	product.z = a.x * b.y - a.y * b.x;
	if (product.z == -0.000000)
		product.z = 0;
	return (product);
}

t_vector	normalize_vector(t_vector vector)
{
	double	length;

	length = sqrt((double)vector.x * (double)vector.x + (double)vector.y
			* (double)vector.y + (double)vector.z * (double)vector.z);
	vector.x = vector.x / length;
	vector.y = vector.y / length;
	vector.z = vector.z / length;
	return (vector);
}

t_vector	multiply_by_matrix(t_vector p, t_scene *scene)
{
	t_vector	res;

	res.x = p.x * scene->ctw.matrix[0][0] + p.y * scene->ctw.matrix[1][0]
		+ p.z * scene->ctw.matrix[2][0] + scene->ctw.matrix[3][0];
	res.y = p.x * scene->ctw.matrix[0][1] + p.y * scene->ctw.matrix[1][1]
		+ p.z * scene->ctw.matrix[2][1] + scene->ctw.matrix[3][1];
	res.z = p.x * scene->ctw.matrix[0][2] + p.y * scene->ctw.matrix[1][2]
		+ p.z * scene->ctw.matrix[2][2] + scene->ctw.matrix[3][2];
	return (res);
}

float	vector_matrix(t_vector vector, float constant)
{
	float	value;

	vector.x = vector.x * constant;
	vector.y = vector.y * constant;
	vector.z = vector.z * constant;
	value = vector.x + vector.y + vector.z;
	return (value);
}
