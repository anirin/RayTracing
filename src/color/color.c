#include "color.h"
#include "ray.h"

unsigned int	color2int(t_color c)
{
	int	r;
	int	g;
	int	b;

	r = ((int)(255.999 * c.x));
	g = (int)(255.999 * c.y);
	b = (int)(255.999 * c.z);
	return (r << 16 | g << 8 | b);
}

t_color ray_color(t_ray r)
{
	t_vec3 unit_direction;
	t_color blue, white;
	double t;

	unit_direction = unit_vec3(r.direction);
	blue = init_vec3(0.5, 0.7, 1.0);
	white = init_vec3(1.0, 1.0, 1.0);
	t = 0.5 * (unit_direction.y + 1.0);
	return (add_vec3(multipul_vec3(white, 1.0 - t), multipul_vec3(blue, t)));
}

t_color ray_normal_color(t_ray r, t_sphere s)
{
	t_vec3 unit_vec;
	double t;

	t = hit_sphere(s, r);
	if (t > 0.0)
	{
		unit_vec = unit_vec3(sub_vec3(at(r, t), s.center));
		return multipul_vec3(init_vec3(unit_vec.x + 1, unit_vec.y + 1, unit_vec.z + 1), 0.5);
	}
	
	return (ray_color(r));
}