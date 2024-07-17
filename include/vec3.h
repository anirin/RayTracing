#ifndef VEC3_H
# define VEC3_H

# include <math.h>
# include <stdio.h>
# include <stdlib.h>

typedef struct s_vec3
{
	double		x;
	double		y;
	double		z;
}				t_vec3;

typedef t_vec3	t_point3;
typedef t_vec3	t_color;

t_vec3			init_vec3(double x, double y, double z);
t_vec3			sub_vec3(t_vec3 v, t_vec3 u);
t_vec3			add_vec3(t_vec3 v, t_vec3 u);
t_vec3			multipul_vec3(t_vec3 v, double t);
t_vec3			div_vec3(t_vec3 v, double t);
double			dot_vec3(t_vec3 u, t_vec3 v);
t_vec3			cross_vec3(t_vec3 v, t_vec3 u);
double			length_vec3(t_vec3 v);
t_vec3			unit_vec3(t_vec3 v);

#endif
