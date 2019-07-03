/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_helper.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myuliia <myuliia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/20 12:35:26 by myuliia           #+#    #+#             */
/*   Updated: 2019/07/03 16:17:17 by myuliia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/rtv1.h"

void	canvas_to_viewpoint(double x, double y, t_ray *ray)
{
	ray->dir[0] = x / WIDTH - 0.5;
	ray->dir[1] = 0.5 + -y / HEIGHT;
	ray->dir[2] = 1;
}

double	min_max(double x, double min, double max)
{
	if (x < min)
		x = min;
	else if (x > max)
		x = max;
	return (x);
}
