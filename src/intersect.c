/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersect.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myuliia <myuliia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/07 19:28:06 by myuliia           #+#    #+#             */
/*   Updated: 2019/07/03 16:22:09 by myuliia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/rtv1.h"

double	ray_intersect_sphere(t_ray *ray, t_elem obj)
{
	t_vector	distance;
	double		a;
	double		b;
	double		c;
	double		t;

	distance = vector_sub(obj.center, ray->pos);
	a = vector_dot(ray->dir, ray->dir);
	b = 2.0 * vector_dot(ray->dir, distance);
	c = vector_dot(distance, distance) - (obj.radius * obj.radius);
	t = find_tt(a, b, c);
	return (t);
}

double	ray_intersect_cylinder(t_ray *ray, t_elem obj, double t)
{
	double		a;
	double		b;
	double		c;
	t_vector	distance;
	t_vector	norm_tmp;

	distance = vector_sub(obj.center, ray->pos);
	norm_tmp = vector_norm(obj.normal);
	a = vector_dot(ray->dir, ray->dir) - pow(vector_dot(norm_tmp, ray->dir), 2);
	b = 2.0 * (vector_dot(distance, ray->dir) - vector_dot(norm_tmp, distance)
		* vector_dot(norm_tmp, ray->dir));
	c = vector_dot(distance, distance) - pow(vector_dot(norm_tmp, distance), 2)
		- obj.radius * obj.radius;
	t = find_tt(a, b, c);
	return (t);
}

double	ray_intersect_cone(t_ray *ray, t_elem obj, double t)
{
	double		a;
	double		b;
	double		c;
	t_vector	distance;
	t_vector	norm_tmp;

	distance = vector_sub(obj.center, ray->pos);
	norm_tmp = vector_norm(obj.normal);
	a = vector_dot(ray->dir, ray->dir) - (1 + pow(tan(obj.radius), 2))
	* pow(vector_dot(ray->dir, norm_tmp), 2);
	b = 2 * (vector_dot(ray->dir, distance) - (1 + pow(tan(obj.radius), 2))
	* vector_dot(ray->dir, norm_tmp) * vector_dot(distance, norm_tmp));
	c = vector_dot(distance, distance) - (1 + pow(tan(obj.radius), 2))
	* pow(vector_dot(distance, norm_tmp), 2);
	t = find_tt(a, b, c);
	return (t);
}

double	ray_intersect_plane(t_ray *ray, t_elem obj, double t)
{
	t_vector	dist;

	dist = vector_sub(obj.center, ray->pos);
	t = -1 * vector_dot(obj.normal, dist) / vector_dot(obj.normal, ray->dir);
	if (t < 0.00001)
		t = -1;
	return (t);
}
