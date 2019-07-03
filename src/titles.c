/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   titles.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myuliia <myuliia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/29 13:40:42 by myuliia           #+#    #+#             */
/*   Updated: 2019/06/05 14:19:20 by myuliia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/rtv1.h"

void	hints(t_rtv1 *t)
{
	mlx_string_put(t->mlx_ptr, t->win_ptr, 7, 400,
		0x98a0ad, "'arrows'              move");
	mlx_string_put(t->mlx_ptr, t->win_ptr, 7, 420,
		0x98a0ad, "'page up/page down'   choose another object");
	mlx_string_put(t->mlx_ptr, t->win_ptr, 7, 440,
		0x98a0ad, "'delete'              reset selected object");
}
