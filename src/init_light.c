/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_light.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myuliia <myuliia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/09 17:53:32 by myuliia           #+#    #+#             */
/*   Updated: 2019/07/03 16:30:51 by myuliia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/rtv1.h"

t_vector	init_light_sec(t_ray *ray, t_bright b, t_elem *obj, double t)
{
	double		m;
	t_vector	dist;
	t_vector	left;
	t_vector	right;
	t_vector	tmp_normal;

	if (obj->ind_type == 4)
	{
		dist = vector_sub(obj->center, ray->pos);
		m = t * vector_dot(RD, ON) + vector_dot(dist, ON);
		m = (obj->normal[2] == 0 && obj->normal[0] == 1) ? m / 2 : m;
		left = vector_sub(obj->center, b.point);
		right = vector_mul_on(ON, (1 + pow(tan(obj->radius), 2)) * m);
		tmp_normal = vector_sub(right, left);
	}
	if (obj->ind_type == 3)
	{
		dist = vector_sub(obj->center, ray->pos);
		m = t * vector_dot(RD, ON) + vector_dot(dist, ON);
		m = (obj->normal[2] == 0 && obj->normal[0] == 1) ? m / 2 : m;
		left = vector_sub(obj->center, b.point);
		right = vector_mul_on(obj->normal, m);
		tmp_normal = vector_sub(right, left);
	}
	return (tmp_normal);
}

t_bright	init_light(t_ray *ray, double t, t_elem *obj)
{
	t_vector	tmp_normal;
	t_bright	bright;

	bright.ray_origin = ray;
	bright.point[0] = ray->pos[0] + t * ray->dir[0];
	bright.point[1] = ray->pos[1] + t * ray->dir[1];
	bright.point[2] = ray->pos[2] + t * ray->dir[2];
	if (obj->ind_type == 2)
		tmp_normal = vector_sub(obj->center, bright.point);
	else if (obj->ind_type == 1)
	{
		if (vector_dot(ray->dir, obj->normal) > 0.0)
			tmp_normal = vector_mul_on(obj->normal, -1);
		else
			tmp_normal = obj->normal;
	}
	else
		tmp_normal = init_light_sec(ray, bright, obj, t);
	bright.normal = vector_norm(tmp_normal);
	return (bright);
}

t_color		color_choose(t_elem *obj, double cos, double sp, t_light q)
{
	t_color		color;

	color.r = ((obj->color[0] / 255.0) * q.ambient +
		(obj->color[0] / 255.0) * q.diffuse * cos +
		(obj->color[0] / 255.0) * sp * q.specular) * 255;
	color.g = ((obj->color[1] / 255.0) * q.ambient +
		(obj->color[1] / 255.0) * q.diffuse * cos +
		(obj->color[1] / 255.0) * sp * q.specular) * 255;
	color.b = ((obj->color[2] / 255.0) * q.ambient +
		(obj->color[2] / 255.0) * q.diffuse * cos +
		(obj->color[2] / 255.0) * sp * q.specular) * 255;
	return (color);
}

t_color		get_color(t_rtv1 *rt, t_bright *bright, t_elem *obj, t_ray *ray)
{
	t_get		g;
	t_color		color;
	double		specular;
	double		cosin;
	t_vector	light_pos;

	light_pos = (t_vector){-20, 10, 30};
	g.ne_l = vector_sub(bright->point, light_pos);
	g.ne_v = vector_sub(bright->point, ray->pos);
	g.v = vector_norm(g.ne_v);
	g.l = vector_norm(g.ne_l);
	if (-1 < shadow(rt, bright, light_pos))
	{
		color.r = obj->color[0] * rt->quant.ambient;
		color.g = obj->color[1] * rt->quant.ambient;
		color.b = obj->color[2] * rt->quant.ambient;
		return (color);
	}
	cosin = min_max(vector_dot(bright->normal, g.l), 0, 1);
	specular = specularity(g.l, g.v, bright);
	color = color_choose(obj, cosin, specular, rt->quant);
	return (color);
}
