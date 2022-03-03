/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   image_utils.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: aheister <aheister@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/05/18 20:10:30 by aheister      #+#    #+#                 */
/*   Updated: 2021/06/25 16:13:05 by aheister      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

/*
** CREATE_HEXA - Tranforms an rgb color into a hexadecimal
** FILL_COLOR - Fills the struct color with values
** CALCULATE_COLOR - calculates the rgb values with a value (like brightness)
** ADD_COLORS - adds color b to color a with a clamp of 255
** MULTIPLY_COLORS - multiplies 2 colors and devides them through 255
*/

#include "minirt.h"

int	create_hexa(int t, int r, int g, int b)
{
	return (t << 24 | r << 16 | g << 8 | b);
}

t_color	calculate_color(t_color color, float value)
{
	color.r = color.r * value;
	if (color.r < 0 )
		color.r = 0;
	color.g = color.g * value;
	if (color.g < 0)
		color.g = 0;
	color.b = color.b * value;
	if (color.b < 0)
		color.b = 0;
	return (color);
}

t_color	fill_color(float value)
{
	t_color	color;

	color.r = value;
	color.g = value;
	color.b = value;
	return (color);
}

t_color	add_colors(t_color color_a, t_color color_b)
{
	color_a.r = color_a.r + color_b.r;
	if (color_a.r > 255)
		color_a.r = 255;
	color_a.g = color_a.g + color_b.g;
	if (color_a.g > 255)
		color_a.g = 255;
	color_a.b = color_a.b + color_b.b;
	if (color_a.b > 255)
		color_a.b = 255;
	return (color_a);
}

t_color	multiply_colors(t_color color_a, t_color color_b)
{
	t_color	new_color;

	new_color.r = (color_a.r * color_b.r) / 255;
	new_color.g = (color_a.g * color_b.g) / 255;
	new_color.b = (color_a.b * color_b.b) / 255;
	return (new_color);
}
