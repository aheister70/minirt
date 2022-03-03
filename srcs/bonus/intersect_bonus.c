/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   intersect_bonus.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: aheister <aheister@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/05/15 13:16:19 by aheister      #+#    #+#                 */
/*   Updated: 2021/06/25 16:12:00 by aheister      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

/*
** INTERSECT_OBJECTS - checks if a ray intersects an object
** CALCULATE_I - calculates the coordinates of a (possible) intersection point
** CALCULATE_I_SHADOW - calculates an intersection point with shadow ray
** CALCULATE_T - calculates length t between camera and intersection point
** CALCULATE_T_SHADOW - calculates length t between light and intersection point 
*/

#include "minirt.h"

void	intersect_objects(t_scene *scene, t_vector ray, t_list *list_objects
		, int id)
{
	if (list_objects->type == 1)
		intersect_sphere(ray, list_objects->content, scene, id);
	else if (list_objects->type == 2)
		intersect_plane(ray, list_objects->content, scene, id);
	else if (list_objects->type == 3)
		intersect_cylinder(ray, list_objects->content, scene, id);
	else if (list_objects->type == 4)
		intersect_triangle(ray, list_objects->content, scene, id);
}

t_vector	calculate_i(t_scene *scene, float t)
{
	t_vector	point;

	point.x = (1 - t) * scene->camera.point.x + t * scene->origin_ray.x;
	point.y = (1 - t) * scene->camera.point.y + t * scene->origin_ray.y;
	point.z = (1 - t) * scene->camera.point.z + t * scene->origin_ray.z;
	return (point);
}

t_vector	calculate_i_shadow(t_scene *scene, float t)
{
	t_vector	point;

	point.x = (1 - t) * scene->pixel.point.x + t * scene->origin_ray.x;
	point.y = (1 - t) * scene->pixel.point.y + t * scene->origin_ray.y;
	point.z = (1 - t) * scene->pixel.point.z + t * scene->origin_ray.z;
	return (point);
}

float	calculate_t(t_scene *scene, t_vector orient, t_vector point)
{
	float	t;
	float	dot_pc;
	float	dot_pp;
	float	dot_pr;

	dot_pc = dot_vectors(orient, scene->camera.point);
	dot_pp = dot_vectors(orient, point);
	dot_pr = dot_vectors(orient, scene->origin_ray);
	t = (dot_pp - dot_pc) / (dot_pr - dot_pc);
	return (t);
}

float	calculate_t_shadow(t_scene *scene, t_vector orient, t_vector point)
{
	float	t;
	float	dot_pc;
	float	dot_pp;
	float	dot_pr;

	dot_pc = dot_vectors(orient, scene->light_point);
	dot_pp = dot_vectors(orient, point);
	dot_pr = dot_vectors(orient, scene->pixel.point);
	t = (dot_pp - dot_pc) / (dot_pr - dot_pc);
	return (t);
}
