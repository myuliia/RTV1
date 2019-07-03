/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myuliia <myuliia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/22 13:53:38 by myuliia           #+#    #+#             */
/*   Updated: 2019/06/05 14:19:14 by myuliia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/rtv1.h"

void	put_pixel(t_rtv1 *rt, int x, int y, t_color color)
{
	*(unsigned int*)(rt->addr + 4 * WIDTH * y + x * 4) =
	RGB(color.r, color.g, color.b);
}

void	init_window(t_rtv1 *t, char *argv)
{
	char	*str;

	str = ft_strjoin("RTV1 - ", argv);
	t->mlx_ptr = mlx_init();
	t->win_ptr = mlx_new_window(t->mlx_ptr, WIDTH, HEIGHT, str);
	system("afplay ./msc/sound1.mp3&");
	t->img_ptr = mlx_new_image(t->mlx_ptr, WIDTH, HEIGHT);
	t->addr = mlx_get_data_addr(t->img_ptr,
		&t->bits, &t->line_size, &t->endian);
	free(str);
}

void	initial_values(t_rtv1 *rt)
{
	rt->ind_hints = 0;
	rt->ind_figure = 3;
	rt->ind_light = 1;
	rt->ind_move = 0;
	rt->quant.diffuse = 0.5;
	rt->quant.ambient = 0.2;
	rt->quant.specular = 0.2;
	rt->rays = (t_ray*)malloc(sizeof(t_ray));
	rt->rays->dir = (t_vector){0, 0, 0};
	rt->rays->pos = (t_vector){0, 0, -200};
}

int		main(int argc, char **argv)
{
	t_rtv1	*rt;

	if (argc != 2)
		ft_error(1);
	rt = (t_rtv1*)malloc(sizeof(t_rtv1));
	init_window(rt, argv[1]);
	initial_values(rt);
	rt->obj = parser(argv[1]);
	mlx_hook(rt->win_ptr, 17, 0, destroy, NULL);
	mlx_hook(rt->win_ptr, 2, (1L << 0), ft_key_hook, rt);
	draw_all(rt);
	mlx_loop(rt->mlx_ptr);
	return (0);
}
