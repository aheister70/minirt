/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   minirt.h                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: aheister <aheister@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/04/08 12:01:05 by aheister      #+#    #+#                 */
/*   Updated: 2021/06/26 11:29:24 by aheister      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIRT_H
# define MINIRT_H

# include <stdlib.h>
# include <stdio.h>
# include <math.h>
# include <fcntl.h>
# include <errno.h>
# include <string.h>
# include "../lib/mlx/mlx.h"
# include "../lib/libft/libft.h"
# include "get_next_line.h"

typedef struct s_img
{
	void				*img_ptr;
	char				*address;
	int					bits_per_pixel;
	int					line_size;
	int					endian;
}						t_img;

typedef struct s_vars
{
	void				*location;
	void				*window;
}						t_vars;

typedef struct s_resolution
{
	int					width;
	int					height;
}						t_resolution;

typedef struct s_color
{
	int					r;
	int					g;
	int					b;
}						t_color;

typedef struct s_vector
{
	float				x;
	float				y;
	float				z;
}						t_vector;

typedef struct s_matrix
{
	float	matrix[4][4];
}				t_matrix;

typedef struct s_pixel
{
	int					first;
	float				t;
	t_vector			point;
	t_vector			orient;
	t_color				color;
}						t_pixel;

typedef struct s_ambient
{
	t_color				color;
}						t_ambient;

typedef struct s_camera
{
	t_vector			point;
	t_vector			orient;
	int					fov;
}						t_camera;

typedef struct s_light
{
	t_vector			point;
	t_color				color;
	float				brightness;
}						t_light;

typedef struct s_sphere
{
	int					id;
	int					type;
	t_vector			point;
	t_color				color;
	float				diameter;
}						t_sphere;

typedef struct s_plane
{
	int					id;
	int					type;
	t_vector			point;
	t_vector			orient;
	t_color				color;
}						t_plane;

typedef struct s_cylinder
{
	int					id;
	int					type;
	t_vector			point;
	t_vector			orient;
	t_color				color;
	float				diameter;
	float				height;
}						t_cylinder;

typedef struct s_triangle
{
	int					id;
	int					type;
	t_vector			point_a;
	t_vector			point_b;
	t_vector			point_c;
	t_vector			orient;
	t_color				color;
}						t_triangle;

typedef struct s_flags
{
	int					A;
	int					C;
	int					L;
}						t_flags;

typedef struct s_scene
{
	int					shadow;
	float				length;
	t_vector			origin_cam;
	t_vector			origin_ray;
	t_vector			ray;
	t_vector			abc;
	int					amount_objects;
	t_vars				vars;
	t_vector			light_point;
	t_pixel				pixel;
	t_flags				flags;
	t_resolution		resolution;
	t_ambient			ambient;
	t_camera			camera;
	t_matrix			ctw;
	t_list				*list_lights;
	t_list				*list_objects;
}						t_scene;

/*
** GENERAL FUNCTIONS - ft_atof.c
*/
float		ft_atof(const char *str);

/*
** EXIT AND FREE - errors.c
*/
int			close_window_key(int keycode, t_scene *scene);
int			close_window_cross(t_scene *scene);
void		error_handling(char *message, char **object, t_scene *scene);
void		free_list(t_scene *scene);
void		free_split(char **object);

/*
** GENERAL FUNCTIONS - minirt.c
*/
int			check_extension(char *rt);
int			main(int argc, char **argv);
void		open_window(t_scene *scene);
void		read_map(char **argv, t_scene *scene);

/*
** IMAGE - image.c
*/
void		create_image(t_img img, t_scene *scene);
void		calculate_pixel(t_scene *scene, t_img img, int x, int y);
void		my_mlx_pixel_put(t_img *img, int x, int y, unsigned int colour);
void		init_pixel(t_scene *scene);

/*
** IMAGE UTILS - image_utils.c
*/
t_color		add_colors(t_color color_a, t_color color_b);
t_color		multiply_colors(t_color color_a, t_color color_b);
int			create_hexa(int t, int r, int g, int b);
t_color		calculate_color(t_color color, float value);
t_color		fill_color(float value);

