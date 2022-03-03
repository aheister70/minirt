/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   minirt.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: aheister <aheister@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/04/08 13:36:44 by aheister      #+#    #+#                 */
/*   Updated: 2021/06/27 16:29:51 by aheister      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

/*
** OPEN_WINDOW - Opens mlx window and starts the image creation
** CHECK_EXTENSION - Checks if the extention of read file = rt
** READ_MAP - Reads the rt file and parses the values to initialize
** MAIN - start of minirt
*/

#include "minirt.h"
#include <unistd.h>

void	open_window(t_scene *scene)
{
	t_img	img01;
	int		closed;

	closed = 1;
	scene->vars.location = mlx_init();
	if (!scene->vars.location)
		error_handling("Fail to initialize Minilibx", 0, scene);
	scene->vars.window = mlx_new_window(scene->vars.location,
			scene->resolution.width, scene->resolution.height, "miniRT");
	if (!scene->vars.window)
		error_handling("Fail to create Minilibx window.", 0, scene);
	img01.img_ptr = mlx_new_image(scene->vars.location, scene->resolution.width,
			scene->resolution.height);
	img01.address = mlx_get_data_addr(img01.img_ptr, &img01.bits_per_pixel,
			&img01.line_size, &img01.endian);
	create_image(img01, scene);
	mlx_hook(scene->vars.window, 17, 0, close_window_cross, scene);
	mlx_hook(scene->vars.window, 2, 1L << 0, close_window_key, scene);
	mlx_loop(scene->vars.location);
}

int	check_extension(char *rt)
{
	int		length;
	char	type[4];
	int		i;

	i = 3;
	length = ft_strlen(rt);
	type[3] = '\0';
	while (i > 0)
	{
		i--;
		type[i] = rt[length - 3 + i];
	}
	if (ft_strncmp(type, ".rt", 3) == 0)
		return (0);
	else
		return (1);
}

void	read_map(char **argv, t_scene *scene)
{
	int		fd;
	int		res;
	char	*line;
	char	*rt;

	rt = argv[1];
	if (check_extension(rt) == 1)
		error_handling("Scene file has wrong extension.", 0, scene);
	fd = open(rt, O_RDONLY);
	if (fd < 0)
		error_handling("Fail to open scene file.", 0, scene);
	res = 1;
	init_flags(scene);
	while (res > 0)
	{
		res = get_next_line(fd, &line);
		init_scene(line, scene);
		free(line);
		if (res == 0 || res == -1)
			break ;
	}
	close(fd);
}

int	main(int argc, char **argv)
{
	t_scene		scene;

	if (argc < 2 || argc > 2)
		error_handling("Wrong arguments as input.", 0, &scene);
	scene.resolution.width = 800;
	scene.resolution.height = 600;
	if (scene.resolution.width < 1 || scene.resolution.height < 1)
		error_handling("Invalid resolution.", 0, &scene);
	read_map(argv, &scene);
	if (scene.flags.A == 0)
		error_handling("Ambient light is missing in the scene.", 0, &scene);
	if (scene.flags.C == 0)
		error_handling("Camera is missing in the scene.", 0, &scene);
	open_window(&scene);
	return (0);
}
