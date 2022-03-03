/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   initialize_utils.c                                 :+:    :+:            */
/*                                                     +:+                    */
/*   By: aheister <aheister@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/05/13 12:30:50 by aheister      #+#    #+#                 */
/*   Updated: 2021/06/25 16:13:24 by aheister      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

/*
** SPLIT_AMOUNT - counts the amount of substrings
** SPLIT_VECTOR - splits object string and fills values of struct vector
** SPLIT_COLOR	- splits object string and fills values of struct color
** FILL_MATRIX - fills the exceptions in the cam matrix
** CAM_MATRIX - set-up of the cam-to-world matrix

*/

#include "minirt.h"

int	split_amount(char **split)
{
	int	i;

	i = 0;
	while (split[i])
		i++;
	return (i);
}

t_vector	split_vector(char *string, t_scene *scene, int type)
{
	char		**split;
	int			amount;
	t_vector	vec;

	split = ft_split(string, ',');
	amount = split_amount(split);
	if (amount != 3 || split_check(split) == 0
		|| c_check(string, ',') != 2)
		error_handling("Wrong vector format.", split, scene);
	if (c_check(split[0], '.') > 1 || c_check(split[1], '.') > 1
		|| c_check(split[2], '.') > 1)
		error_handling("Wrong vector format.", split, scene);
	vec.x = ft_atof(split[0]);
	vec.y = ft_atof(split[1]);
	vec.z = ft_atof(split[2]);
	if (type == 1)
	{
		if ((!vec.x && !vec.y && !vec.z) || vec.x < -1 || vec.y < -1
			|| vec.z < -1 || vec.x > 1 || vec.y > 1 || vec.z > 1)
			error_handling("Wrong vector orientation format.", split, scene);
	}
	free_split(split);
	return (vec);
}

t_color	split_color(char *string, t_scene *scene)
{
	char		**split;
	int			amount;
	t_color		col;

	split = ft_split(string, ',');
	amount = split_amount(split);
	if (amount != 3 || split_check(split) == 0
		|| c_check(string, ',') != 2 || c_check(string, '.') != 0)
		error_handling("Wrong color format.", split, scene);
	col.r = ft_atof(split[0]);
	col.g = ft_atof(split[1]);
	col.b = ft_atof(split[2]);
	if (col.r < 0 || col.g < 0 || col.b < 0 || col.r > 255
		|| col.g > 255 || col.b > 255)
		error_handling("Wrong color format.", split, scene);
	free_split(split);
	return (col);
}

void	fill_matrix(t_scene *scene, int dir, t_vector value)
{
	if (scene->camera.point.x == 0 && scene->camera.point.y != 0
		&& scene->camera.point.z == 0)
	{
		if (dir == 0)
		{
			if (scene->camera.point.y > 0)
				scene->ctw.matrix[0][0] = 1;
			else if (scene->camera.point.y < 0)
				scene->ctw.matrix[0][0] = -1;
		}
		if (dir == 1)
		{
			if (scene->camera.point.y > 0)
				scene->ctw.matrix[1][2] = -1;
			else if (scene->camera.point.y < 0)
				scene->ctw.matrix[1][2] = 1;
		}
	}	
	else
	{
		if (dir == 0)
			scene->ctw.matrix[0][0] = value.x;
		if (dir == 1)
			scene->ctw.matrix[1][2] = value.z;
	}
}

void	cam_matrix(t_scene *scene)
{
	t_vector	x;
	t_vector	y;
	t_vector	z;
	t_vector	tmp;

	z = substract_vectors(scene->camera.point, scene->camera.orient);
	z = normalize_vector(z);
	tmp = fill_vector(0, 1, 0);
	x = product_vectors(tmp, z);
	y = product_vectors(z, x);
	fill_matrix(scene, 0, x);
	scene->ctw.matrix[0][1] = x.y;
	scene->ctw.matrix[0][2] = x.z;
	scene->ctw.matrix[1][0] = y.x;
	scene->ctw.matrix[1][1] = y.y;
	fill_matrix(scene, 1, y);
	scene->ctw.matrix[2][0] = z.x;
	scene->ctw.matrix[2][1] = z.y;
	scene->ctw.matrix[2][2] = z.z;
	scene->ctw.matrix[3][0] = scene->camera.point.x;
	scene->ctw.matrix[3][1] = scene->camera.point.y;
	scene->ctw.matrix[3][2] = scene->camera.point.z;
}
