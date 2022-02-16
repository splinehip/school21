/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update_vectors.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cflorind <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/14 17:18:05 by cflorind          #+#    #+#             */
/*   Updated: 2022/02/16 16:46:45 by cflorind         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bool.h"
#include "input_handler.h"

static inline void	set_vec(t_vec *v, float p[3])
{
	v->x = p[x];
	v->y = p[y];
	v->z = p[z];
}

inline void	update_vectors(t_arg *args)
{
	int	i;

	set_vec(&args->camera.vpoint, args->camera.point);
	set_vec(&args->camera.vnorma, args->camera.norma);
	set_vec(&args->light.vpoint, args->light.point);
	i = 0;
	while (true)
	{
		if (i < args->objs.sp_len)
			set_vec(&args->objs.sp[i].vcenter, args->objs.sp[i].center);
		if (i < args->objs.pl_len)
		{
			set_vec(&args->objs.pl[i].vpoint, args->objs.pl[i].point);
			set_vec(&args->objs.pl[i].vnorma, args->objs.pl[i].norma);
		}
		if (i < args->objs.cy_len)
		{
			set_vec(&args->objs.cy[i].vpoint, args->objs.cy[i].point);
			set_vec(&args->objs.cy[i].vnorma, args->objs.cy[i].norma);
		}
		if (i >= args->objs.sp_len && i >= args->objs.pl_len
			&& i >= args->objs.cy_len)
			break ;
		i++;
	}
}
