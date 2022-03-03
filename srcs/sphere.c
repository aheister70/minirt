/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   sphere.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: aheister <aheister@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/05/14 13:20:16 by aheister      #+#    #+#                 */
/*   Updated: 2021/06/26 12:01:11 by aheister      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

/*
** INIT_SPHERE - Assigns values from RT file to struct s_sphere (id: 1)
** FILL_PIXEL_SPHERE - Fills the pixel values when sphere has the closest pixel
** CALCULATE_CLOSEST - Calculates the closest intersection with the sphere
** INTERSECT_SPHERE - calculates if a given ray intersecs a given sphere
*/

#include "minirt.h"

void	init_sphere(char **object, t_scene *scene)
{	
	t_sphere	*sphere;

	if (split_amount(object) != 4)
		error_handling("Scene contains wrong sphere format.", object, scene);
	sphere = ft_calloc(1, sizeof(t_sphere));
	if (!sphere)
		error_handling("Fail to malloc sphere.", object, scene);
	sphere->point = split_vector(object[1], scene, 0);
	if (c_check(object[2], '.') > 1 || str_check(object[2]) == 0)
		error_handling("Sphere has an invalid diameter.", object, scene);
	sphere->diameter = ft_atof(object[2]);
	if (sphere->diameter <= 0)
		error_handling("Sphere has an invalid diameter.", object, scene);
	sphere->color = split_color(object[3], scene);
	scene->amount_objects++;
	sphere->id = scene->amount_objects;
	sphere->type = 1;
	ft_lstadd_back(&scene->list_objects, ft_lstnew(1, sphere));
	free_split(object);
}

void	fill_pixel_sphere(t_sphere *sp, t_scene *scene, int in)
{
	scene->pixel.first = 1;
	scene->pixel.point = calculate_i(scene, scene->pixel.t);
	scene->pixel.orient = substract_vectors(scene->pixel.point, sp->point);
	scene->pixel.orient = normalize_vector(scene->pixel.orient);
	if (in == 1)
	{
		scene->pixel.orient = vector_constant(scene->pixel.orient, -1);
		scene->pixel.color = add_lights(scene, sp->color, 0);
	}
	else
		scene->pixel.color = add_lights(scene, sp->color, sp->id);
}

float	calculate_closest(t_sphere *sp, t_vector ray, t_vector length)
{
	float		tca;
	float		thc;
	float		d2;
	float		t0;
	float		t1;

	tca = dot_vectors(length, ray);
	if (tca < 0)
		return (0);
	d2 = dot_vectors(length, length) - tca * tca;
	if (d2 > (sp->diameter / 2) * (sp->diameter / 2))
		return (0);
	thc = sqrt((sp->diameter / 2) * (sp->diameter / 2) - d2);
	t0 = tca - thc;
	t1 = tca + thc;
	if (t0 < 0 && t1 < 0)
		return (0);
	if (t0 < 0)
	{
		printf("ja");
		t0 = t1;
		t0 = t0 * -1;
	}
	return (t0);
}

void	intersect_sphere(t_vector ray, void *p_sphere, t_scene *scene, int id)
{
	int			inside;
	float		t;
	t_vector	length;
	t_sphere	*sp;

	inside = 0;
	sp = p_sphere;
	if (id == 0)
		length = substract_vectors(sp->point, scene->origin_ray);
	else
		length = substract_vectors(sp->point, scene->light_point);
	t = calculate_closest(sp, ray, length);
	if (t < 0)
	{
		inside = 1;
		t = t * -1;
	}
	if (id == 0 && t > 0 && (scene->pixel.first == 0 || t < scene->pixel.t))
	{
		scene->pixel.t = t;
		fill_pixel_sphere(sp, scene, inside);
	}
	else if (sp->id != id && t > 0 && t < scene->length)
		scene->shadow = 1;
}
