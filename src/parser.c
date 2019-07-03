/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myuliia <myuliia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/02 12:58:05 by myuliia           #+#    #+#             */
/*   Updated: 2019/06/05 14:18:17 by myuliia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/rtv1.h"

t_vector	save_vector(int i, char **str)
{
	t_vector	res;

	res = (t_vector){ft_atoi(str[i]), ft_atoi(str[i + 1]), ft_atoi(str[i + 2])};
	return (res);
}

t_vector	save_vector_cylinder(int i, char **str)
{
	t_vector	res;
	int			x;
	int			y;
	int			z;

	x = ft_atoi(str[i]);
	y = ft_atoi(str[i + 1]);
	z = ft_atoi(str[i + 2]);
	if (x == 1 && y == 1 && z == 1)
		res = (t_vector){0.57, 0.57, 0.57};
	else if (x == 0 && y == 1 && z == 1)
		res = (t_vector){0, 0.7, 0.7};
	else if (x == 1 && y == 0 && z == 1)
		res = (t_vector){0.7, 0, 0.7};
	else
		res = (t_vector){ft_atoi(str[i]),
			ft_atoi(str[i + 1]), ft_atoi(str[i + 2])};
	return (res);
}

t_vector	save_vector_cone(int i, char **str)
{
	t_vector	res;
	int			x;
	int			y;
	int			z;

	x = ft_atoi(str[i]);
	y = ft_atoi(str[i + 1]);
	z = ft_atoi(str[i + 2]);
	if (x == 1 && y == 1 && z == 1)
		res = (t_vector){0.57, 0.57, 0.57};
	else if (x == 0 && y == 1 && z == 1)
		res = (t_vector){0, 0.7, 0.7};
	else if (x == 1 && y == 0 && z == 1)
		res = (t_vector){0.7, 0, 0.7};
	else
		res = (t_vector){ft_atoi(str[i]),
			ft_atoi(str[i + 1]), ft_atoi(str[i + 2])};
	return (res);
}

void		parser_adder(char *line, t_obj *obj)
{
	int			len;

	len = ft_strlen(line);
	if (strncmp(line, "sphere:", 6) == 0 && (len > 50 && len < 74))
		sphere_add(line, obj);
	else if (strncmp(line, "cylinder:", 9) == 0 && (len > 69 && len < 90))
		cylinder_add(line, obj);
	else if (strncmp(line, "plane:", 6) == 0 && (len > 55 && len < 67))
		plane_add(line, obj);
	else if (strncmp(line, "cone:", 5) == 0 && (len > 69 && len < 90))
		cone_add(line, obj);
	else
		ft_error(0);
	free(line);
	obj->nb_of++;
}

t_obj		*parser(char *str)
{
	int			fd;
	char		*line;
	t_obj		*obj;

	obj = (t_obj*)malloc(sizeof(t_obj));
	obj->nb_of = 0;
	if (ft_strncmp(str, "scene", 5) != 0)
		ft_error(3);
	if (((fd = open(str, O_RDONLY)) < 0) || (open(str, O_DIRECTORY)) > 0)
		ft_error(2);
	while ((get_next_line(fd, &line)) == 1 && obj->nb_of < 15)
		parser_adder(line, obj);
	close(fd);
	return (obj);
}
