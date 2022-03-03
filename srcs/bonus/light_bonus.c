/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   light_bonus.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: aheister <aheister@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/05/23 15:10:22 by aheister      #+#    #+#                 */
/*   Updated: 2021/06/25 16:12:07 by aheister      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

/*
** CHECK_SHADOW - checks if the pixel is in the shadow
** CALCULATE_LIGHT - calculates the color of a pixel with a light ray
** CALCULATE_VIEW - calculates the color of a pixel with the camera angle
** WALK_LIST_LIGHTS - goes through the list of lights to add up all of them
** ADD_LIGHTS - calculates the final color of a pixel with all lights
*/

#include "minirt.h"

void	check_shadow(t_scene *scene, t_vector ray, int id)
{
	t_list		*list_tmp;

	list_tmp = scene->list_objects;
	while (list_tmp)
	{
		if (list_tmp->type == 1)
			intersect_sphere(ray, list_tmp->content, scene, id);
		else if (list_tmp->type == 2)
			intersect_plane(ray, list_tmp->content, scene, id);
		else if (list_tmp->type == 3)
			intersect_cylinder(ray, list_tmp->content, scene, id);
		else if (list_tmp->type == 4)
			intersect_triangle(ray, list_tmp->content, scene, id);
		list_tmp = list_tmp->next;
	}
}

t_color	calculate_light(t_scene *scene, void *p_light, int id)
{
	t_vector	dir;
	float		light_amount;
	t_color		light_color;
	t_light		*light;

	light = p_light;
	scene->shadow = 0;
	dir = substract_vectors(scene->pixel.point, light->point);
	scene->length = sqrt((dir.x * dir.x) + (dir.y * dir.y) + (dir.z * dir.z));
	dir = normalize_vector(dir);
	scene->light_point = light->point;
	check_shadow(scene, dir, id);
	if (scene->shadow == 1)
		light_color = calculate_color(light->color, 0);
	else
	{
		dir = substract_vectors(light->point, scene->pixel.point);
		dir = normalize_vector(dir);
		light_amount = dot_vectors(dir, scene->pixel.orient);
		light_amount = light_amount * light->brightness;
		light_color = calculate_color(light->color, light_amount);
	}
	return (light_color);
}

t_color	calculate_view(t_scene *scene, t_color color)
{
	float		dot_view;
	t_vector	ray;

	ray = substract_vectors(scene->origin_ray, scene->pixel.point);
	ray = normalize_vector(ray);
	dot_view = dot_vectors(scene->pixel.orient, ray);
	color = calculate_color(color, dot_view);
	return (color);
}

t_color	walk_list_light(t_list *list_lights, t_scene *scene,
	t_color light_color, int id)
{
	t_color		light_color_tmp;
	int			i;

	i = 1;
	while (list_lights)
	{
		if (i > 1)
		{
			light_color_tmp = calculate_light(scene, list_lights->content, id);
			light_color = add_colors(light_color, light_color_tmp);
		}
		else
			light_color = calculate_light(scene, list_lights->content, id);
		list_lights = list_lights->next;
		i++;
	}
	return (light_color);
}

t_color	add_lights(t_scene *scene, t_color color, int id)
{
	t_list		*list_tmp;
	t_color		light_color;
	int			i;

	i = 1;
	list_tmp = scene->list_lights;
	light_color = fill_color(0);
	scene->shadow = 0;
	if (scene->list_lights && id != 0)
		light_color = walk_list_light(list_tmp, scene, light_color, id);
	light_color = add_colors(light_color, scene->ambient.color);
	color = calculate_view(scene, color);
	color = multiply_colors(color, light_color);
	return (color);
}
