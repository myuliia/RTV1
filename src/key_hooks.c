/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hooks.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myuliia <myuliia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/22 14:28:39 by myuliia           #+#    #+#             */
/*   Updated: 2019/05/22 16:43:50 by myuliia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/rtv1.h"

void	info_type(t_rtv1 *rt)
{
	if (rt->obj->tmp[rt->ind_move].ind_type == 2)
		ft_putstr("The chosen figure is ~ sphere\n");
	else if (rt->obj->tmp[rt->ind_move].ind_type == 1)
		ft_putstr("The chosen figure is ~ plane\n");
	else if (rt->obj->tmp[rt->ind_move].ind_type == 3)
		ft_putstr("The chosen figure is ~ cylinder\n");
	else if (rt->obj->tmp[rt->ind_move].ind_type == 4)
		ft_putstr("The chosen figure is ~ cone\n");
}

void	movement(t_rtv1 *rt, int key)
{
	if (rt->ind_move <= 0 || rt->ind_move > rt->obj->nb_of)
		rt->ind_move = 0;
	if (key == PAGE_UP)
	{
		rt->ind_move++;
		info_type(rt);
	}
	if (key == PAGE_DOWN && rt->ind_move != 0)
	{
		rt->ind_move--;
		info_type(rt);
	}
	if (key == PLUS)
		rt->obj->tmp[rt->ind_move].center[2] -= 3;
	if (key == MINUS)
		rt->obj->tmp[rt->ind_move].center[2] += 3;
	if (key == LEFT)
		rt->obj->tmp[rt->ind_move].center[0] -= 3;
	if (key == RIGHT)
		rt->obj->tmp[rt->ind_move].center[0] += 3;
	if (key == UP)
		rt->obj->tmp[rt->ind_move].center[1] += 3;
	if (key == DOWN)
		rt->obj->tmp[rt->ind_move].center[1] -= 3;
}

void	move(t_rtv1 *rt, int key)
{
	if (key == 117)
	{
		if (rt->ind_move != 25)
			rt->ind_move = 25;
		else
			rt->ind_move = 0;
	}
	if (rt->ind_move != 25)
		movement(rt, key);
	else if (rt->ind_move == 25)
	{
		if (key == PLUS)
			rt->rays->pos[2] += 10;
		if (key == MINUS)
			rt->rays->pos[2] -= 10;
		if (key == LEFT)
			rt->rays->pos[0] += 5;
		if (key == RIGHT)
			rt->rays->pos[0] -= 5;
		if (key == UP)
			rt->rays->pos[1] -= 5;
		if (key == DOWN)
			rt->rays->pos[1] += 5;
	}
}

int		ft_key_hook(int key, t_rtv1 *rt)
{
	if (key == ESC)
	{
		system("killall afplay");
		exit(0);
	}
	if (key == KEY_H)
	{
		if (rt->ind_hints == 1)
			rt->ind_hints = 0;
		else
			rt->ind_hints = 1;
	}
	move(rt, key);
	draw_all(rt);
	return (0);
}
