/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myuliia <myuliia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/22 16:18:28 by myuliia           #+#    #+#             */
/*   Updated: 2019/06/05 14:39:13 by myuliia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/rtv1.h"

void	draw_all(t_rtv1 *t)
{
	draw(t);
	if (t->ind_hints == 1)
	{
		hints(t);
	}
}

double	intersection(t_rtv1 *rt, t_ray ray)
{
	int			i;
	double		t;
	double		tmp;

	i = -1;
	t = 8000;
	tmp = 8000;
	rt->ind_figure = 0;
	while (++i <= rt->obj->nb_of)
	{
		if (rt->obj->tmp[i].ind_type == 2)
			tmp = ray_intersect_sphere(&ray, rt->obj->tmp[i]);
		if (rt->obj->tmp[i].ind_type == 1)
			tmp = ray_intersect_plane(&ray, rt->obj->tmp[i], 0);
		if (rt->obj->tmp[i].ind_type == 3)
			tmp = ray_intersect_cylinder(&ray, rt->obj->tmp[i], 0);
		if (rt->obj->tmp[i].ind_type == 4)
			tmp = ray_intersect_cone(&ray, rt->obj->tmp[i], 0);
		if (0.0001 < tmp && tmp < t)
		{
			t = tmp;
			rt->ind_figure = i;
		}
	}
	return (t);
}

t_color	ray_tracing(t_rtv1 *rt, t_ray ray, int x, int y)
{
	double		t;
	double		sum[3];
	t_color		color;
	t_xy		xyt;

	xyt.y1 = y - 1;
	rt->p = 0.0;
	sum_color(sum, &color, rt->p, 0);
	while (++xyt.y1 < y + 1)
	{
		xyt.x1 = x - 1;
		while (++xyt.x1 < x + 1)
		{
			canvas_to_viewpoint(x, y, &ray);
			t = intersection(rt, ray);
			if (t > 0.0001 && t < 8000.0)
				color = lightning(rt, t, &ray, &rt->obj->tmp[rt->ind_figure]);
			else
				color = (t_color){0, 0, 0};
			sum_color(sum, &color, rt->p, 1);
			rt->p++;
		}
	}
	sum_color(sum, &color, rt->p, 2);
	return (color);
}

void	draw(t_rtv1 *rt)
{
	int			y;
	int			x;
	t_ray		ray;
	t_color		color;

	ray.dir = rt->rays->dir;
	ray.pos = rt->rays->pos;
	x = -1;
	while (++x < HEIGHT)
	{
		y = -1;
		while (++y < WIDTH)
		{
			color = ray_tracing(rt, ray, x, y);
			put_pixel(rt, x, y, color);
		}
	}
	mlx_put_image_to_window(rt->mlx_ptr, rt->win_ptr, rt->img_ptr, 0, 0);
}
