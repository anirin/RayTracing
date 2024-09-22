#ifndef HIT_SPHERE_H
# define HIT_SPHERE_H

# include "vec3.h"
# include "ray.h"
#include "hittable.h"
# include <stdbool.h>

typedef struct s_sphere
{
	t_point3	center;
	double		radius;
	t_color		color;
}				t_sphere;

bool	hit_sphere(void *object, t_ray r, t_hit_record *rec);

#endif