#include "vec3.h"
#include "ray.h"
#include "hit_sphere.h"
#include <stdbool.h>

bool	hit_sphere(t_sphere s, t_ray r)
{
	double a;
	double half_b;
	double c;
	double discriminant;
	t_vec3 oc;

	oc = sub_vec3(r.origin, s.center);
	a = dot_vec3(r.direction, r.direction);
	half_b = dot_vec3(oc, r.direction);
	c = dot_vec3(oc, oc) - s.radius * s.radius;
	discriminant = half_b * half_b - a * c;

	if (discriminant > 0)
	{
		return (true);
	}
	return (false);
}