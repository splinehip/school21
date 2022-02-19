/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scene_handler.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cflorind <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/08 15:24:02 by cflorind          #+#    #+#             */
/*   Updated: 2022/02/18 11:49:07 by cflorind         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCENE_HANDLER_H
# define SCENE_HANDLER_H
# include "args.h"
# define MIN_DIST		0.0001f
# define MAX_DIST		100000000.0f
# define COLOR_BLACK	0x002B2B2A

typedef struct s_rgb
{
	int	r;
	int	g;
	int	b;
}	t_rgb;

typedef struct s_qec
{
	float	a;
	float	b;
	float	c;
	float	discr;
	float	root_1;
	float	root_2;
	float	m_1;
	float	m_2;
}	t_qec;

typedef struct s_org
{
	float	m;
	float	dist;
	float	dot_r_nv;
	short	res[2];
	t_vec	pl_1;
	t_vec	pl_2;
	t_vec	hit[2];
	t_qec	caps;
	t_vec	vres;
	t_vec	cam_cy;
	t_qec	qec;
}	t_org;

typedef struct s_pxl
{
	int		rgb[3];
	int		color;
	float	dist;
	char	*type;
	t_rgb	trgb;
	t_vec	vh_norma;
	t_vec	vh_point;
}	t_pxl;

void	draw_scene(t_arg *args);
void	culc_color(t_arg *args, t_vec *ray, int *color);
void	check_pxl_intersects(t_arg *args, t_vec *ray, t_pxl *pxl);
int		rgb_hex(int t, t_rgb rgb);
t_rgb	calc_rgb_light(t_rgb trgb, double ratio);
t_rgb	multiply_rgbs(t_rgb a, t_rgb b);
t_rgb	add_rgb_light(t_rgb a, t_rgb b);
void	set_pxl_color(t_arg *args, t_vec *ray, t_pxl *pxl);
t_vec	get_hit_direction(void *obj, char *obj_type, t_vec ray);
void	sphere_intersects(t_arg *args, t_sphere *sp, t_vec *ray, t_pxl *pxl);
void	plane_intersects(t_arg *args, t_plane *pl, t_vec *ray, t_pxl *pxl);
void	cylinder_intersects(
			t_arg *args, t_cylinder *cy, t_vec *ray, t_pxl *pxl);
int		get_caps(t_cylinder *cy, t_vec *ray, t_org *org);
int		in_range(float num, float range);
void	init_vect(t_vec *v, float x, float y, float z);
t_vec	vect_add(t_vec v1, t_vec v2);
t_vec	vect_substract(t_vec v1, t_vec v2);
float	vect_len(t_vec vect);
void	normalise_vect(t_vec *vect);
float	vect_dot_product(t_vec v1, t_vec v2);
t_vec	vect_mult(t_vec vect, float n);
t_vec	vect_div(t_vec vect, float n);
t_vec	reflect_vect(t_vec ray, t_vec norm);
float	vector_scalar(t_vec v1, t_vec v2);
float	point_dist(t_vec v1, t_vec v2);
float	vect_dist(t_vec v1, t_vec v2);
void	rotate_x(t_arg *args, double alfa);
void	rotate_y(t_arg *args, double alfa);
void	rotate_z(t_arg *args, double alfa);
void	skeep_cam_to_def(t_arg *args);

#endif
