/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   plane.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: aheister <aheister@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/05/08 13:02:56 by aheister      #+#    #+#                 */
/*   Updated: 2021/06/25 16:13:51 by aheister      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

/*
** INIT_PLANE - Assigns values from RT file to struct s_plane to list (ob: 2)
** INTERSECT_PLANE - calculates if a given ray intersecs a given plane
*/

#include "minirt.h"

void	init_plane(char **object, t_scene *scene)
{	
	t_plane	*plane;

	if (split_amount(object) != 4)
		error_handling("Scene contains wrong plane format.", object, scene);
	plane = ft_calloc(1, sizeof(t_plane));
	if (!plane)
		error_handling("Fail to malloc plane.", object, scene);
	plane->point = split_vector(object[1], scene, 0);
	plane->orient = split_vector(object[2], scene, 1);
	plane->color = split_color(object[3], scene);
	scene->amount_objects++;
	plane->id = scene->amount_objects;
	plane->type = 2;
	ft_lstadd_back(&scene->list_objects, ft_lstnew(2, plane));
	free_split(object);
}

void	intersect_plane(t_vector ray, void *p_plane, t_scene *scene, int id)
{
	float		t;
	t_plane		*pl;

	t = 0;
	pl = p_plane;
	if (id == 0 && dot_vectors(pl->orient, ray) >= 0)
		return ;
	else if (id != 0 && pl->id != id)
	{
		if (dot_vectors(vector_constant(pl->orient, -1), ray) >= 0)
			return ;
		else if (dot_vectors(vector_constant(pl->orient, -1), ray) < 0)
			scene->shadow = 1;
	}
	t = calculate_t(scene, pl->orient, pl->point);
	if (id == 0 && (scene->pixel.first == 0 || t <= scene->pixel.t))
	{
		scene->pixel.first = 1;
		scene->pixel.t = t;
		scene->pixel.orient = pl->orient;
		scene->pixel.point = calculate_i(scene, t);
		scene->pixel.color = add_lights(scene, pl->color, pl->id);
	}
}
