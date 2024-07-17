#ifndef RAY_H
# define RAY_H

# include "vec3.h"

typedef struct s_ray
{
	t_point3	origin;
	t_vec3		direction;
	double		t_min;
	double		t_max;
}				t_ray;

t_ray			init_ray(t_point3 origin, t_vec3 direction, double t_min, double t_max);
t_vec3			at(t_ray ray, double t);

#endif