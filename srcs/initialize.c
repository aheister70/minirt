/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   initialize.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: aheister <aheister@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/04/22 12:41:39 by aheister      #+#    #+#                 */
/*   Updated: 2021/06/26 11:18:59 by aheister      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

/*
** INIT_SCENE - Receives lines from read and assigns them to object functions
** INIT_AMBIENT - Assigns values from RT file to struct s_ambient
** INIT_LIGHT - Assigns value from RT file to struct s_light
** INIT_CAMERA - Assigns values from RT file to struct s_camera (option: multi)
** INIT_FLAGS - Preset of ambient and resolution flags to 0 (if input is valid)
*/

#include "minirt.h"

void	init_scene(char	*line, t_scene *scene)
{
	char	**object;

	object = ft_split(line, ' ');
	if (object[0] != NULL)
	{
		if (ft_strncmp(object[0], "A\0", 2) == 0)
			init_ambient(object, scene);
		else if (ft_strncmp(object[0], "L\0", 2) == 0)
			init_light(object, scene);
		else if (ft_strncmp(object[0], "C\0", 2) == 0)
			init_camera(object, scene);
		else if (ft_strncmp(object[0], "sp\0", 3) == 0)
			init_sphere(object, scene);
		else if (ft_strncmp(object[0], "pl\0", 3) == 0)
			init_plane(object, scene);
		else if (ft_strncmp(object[0], "cy\0", 3) == 0)
			init_cylinder(object, scene);
		else
			error_handling("Non valid object type in scene.", object, scene);
	}
	else
		free_split(object);
}

void	init_ambient(char **object, t_scene *scene)
{
	char	**color;
	float	brightness;

	if (scene->flags.A == 1)
		error_handling("Too many ambient lights in the scene", object, scene);
	else
	{
		if (c_check(object[1], '.') > 1 || str_check(object[1]) == 0)
			error_handling("Value of ambient brightness is invalid",
				object, scene);
		brightness = ft_atof(object[1]);
		if (brightness < 0.0 || brightness > 1.0)
			error_handling("Value of ambient brightness is invalid",
				object, scene);
		color = ft_split(object[2], ',');
		scene->ambient.color.r = ft_atoi(color[0]);
		scene->ambient.color.g = ft_atoi(color[1]);
		scene->ambient.color.b = ft_atoi(color[2]);
		scene->ambient.color = calculate_color(scene->ambient.color,
				brightness);
		free_split(color);
		scene->flags.A = 1;
		free_split(object);
	}
}

void	init_light(char **object, t_scene *scene)
{
	t_light	*light;

	if (scene->flags.L == 1)
		error_handling("Too many lights in the scene", object, scene);
	else
	{
		if (split_amount(object) != 4)
			error_handling("Parsing error: Wrong light format.", object, scene);
		light = ft_calloc(1, sizeof(t_light));
		if (!light)
			error_handling("Fail to malloc light.", object, scene);
		light->point = split_vector(object[1], scene, 0);
		if (c_check(object[2], '.') > 1 || str_check(object[2]) == 0)
			error_handling("Value of light brightness is invalid",
				object, scene);
		light->brightness = ft_atof(object[2]);
		if (light->brightness < 0.0 || light->brightness > 1.0)
			error_handling("Value of light brightness is invalid",
				object, scene);
		light->color = split_color(object[3], scene);
		ft_lstadd_back(&scene->list_lights, ft_lstnew(0, light));
		scene->flags.L = 1;
		free_split(object);
	}
}

void	init_camera(char **object, t_scene *scene)
{
	char	**array;

	if (scene->flags.C == 1)
		error_handling("Too many camera's in the scene", object, scene);
	else
	{
		array = ft_split(object[1], ',');
		scene->camera.point.x = ft_atof(array[0]);
		scene->camera.point.y = ft_atof(array[1]);
		scene->camera.point.z = ft_atof(array[2]);
		free_split(array);
		array = ft_split(object[2], ',');
		scene->camera.orient.x = ft_atof(array[0]);
		scene->camera.orient.y = ft_atof(array[1]);
		scene->camera.orient.z = ft_atof(array[2]);
		free_split(array);
		if (c_check(object[3], '.') > 1 || str_check(object[3]) == 0
			|| ft_atoi(object[3]) < 0 || ft_atoi(object[3]) > 180)
			error_handling("Value of camera fov is invalid", object, scene);
		scene->camera.fov = ft_atoi(object[3]);
		scene->flags.C = 1;
		cam_matrix(scene);
		scene->origin_cam = multiply_by_matrix(scene->origin_cam, scene);
		free_split(object);
	}
}

void	init_flags(t_scene *scene)
{
	scene->flags.A = 0;
	scene->flags.C = 0;
	scene->flags.L = 0;
	scene->ray = fill_vector(0, 0, 0);
	scene->origin_cam = fill_vector(0, 0, 0);
	scene->ambient.color = fill_color(0);
	scene->pixel.first = 0;
	scene->shadow = 0;
	scene->length = 0;
	scene->amount_objects = 0;
}
