/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rtv1.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myuliia <myuliia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/22 17:02:10 by myuliia           #+#    #+#             */
/*   Updated: 2019/07/03 16:30:59 by myuliia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RTV1_H
# define RTV1_H

# include <fcntl.h>
# include <stdlib.h>
# include <mlx.h>
# include <unistd.h>
# include <math.h>
# include "../libft/libft.h"
# include <pthread.h>
# define WIDTH 500
# define HEIGHT 500
# define RGB(r, g, b)(256 * 256 * (int)r + 256 * (int)g + (int)b)
# define RD ray->dir
# define ON obj->normal
# define KEY_H 4
# define ESC 53
# define LEFT 123
# define DOWN 125
# define RIGHT 124
# define UP	126
# define MINUS 27
# define PLUS 24
# define PAGE_UP 116
# define PAGE_DOWN 121

typedef double	t_vector __attribute__((vector_size(sizeof(double)*3)));

typedef	struct		s_xy
{
	double			t;
	double			x1;
	double			y1;
}					t_xy;

typedef	struct		s_get
{
	t_vector		ne_v;
	t_vector		ne_l;
	t_vector		l;
	t_vector		v;
}					t_get;

typedef	struct		s_ray
{
	t_vector		pos;
	t_vector		dir;
}					t_ray;

typedef struct		s_elem
{
	int				ind_type;
	double			radius;
	t_vector		normal;
	t_vector		center;
	t_vector		color;

}					t_elem;

typedef struct		s_bright
{
	t_ray			*ray_origin;
	t_vector		point;
	t_vector		normal;
	t_vector		color;
	double			t;
}					t_bright;

typedef struct		s_obj
{
	int				nb_of;
	int				tmp_nb;
	t_elem			tmp[20];
}					t_obj;

typedef struct		s_light
{
	double			diffuse;
	double			ambient;
	double			specular;
}					t_light;

typedef	struct		s_color
{
	int				r;
	int				g;
	int				b;
}					t_color;

typedef struct		s_rtv1
{
	void			*mlx_ptr;
	void			*win_ptr;
	void			*img_ptr;
	char			*addr;
	int				bits;
	int				line_size;
	int				endian;
	int				ind_hints;
	int				ind_figure;
	int				ind_light;
	int				ind_move;
	double			p;
	t_vector		color;
	t_obj			*obj;
	t_light			quant;
	t_ray			*rays;
}					t_rtv1;

int					destroy(void);
void				ft_error(int n);
int					ft_key_hook(int key, t_rtv1 *rt);
void				init_window(t_rtv1 *t, char *argv);
void				initial_values(t_rtv1 *tr);
void				draw_all(t_rtv1 *t);
void				draw(t_rtv1 *rt);
void				hints(t_rtv1 *t);
void				put_pixel(t_rtv1 *t, int x, int y, t_color color);
double				vector_lenght(t_vector a);
t_vector			vector_sum(t_vector a, t_vector b);
t_vector			vector_sub(t_vector a, t_vector b);
double				vector_dot(t_vector a, t_vector b);
t_vector			vector_norm(t_vector a);
t_vector			vector_div_on(t_vector a, double b);
t_vector			vector_mul_on(t_vector a, double b);
t_obj				*parser(char *str);
void				parser_adder(char *line, t_obj *obj);
void				sphere_add(char *line, t_obj *obj);
void				cylinder_add(char *line, t_obj *obj);
void				plane_add(char *line, t_obj *obj);
void				cone_add(char *line, t_obj *obj);
t_vector			save_vector(int i, char **str);
t_vector			save_vector_cylinder(int i, char **str);
t_vector			save_vector_cone(int i, char **str);
double				find_tt(double a, double b, double c);
void				canvas_to_viewpoint(double x, double y, t_ray *ray);
double				intersection(t_rtv1 *rt, t_ray ray);
t_color				ray_tracing(t_rtv1 *rt, t_ray ray, int x, int y);
double				ray_intersect_sphere(t_ray *ray, t_elem obj);
double				ray_intersect_cylinder(t_ray *ray,
		t_elem obj, double t);
double				ray_intersect_cone(t_ray *ray,
		t_elem obj, double t);
double				ray_intersect_plane(t_ray *ray,
		t_elem obj, double t);
t_color				get_color(t_rtv1 *rt, t_bright *bright,
		t_elem *obj, t_ray *ray);
t_color				lightning(t_rtv1 *rt, double t, t_ray *ray, t_elem *obj);
t_bright			init_light(t_ray *ray,
		double t, t_elem *obj);
t_vector			init_light_sec(t_ray *ray, t_bright b,
		t_elem *obj, double t);
double				shadow(t_rtv1 *rt, t_bright *bright, t_vector light_pos);
t_color				color_choose(t_elem *obj, double cos, double sp, t_light q);
double				specularity(t_vector l, t_vector v, t_bright *bright);
void				sum_color(double sum[3], t_color *c, double p, int flag);
double				min_max(double x, double min, double max);
#endif