/*
** INITIALIZE - initialize.c
*/
void		init_ambient(char **object, t_scene *scene);
void		init_camera(char **object, t_scene *scene);
void		init_flags(t_scene *scene);
void		init_light(char **object, t_scene *scene);
void		init_scene(char	*line, t_scene *scene);

/*
** INITIALIZE CHECKS - initialize_checks.c
*/
int			c_check(char *string, char c);
int			split_check(char **split);
int			str_check(char *str);

/*
** INITIALIZE UTILS - initialize_utils.c
*/
void		cam_matrix(t_scene *scene);
int			split_amount(char **split);
t_color		split_color(char *string, t_scene *scene);
t_vector	split_vector(char *string, t_scene *scene, int type);

/*
** RAY TRACING - calculate_point.c
*/
float		calculate_px(float x, t_scene *scene);
float		calculate_py(float y, t_scene *scene);
t_vector	calculate_ray(t_scene *scene, int x, int y);

/*
** RAY TRACING - intersect.c
*/
void		intersect_objects(t_scene *scene, t_vector ray,
				t_list *list_objects, int id);
t_vector	calculate_i(t_scene *scene, float t);
t_vector	calculate_i_shadow(t_scene *scene, float t);

float		calculate_t(t_scene *scene, t_vector orient,
				t_vector point);

float		calculate_t_shadow(t_scene *scene, t_vector orient,
				t_vector point);

/*
** LIGHT - light.c + light_bonus.c (just walk_list_light)
*/
t_color		add_lights(t_scene *scene, t_color color, int id);
t_color		calculate_light(t_scene *scene, void *p_light, int type);
t_color		calculate_view(t_scene *scene, t_color color);
void		check_shadow(t_scene *scene, t_vector ray, int id);

t_color		walk_list_light(t_list *list_lights, t_scene *scene,
				t_color light_color, int id);

/*
** OBJECTS - cylinder.c and cylinder2.c
*/
float		calculate_closest_cy(t_cylinder *cy, float *t_tmp, t_scene *scene,
				int id);

float		calculate_discriminant(t_vector ray, t_cylinder *cy,
				t_scene *scene, int id);

float		calculate_length(t_cylinder *cy, float t_tmp, t_scene *scene,
				int id);

t_vector	calculate_orient_cy(t_vector ray, t_cylinder *cy, t_scene *scene);

void		fill_pixel_cylinder(t_cylinder *cy, t_scene *scene, t_vector ray,
				int type);

void		init_cylinder(char **object, t_scene *scene);

float		intersect_caps(t_cylinder *cy, t_vector ray, t_scene *scene,
				int type);

void		intersect_cylinder(t_vector ray, void *c_cyl, t_scene *scene,
				int id);

float		intersect_side(t_vector ray, t_cylinder *cy, t_scene *scene,
				int id);

/*
** OBJECTS - plane.c
*/
void		init_plane(char **object, t_scene *scene);

void		intersect_plane(t_vector ray, void *p_plane, t_scene *scene,
				int id);

/*
** OBJECTS - sphere.c
*/
float		calculate_closest(t_sphere *sp, t_vector ray, t_vector length);
void		fill_pixel_sphere(t_sphere *sp, t_scene *scene, int in);
void		init_sphere(char **object, t_scene *scene);

void		intersect_sphere(t_vector ray, void *p_shere, t_scene *scene,
				int id);

/*
** OBJECTS - triangle.c
*/
t_vector	calculate_orient(t_triangle tr);
int			check_inside(t_triangle tr, t_vector point);
void		fill_pixel_triangle(t_triangle *tr, t_scene *scene, float t);
void		init_triangle(char **object, t_scene *scene);

void		intersect_triangle(t_vector ray, void *p_triangle, t_scene *scene,
				int id);

/*
** VECTORS - vectors_ops.c
*/
t_vector	add_vectors(t_vector a, t_vector b);
t_vector	fill_vector(float x, float y, float z);
t_vector	substract_vectors(t_vector a, t_vector b);
t_vector	vector_constant(t_vector vector, float constant);

/*
** VECTORS - vectors_ops2.c
*/
float		vector_matrix(t_vector vector, float constant);
float		dot_vectors(t_vector orient, t_vector point);
t_vector	product_vectors(t_vector a, t_vector b);
t_vector	normalize_vector(t_vector vector);
t_vector	multiply_by_matrix(t_vector p, t_scene *scene);

#endif