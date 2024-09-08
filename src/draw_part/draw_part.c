#include "minirt.h"
#include "vec3.h"
#include "ray.h"
#include "color.h"
#include "print.h"
#include "hit_sphere.h"
#include "mlx.h"

void logic(t_vars *vars, t_vec3 lower_left_corner, t_vec3 horizontal, t_vec3 vertical, t_vec3 origin) {
	double u;
	double v;
	t_ray r;
	t_vec3 direction;
	t_color pixel_color;

	t_sphere s;

	s.center = init_vec3(0, 0, -1);
	s.radius = 0.5;
	s.color = init_vec3(0.7, 0.3, 0.3);


	for(int j = HEIGHT - 1; j >= 0; --j) {
		for (int i = 0; i < WIDTH; ++i) {
			u = (double)i / (WIDTH - 1);
			v = (double)j / (HEIGHT - 1);

			//todo
			direction = sub_vec3(add_vec3(lower_left_corner, add_vec3(multipul_vec3(horizontal, u), multipul_vec3(vertical, v))), origin);
			r = init_ray(origin, direction, 0.00, INFINITY);
			pixel_color = ray_normal_color(r, s);
			draw_pixel(vars, i, (HEIGHT - 1) - j, color2int(pixel_color));
		}
	}
}

void draw_part (t_vars *vars)
{
	double aspect_ratio = 16.0 / 9.0;
	double viewport_height = 2.0;
	double viewport_width = aspect_ratio * viewport_height;
	double focal_length = 1.0;

	t_point3 origin = init_vec3(0, 0, 0);
	t_vec3 horizontal = init_vec3(viewport_width, 0, 0);
	t_vec3 vertical = init_vec3(0, viewport_height, 0);
	t_vec3 lower_left_corner = sub_vec3(sub_vec3(sub_vec3(origin, div_vec3(horizontal, 2)), div_vec3(vertical, 2)), init_vec3(0, 0, focal_length));

	logic(vars, lower_left_corner, horizontal, vertical, origin);
	mlx_put_image_to_window(vars->mlx, vars->win, vars->img.img, 0, 0);
}