/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   cylinder2.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: aheister <aheister@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/05/14 13:20:57 by aheister      #+#    #+#                 */
/*   Updated: 2021/06/26 11:28:10 by aheister      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

/*
** CALCULATE_DISCRIMINANT - calculates if a ray hits a cylinder
** CALCULATE_ORIENT_CY - calculates the orient of the hitted point
** FILL_PIXEL_CYLINDER - Fills the pixel values when cylinder is the closest
** CALCULATE_LENGTH - Helper of the function calculate_closest_cy
*/

#include "minirt.h"

float	calculate_discriminant(t_vector ray, t_cylinder *cy, t_scene *scene
		, int id)
{
	t_vector	length;
	float		p;
	float		discriminant;

	scene->abc.x = 1 - dot_vectors(ray, cy->orient)
		* dot_vectors(ray, cy->orient);
	if (id == 0)
		length = substract_vectors(scene->origin_ray, cy->point);
	else
		length = substract_vectors(scene->light_point, cy->point);
	p = dot_vectors(length, cy->orient);
	scene->abc.y = 2 * dot_vectors(ray, length) - 2 * p
		* dot_vectors(ray, cy->orient);
	scene->abc.z = dot_vectors(length, length) - (cy->diameter / 2)
		* (cy->diameter / 2) - p * p;
	discriminant = scene->abc.y * scene->abc.y - 4 * scene->abc.x
		* scene->abc.z;
	return (discriminant);
}

t_vector	calculate_orient_cy(t_vector ray, t_cylinder *cy, t_scene *scene)
{
	t_vector	point_a;
	t_vector	point_b;
	float		t;

	scene->pixel.point = vector_constant(ray, scene->pixel.t);
	scene->pixel.point = add_vectors(scene->pixel.point, scene->camera.point);
	point_a = substract_vectors(scene->pixel.point, cy->point);
	t = dot_vectors(point_a, cy->orient);
	point_b = vector_constant(cy->orient, t);
	point_a = substract_vectors(point_a, point_b);
	point_a = normalize_vector(point_a);
	return (point_a);
}

void	fill_pixel_cylinder(t_cylinder *cy, t_scene *scene, t_vector ray,
			int type)
{
	t_vector	length;
	float		angle;

	scene->pixel.first = 1;
	if (type == 1)
		scene->pixel.orient = calculate_orient_cy(ray, cy, scene);
	else
	{
		scene->pixel.orient = cy->orient;
		scene->pixel.point = calculate_i(scene, scene->pixel.t);
		scene->pixel.orient = cy->orient;
		length = substract_vectors(scene->pixel.point, scene->origin_ray);
		angle = dot_vectors(length, scene->pixel.orient);
		if (angle > 0)
			scene->pixel.orient = vector_constant(scene->pixel.orient, -1);
	}
	scene->pixel.color = add_lights(scene, cy->color, cy->id);
}

float	calculate_length(t_cylinder *cy, float t_tmp, t_scene *scene, int id)
{
	t_vector	length;
	float		dir;

	length = vector_constant(scene->ray, t_tmp);
	if (id == 0)
		length = add_vectors(scene->origin_ray, length);
	else
		length = add_vectors(scene->light_point, length);
	length = substract_vectors(length, cy->point);
	dir = dot_vectors(length, cy->orient);
	if (id != 0 && cy->id != id)
		dir = -dir;
	if (dir <= cy->height / 2 && dir >= -cy->height / 2)
		return (t_tmp);
	else
		return (INFINITY);
}
