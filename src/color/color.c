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