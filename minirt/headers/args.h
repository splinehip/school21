/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   args.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cflorind <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/26 16:31:26 by cflorind          #+#    #+#             */
/*   Updated: 2022/02/16 17:33:35 by cflorind         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARGS_H
# define ARGS_H
# define AMBIENT	"A"
# define LIGHT		"L"
# define CAMERA		"C"
# define SPHERE		"sp"
# define PLANE		"pl"
# define CYLINDER	"cy"
# define ALR_MIN	0.0f
# define ALR_MAX	1.0f
# define RGB_MIN	0
# define RGB_MAX	255
# define NORMA_MIN	-1.0f
# define NORMA_MAX	1.0f
# define FOV_MIN	0
# define FOV_MAX	180
# define LBR_MIN	0.0f
# define LBR_MAX	1.0f

enum e_rgb_idx
{
	r,
	g,
	b,
};

enum e_axis_idx
{
	x,
	y,
	z,
};

typedef struct s_vec
{
	float	x;
	float	y;
	float	z;
}	t_vec;

typedef struct s_ambient
{
	int		seted;
	float	alr;
	int		color[3];
}	t_ambient;

typedef struct s_camera
{
	int		seted;
	int		fov;
	float	point[3];
	float	norma[3];
	t_vec	vpoint;
	t_vec	vnorma;
}	t_camera;

typedef struct s_light
{
	int		seted;
	float	point[3];
	float	lbr;
	int		color[3];
	t_vec	vpoint;
}	t_light;

typedef struct s_sphere
{
	float	center[3];
	float	d;
	int		color[3];
	int		inside;
	t_vec	vcenter;
	t_vec	vh_point;
	t_vec	vh_norma;
}	t_sphere;

typedef struct s_plane
{
	float	point[3];
	float	norma[3];
	int		color[3];
	int		inside;
	t_vec	vpoint;
	t_vec	vnorma;
	t_vec	vh_point;
	t_vec	vh_norma;
}	t_plane;

typedef struct s_cylinder
{
	float	point[3];
	float	d;
	float	h;
	float	norma[3];
	int		color[3];
	int		inside;
	t_vec	vpoint;
	t_vec	vnorma;
	t_vec	vh_point;
	t_vec	vh_norma;
}	t_cylinder;

typedef struct s_objs
{
	int			sp_len;
	int			pl_len;
	int			cy_len;
	t_sphere	*sp;
	t_plane		*pl;
	t_cylinder	*cy;
}	t_objs;

typedef struct s_arg
{
	void		*mlx;
	void		*win;
	void		*img;
	char		*img_addr;
	int			bits_per_pixel;
	int			length;
	int			endian;
	int			window_width;
	int			window_height;
	int			cntl;
	t_ambient	ambient;
	t_camera	camera;
	t_light		light;
	t_objs		objs;
	t_vec		origin;
}	t_arg;

char	rgb_idx_name(int i);
char	axis_idx_name(int i);

#endif
