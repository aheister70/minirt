/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   calculate_point.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: aheister <aheister@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/04/22 15:46:39 by aheister      #+#    #+#                 */
/*   Updated: 2021/06/25 16:12:26 by aheister      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

/*
** CALCULATE_PX - calculates x coordinate of point on the image plane
** CALCULATE_PY - calculates y coordinate of point on the image plane
** CALCULATE_RAY - transforms a pixel position to a point on the image plane
*/

#include "minirt.h"

float	calculate_px(float x, t_scene *scene)
{
	float	img_ratio;

	x = (x + 0.5) / scene->resolution.width;
	img_ratio = (float)scene->resolution.width
		/ (float)scene->resolution.height;
	x = (2 * x - 1) * img_ratio;
	x = x * tan((scene->camera.fov * (M_PI / 180)) / 2);
	return (x);
}

float	calculate_py(float y, t_scene *scene)
{
	y = (y + 0.5) / scene->resolution.height;
	y = 1 - 2 * y;
	y = y * tan((scene->camera.fov * (M_PI / 180)) / 2);
	return (y);
}

t_vector	calculate_ray(t_scene *scene, int x, int y)
{	
	t_vector	vector;
	t_vector	ray;

	vector.x = calculate_px(x, scene);
	vector.y = calculate_py(y, scene);
	vector.z = -1;
	vector = multiply_by_matrix(vector, scene);
	scene->origin_ray = vector;
	ray = substract_vectors(vector, scene->origin_cam);
	ray = normalize_vector(ray);
	return (ray);
}
