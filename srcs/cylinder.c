/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   cylinder.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: aheister <aheister@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/05/14 13:20:57 by aheister      #+#    #+#                 */
/*   Updated: 2021/06/26 15:15:04 by aheister      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

/*
** INIT_CYLINDER - Assigns values from RT file to struct s_cylinder (ob: 3)
** CALCULATE_CLOSEST_CY - calculates which intersections is the closest
** INTERSECT_SIDE - checks if a ray intersects the side of the cylinder
** INTERSECT_CAPS - checks if a ray intersects one of the caps of the cylinder
** INTERSECT_CYLINDER - checks if a ray intersects a cylinder
** 
*/

#include "minirt.h"

void	init_cylinder(char **object, t_scene *scene)
{	
	t_cylinder	*cylinder;

	if (split_amount(object) != 6)
		error_handling("Scene contains wrong cylinder format.", object, scene);
	cylinder = ft_calloc(1, sizeof(t_cylinder));
	if (!cylinder)
		error_handling("Fail to malloc cylinder.", object, scene);
	cylinder->point = split_vector(object[1], scene, 0);
	cylinder->orient = split_vector(object[2], scene, 1);
	if (c_check(object[3], '.') > 1 || str_check(object[3]) == 0)
		error_handling("Cylinder has an invalid diameter.", object, scene);
	cylinder->diameter = ft_atof(object[3]);
	if (cylinder->diameter <= 0)
		error_handling("Cylinder has an invalid diameter.", object, scene);
	if (c_check(object[4], '.') > 1 || str_check(object[4]) == 0)
		error_handling("Cylinder has an invalid height.", object, scene);
	cylinder->height = ft_atof(object[4]);
	if (cylinder->height <= 0)
		error_handling("Cylinder has an invalid height.", object, scene);
	cylinder->color = split_color(object[5], scene);
	scene->amount_objects++;
	cylinder->id = scene->amount_objects;
	cylinder->type = 3;
	ft_lstadd_back(&scene->list_objects, ft_lstnew(3, cylinder));
	free_split(object);
}

float	calculate_closest_cy(t_cylinder *cy, float *t_tmp, t_scene *scene,
		int id)
{
	float		t[2];

	if (t_tmp[0] > 0)
		t[0] = calculate_length(cy, t_tmp[0], scene, id);
	if (t_tmp[1] > 0)
	{
		t[1] = calculate_length(cy, t_tmp[1], scene, id);
		if (t[1] < t[0])
			t[0] = t[1];
	}
	return (t[0]);
}

float	intersect_side(t_vector ray, t_cylinder *cy, t_scene *scene, int id)
{
	float	t[2];
	float	t_side;
	float	q;
	float	discriminant;

	discriminant = calculate_discriminant(ray, cy, scene, id);
	if (discriminant < 0)
		return (0);
	else
	{
		if (scene->abc.y > 0)
			q = -0.5 * (scene->abc.y + sqrt(discriminant));
		else
			q = -0.5 * (scene->abc.y - sqrt(discriminant));
		t[0] = q / scene->abc.x;
		t[1] = scene->abc.z / q;
		t_side = calculate_closest_cy(cy, t, scene, id);
		return (t_side);
	}
}

float	intersect_caps(t_cylinder *cy, t_vector ray, t_scene *scene, int type)
{
	float		t[2];
	t_vector	orient;
	t_vector	length;
	t_vector	point[2];

	length = fill_vector(0, 0, 0);
	orient = cy->orient;
	if (type == 1)
		length = vector_constant(cy->orient, cy->height / 2);
	else if (type == 2)
	{
		length = vector_constant(cy->orient, -cy->height / 2);
		orient = vector_constant(cy->orient, -1);
	}
	point[0] = add_vectors(cy->point, length);
	if (dot_vectors(orient, ray) < 0)
	{
		t[0] = calculate_t(scene, orient, point[0]);
		point[1] = calculate_i(scene, t[0]);
		length = substract_vectors(point[1], point[0]);
		t[1] = sqrt(pow(length.x, 2) + pow(length.y, 2) + pow(length.z, 2));
		if ((t[1] * t[1]) < (cy->diameter / 2) * (cy->diameter / 2))
			return (t[0]);
	}
	return (INFINITY);
}

void	intersect_cylinder(t_vector ray, void *c_cyl, t_scene *scene, int id)
{
	float		t_cap;
	float		t_side;
	t_cylinder	*cy;

	cy = c_cyl;
	scene->ray = ray;
	t_side = intersect_side(ray, cy, scene, id);
	if (intersect_caps(cy, ray, scene, 1) < intersect_caps(cy, ray, scene, 2))
		t_cap = intersect_caps(cy, ray, scene, 1);
	else
		t_cap = intersect_caps(cy, ray, scene, 2);
	if (id == 0 && t_side > 0 && t_side < t_cap && (scene->pixel.first == 0
			|| t_side <= scene->pixel.t))
	{
		scene->pixel.t = t_side;
		fill_pixel_cylinder(cy, scene, ray, 1);
	}
	else if (id == 0 && t_cap > 0 && t_cap < t_side && (scene->pixel.first == 0
			|| t_cap <= scene->pixel.t))
	{
		scene->pixel.t = t_cap;
		fill_pixel_cylinder(cy, scene, ray, 2);
	}
	else if (id != 0 && cy->id != id && t_side > 0 && t_side < scene->length)
		scene->shadow = 1;
}
