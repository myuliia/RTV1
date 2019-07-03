/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_op.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myuliia <myuliia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/22 14:05:48 by myuliia           #+#    #+#             */
/*   Updated: 2019/05/20 13:10:00 by myuliia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/rtv1.h"

double		vector_lenght(t_vector a)
{
	return (fabs(sqrt(pow(a[0], 2) + pow(a[1], 2) + pow(a[2], 2))));
}

t_vector	vector_sum(t_vector a, t_vector b)
{
	return (a + b);
}

t_vector	vector_sub(t_vector a, t_vector b)
{
	t_vector	res;

	res[0] = b[0] - a[0];
	res[1] = b[1] - a[1];
	res[2] = b[2] - a[2];
	return (res);
}

double		vector_dot(t_vector a, t_vector b)
{
	return ((a[0] * b[0]) + (a[1] * b[1]) + (a[2] * b[2]));
}

t_vector	vector_norm(t_vector a)
{
	double len;

	len = vector_lenght(a);
	return ((t_vector){a[0] / len, a[1] / len, a[2] / len});
}
