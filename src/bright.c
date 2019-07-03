/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bright.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myuliia <myuliia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/09 15:08:19 by myuliia           #+#    #+#             */
/*   Updated: 2019/07/03 17:51:06 by myuliia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/rtv1.h"

void	sum_color(double sum[3], t_color *c, double p, int flag)
{
	if (2 == flag)
	{
		c->r = sum[0] / p;
		c->g = sum[1] / p;
		c->b = sum[2] / p;
	}
	if (0 == flag)
	{
		sum[0] = 0.0;
		sum[1] = 0.0;
		sum[2] = 0.0;
	}
	if (1 == flag)
	{
		sum[0] += (double)c->r;
		sum[1] += (double)c->g;
		sum[2] += (double)c->b;
	}
}

double	shadow(t_rtv1 *rt, t_bright *bright, t_vector light_pos)
{
	t_vector	ne_l;
	t_vector	ln;
	t_ray		ray;
	t_vector	l;
	double		t;

	ne_l = vector_sub(bright->point, light_pos);
	ln[0] = ne_l[0];
	ln[1] = ne_l[1];
	ln[2] = ne_l[2];
	l = vector_norm(ne_l);
	ray.dir = l;
	ray.pos = bright->point;
	t = intersection(rt, ray);
	if (t > 0.001 && t < sqrtf(vector_dot(ln, ln)))
		return (t);
	else
		return (-1);
}

double	specularity(t_vector l, t_vector v, t_bright *bright)
{
	t_vector	halfway;
	t_vector	tmp_halfway;
	double		specular;

	tmp_halfway = v + l;
	halfway = vector_norm(tmp_halfway);
	specular = vector_dot(bright->normal, halfway);
	specular = specular > 0.0001 ? specular : 0.0;
	specular = pow(specular, 100);
	return (specular);
}

t_color	lightning(t_rtv1 *rt, double t, t_ray *ray, t_elem *obj)
{
	t_color		tmp_color;
	t_color		color;
	t_bright	bright;
	double		tmpt;

	color.r = 0;
	color.g = 0;
	color.b = 0;
	tmpt = t;
	bright = init_light(ray, t, obj);
	if (rt->ind_light == 1)
	{
		tmp_color = get_color(rt, &bright, obj, ray);
		color.r = (color.r + tmp_color.r) > 255 ? 255 : color.r + tmp_color.r;
		color.g = (color.g + tmp_color.g) > 255 ? 255 : color.g + tmp_color.g;
		color.b = (color.b + tmp_color.b) > 255 ? 255 : color.b + tmp_color.b;
	}
	return (color);
}
