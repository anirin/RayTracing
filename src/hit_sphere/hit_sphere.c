#include "vec3.h"
#include "ray.h"
#include "hit_sphere.h"
#include "random.h"
#include <stdbool.h>

bool	help_hit_sphere(t_sphere s, t_ray r, double temp, t_hit_record *rec)
{
	t_vec3 outward_normal;

	if (temp < r.t_max && temp > r.t_min)
	{
		rec->t = temp;
		rec->p = at(r, rec->t);
		outward_normal = div_vec3(sub_vec3(rec->p, s.center), s.radius);
		set_face_normal(rec, r, add_vec3(outward_normal, random_in_unit_sphere()));
		return (true);
	}

	return (false);
}

bool	hit_sphere(t_sphere s, t_ray r, t_hit_record *rec)
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

	if (discriminant > 0.0)
	{
		double root;
		double temp;

		root = sqrt(discriminant);
		temp = (-half_b - root) / a;
		if (help_hit_sphere(s, r, temp, rec))
			return (true);

		temp = (-half_b + root) / a;
		if (help_hit_sphere(s, r, temp, rec))
			return (true);
	}
	return (false);
}