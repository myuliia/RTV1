/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_add.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myuliia <myuliia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/02 15:23:00 by myuliia           #+#    #+#             */
/*   Updated: 2019/05/22 14:08:20 by myuliia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/rtv1.h"

void	sphere_add(char *line, t_obj *obj)
{
	int		i;
	char	**str;

	str = ft_strsplit(line, ' ');
	i = 1;
	obj->tmp[obj->nb_of].ind_type = 2;
	if ((ft_strncmp(str[1], "center(", 7) == 0)
		&& (ft_strncmp(str[5], "radius(", 7) == 0)
		&& (ft_strncmp(str[7], "color(", 6) == 0))
	{
		obj->tmp[obj->nb_of].center = save_vector(2, str);
		obj->tmp[obj->nb_of].radius = ft_atoi(str[6]);
		obj->tmp[obj->nb_of].color = save_vector(8, str);
	}
	else
		ft_error(0);
	ft_free_el_arr(str);
}

void	cylinder_add(char *line, t_obj *obj)
{
	int		i;
	char	**str;

	str = ft_strsplit(line, ' ');
	i = 1;
	obj->tmp[obj->nb_of].ind_type = 3;
	if ((ft_strncmp(str[1], "center(", 7) == 0) &&
		(ft_strncmp(str[5], "radius(", 7) == 0)
		&& (ft_strncmp(str[7], "normal(", 7) == 0)
		&& (ft_strncmp(str[11], "color(", 6) == 0))
	{
		obj->tmp[obj->nb_of].center = save_vector(2, str);
		obj->tmp[obj->nb_of].radius = ft_atoi(str[6]);
		obj->tmp[obj->nb_of].normal = save_vector_cylinder(8, str);
		obj->tmp[obj->nb_of].color = save_vector(12, str);
	}
	else
		ft_error(0);
	ft_free_el_arr(str);
}

void	plane_add(char *line, t_obj *obj)
{
	int		i;
	char	**str;

	str = ft_strsplit(line, ' ');
	i = 1;
	obj->tmp[obj->nb_of].ind_type = 1;
	if ((ft_strncmp(str[1], "center(", 7) == 0)
		&& (ft_strncmp(str[5], "normal(", 7) == 0)
		&& (ft_strncmp(str[9], "color(", 6) == 0))
	{
		obj->tmp[obj->nb_of].center = save_vector(2, str);
		obj->tmp[obj->nb_of].normal = save_vector(6, str);
		obj->tmp[obj->nb_of].color = save_vector(10, str);
	}
	else
		ft_error(0);
	ft_free_el_arr(str);
}

void	cone_add(char *line, t_obj *obj)
{
	int		i;
	char	**str;

	str = ft_strsplit(line, ' ');
	i = 1;
	obj->tmp[obj->nb_of].ind_type = 4;
	if ((ft_strncmp(str[1], "center(", 7) == 0) &&
		(ft_strncmp(str[5], "radius(", 7) == 0)
		&& (ft_strncmp(str[7], "normal(", 7) == 0)
		&& (ft_strncmp(str[11], "color(", 6) == 0))
	{
		obj->tmp[obj->nb_of].center = save_vector(2, str);
		obj->tmp[obj->nb_of].radius = ft_atoi(str[6]);
		obj->tmp[obj->nb_of].normal = save_vector_cone(8, str);
		obj->tmp[obj->nb_of].color = save_vector(12, str);
	}
	else
		ft_error(0);
	ft_free_el_arr(str);
}
