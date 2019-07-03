/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_calculation.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myuliia <myuliia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/07 13:34:49 by myuliia           #+#    #+#             */
/*   Updated: 2019/06/05 14:19:19 by myuliia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/rtv1.h"

double		find_tt(double a, double b, double c)
{
	double	t1;
	double	t2;
	double	discriminant;

	discriminant = b * b - 4 * a * c;
	if (discriminant < 0.0001)
		return (-1);
	else
	{
		t1 = (-b + sqrtf(discriminant)) / (2 * a);
		t2 = (-b - sqrtf(discriminant)) / (2 * a);
	}
	if (t1 >= 0.0001 && t2 >= 0.0001)
	{
		if (t1 < t2)
			return (t1);
		else
			return (t2);
	}
	return (-1);
}
