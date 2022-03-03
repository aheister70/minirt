/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   errors.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: aheister <aheister@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/05/08 16:07:37 by aheister      #+#    #+#                 */
/*   Updated: 2021/06/26 13:50:32 by aheister      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

/*
** ERROR_HANDLING - Prints error message, sends objects & lists to free funct
** CLOSE_WINDOW_CROSS - Frees and exits after clicking on cross window
** CLOSE_WINDOW_KEY - Frees and exits after pressing esc key
** FREE_LIST - Frees lists of objects and lights
** FREE_SPLIT - Frees the arrays that are created by ft_split
*/

#include "minirt.h"

void	error_handling(char *message, char **object, t_scene *scene)
{
	printf("Error\n%s", message);
	if (object)
		free_split(object);
	free_list(scene);
	exit (0);
}

int	close_window_cross(t_scene *scene)
{
	free_list(scene);
	mlx_clear_window(scene->vars.location, scene->vars.window);
	mlx_destroy_window(scene->vars.location, scene->vars.window);
	exit (0);
}

int	close_window_key(int keycode, t_scene *scene)
{
	if (keycode == 53)
	{
		free_list(scene);
		mlx_clear_window(scene->vars.location, scene->vars.window);
		mlx_destroy_window(scene->vars.location, scene->vars.window);
		exit (0);
	}
	return (0);
}

void	free_split(char **object)
{
	int	amount;

	amount = split_amount(object);
	while (amount >= 0)
	{
		if (object[amount])
			free(object[amount]);
		amount--;
	}
	free(object);
}

void	free_list(t_scene *scene)
{
	ft_lstclear(&scene->list_objects, free);
	ft_lstclear(&scene->list_lights, free);
}
