/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   image.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: aheister <aheister@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/05/15 13:16:19 by aheister      #+#    #+#                 */
/*   Updated: 2021/06/25 16:13:11 by aheister      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

/*
** INIT_PIXEL - Resets values of 'this' pixel to 0
** MY_MLX_PIXEL_PUT - puts the pixel with the right color on the image
** CALCULATE_PIXEL - function to go through list of objects to find closest pix
** CREATE_IMAGE - draws the image by sending rays through all the pixels
*/

#include "minirt.h"

void	init_pixel(t_scene *scene)
{
	scene->pixel.first = 0;
	scene->pixel.t = 0;
	scene->pixel.point = fill_vector(0, 0, 0);
	scene->pixel.orient = fill_vector(0, 0, 0);
	fill_color(0);
}

void	my_mlx_pixel_put(t_img *img, int x, int y, unsigned int colour)
{
	char	*dst;
	int		offset;

	offset = y * img->line_size + x * (img->bits_per_pixel / 8);
	dst = img->address + offset;
	*(unsigned int *)dst = colour;
}

void	calculate_pixel(t_scene *scene, t_img img, int x, int y)
{
	int			hexa_color;
	t_list		*list_tmp;
	t_vector	ray;

	init_pixel(scene);
	list_tmp = scene->list_objects;
	ray = calculate_ray(scene, x, y);
	while (list_tmp)
	{
		intersect_objects(scene, ray, list_tmp, 0);
		list_tmp = list_tmp->next;
	}
	if (scene->pixel.first == 1)
	{
		hexa_color = create_hexa(100, scene->pixel.color.r,
				scene->pixel.color.g, scene->pixel.color.b);
		my_mlx_pixel_put(&img, x, y, hexa_color);
	}
}

void	create_image(t_img img, t_scene *scene)
{
	int			x;
	int			y;

	y = 0;
	while (y < scene->resolution.height)
	{	
		x = 0;
		while (x < scene->resolution.width)
		{	
			calculate_pixel(scene, img, x, y);
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(scene->vars.location, scene->vars.window,
		img.img_ptr, 0, 0);
}
