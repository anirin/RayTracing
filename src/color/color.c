#include "color.h"
#include "ray.h"
#include "random.h"
#include "stdbool.h"
#include "hittable.h"
#include "material.h"

double my_clamp(double x, double min, double max)
{
	if (x < min)
		return (min);
	if (x > max)
		return (max);
	return (x);
}

unsigned int	color2int(t_color c, int samples_per_pixel)
{
	int	r;
	int	g;
	int	b;

	double scale = 1.0 / samples_per_pixel;

	double double_r = sqrt(c.x * scale);
	double double_g = sqrt(c.y * scale);
	double double_b = sqrt(c.z * scale);

	r = ((int)(256 * my_clamp(double_r, 0.0, 0.999)));
	g = (int)(256 * my_clamp(double_g, 0.0, 0.999));
	b = (int)(256 * my_clamp(double_b, 0.0, 0.999));
	return (r << 16 | g << 8 | b);
}

t_color ray_background_color(t_ray r)
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

//法線 & 背景の描画
t_color ray_normal_color(t_ray r, t_sphere s, t_material *material)
{
	t_vec3 unit_vec;
	t_hit_record rec;
	bool has_hit;

	// todo &の型変換はキモすぎる
	has_hit = hit_sphere((void *)&s, material, r, &rec);
	if (has_hit)
	{
		unit_vec = unit_vec3(sub_vec3(at(r, rec.t), s.center));
		return multipul_vec3(init_vec3(unit_vec.x + 1, unit_vec.y + 1, unit_vec.z + 1), 0.5);
	}
	
	return (ray_background_color(r));
}

// todo worldを作成する必要がある
t_color ray_color(t_ray r, t_world world, int depth)
{
	t_hit_record rec;

	if (depth <= 0)
	{
		return (init_vec3(0.0, 0.0, 0.0));
	}

	if (hit(world, r, &rec))
	{
		t_ray scattered;
		t_color attenuation;

		if (rec.material->scatter(r, &rec, &attenuation, &scattered))
			return multipul_attenuation_vec3(ray_color(scattered, world, depth - 1), attenuation);
			// return ray_color(scattered, world, depth - 1);
		else
		{
			return (init_vec3(0.0, 0.0, 0.0));
		}
	}

	return (ray_background_color(r));
}