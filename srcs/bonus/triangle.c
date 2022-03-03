/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   triangle.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: aheister <aheister@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/05/14 13:20:35 by aheister      #+#    #+#                 */
/*   Updated: 2021/06/25 16:12:14 by aheister      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

/*
** INIT_TRIANGLE - Assigns values from RT file to struct s_triangle (id: 4)
** CHECK_INSIDE - Checks if the intersection point lays within the triangle
** CALCULATE_ORIENT - Calculates the n (orientation) vector
** FILL_PIXEL_TRIANGLE - Fills the pixel values when triangle is the closest
** INTERSECT_TRIANGLE - calculates if a given ray intersecs a given triangle
*/

#include "minirt.h"

void	init_triangle(char **object, t_scene *scene)
{	
	t_triangle	*triangle;

	if (split_amount(object) != 5)
		error_handling("Scene contains wrong triangle format.", object, scene);
	triangle = ft_calloc(1, sizeof(t_triangle));
	if (!triangle)
		error_handling("Fail to malloc triangle", object, scene);
	triangle->point_a = split_vector(object[1], scene, 0);
	triangle->point_b = split_vector(object[2], scene, 0);
	triangle->point_c = split_vector(object[3], scene, 0);
	triangle->color = split_color(object[4], scene);
	scene->amount_objects++;
	triangle->id = scene->amount_objects;
	triangle->type = 4;
	ft_lstadd_back(&scene->list_objects, ft_lstnew(4, triangle));
	free_split(object);
}

int	check_inside(t_triangle tr, t_vector point)
{
	t_vector	c;
	t_vector	side;
	t_vector	vector_p;

	side = substract_vectors(tr.point_b, tr.point_a);
	vector_p = substract_vectors(point, tr.point_a);
	c = product_vectors(side, vector_p);
	if (dot_vectors(tr.orient, c) > 0)
		return (0);
	side = substract_vectors(tr.point_c, tr.point_b);
	vector_p = substract_vectors(point, tr.point_b);
	c = product_vectors(side, vector_p);
	if (dot_vectors(tr.orient, c) > 0)
		return (0);
	side = substract_vectors(tr.point_a, tr.point_c);
	vector_p = substract_vectors(point, tr.point_c);
	c = product_vectors(side, vector_p);
	if (dot_vectors(tr.orient, c) > 0)
		return (0);
	return (1);
}

t_vector	calculate_orient(t_triangle tr)
{
	t_vector	side_a;
	t_vector	side_b;

	side_a = substract_vectors(tr.point_a, tr.point_b);
	side_b = substract_vectors(tr.point_c, tr.point_a);
	tr.orient = product_vectors(side_a, side_b);
	tr.orient = normalize_vector(tr.orient);
	return (tr.orient);
}

void	fill_pixel_triangle(t_triangle *tr, t_scene *scene, float t)
{
	scene->pixel.first = 1;
	scene->pixel.t = t;
	scene->pixel.orient = tr->orient;
	scene->pixel.point = calculate_i(scene, t);
	scene->pixel.color = add_lights(scene, tr->color, tr->id);
}

void	intersect_triangle(t_vector ray, void *p_triangle, t_scene *scene
		, int id)
{
	float		t;
	t_triangle	*tr;
	t_vector	point;

	t = 0;
	tr = p_triangle;
	tr->orient = calculate_orient(*tr);
	if (id == 0 && dot_vectors(tr->orient, ray) < 0)
	{
		t = calculate_t(scene, tr->orient, tr->point_c);
		point = calculate_i(scene, t);
		if (check_inside(*tr, point) == 1 && (scene->pixel.first == 0
				|| t < scene->pixel.t))
			fill_pixel_triangle(tr, scene, t);
	}
	else if (id != 0 && tr->id != id && dot_vectors(tr->orient, ray) < 0)
	{
		t = calculate_t_shadow(scene, vector_constant(tr->orient, -1),
				tr->point_c);
		point = calculate_i_shadow(scene, t);
		t = scene->length - t;
		if (check_inside(*tr, point) == 1 && t > 0 && t < scene->length)
			scene->shadow = 1;
	}
}
