#include "ray.h"

t_ray	init_ray(t_point3 origin, t_vec3 direction, double t_min, double t_max)
{
	t_ray ray;

	ray.origin = origin;
	ray.direction = direction;
	ray.t_min = t_min;
	ray.t_max = t_max;
	return (ray);
}

t_vec3	at(t_ray ray, double t)
{
	return (add_vec3(ray.origin, multipul_vec3(ray.direction, t)));
}