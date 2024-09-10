#include "minirt.h"
#include "vec3.h"
#include "ray.h"
#include "color.h"
#include "print.h"
#include "hit_sphere.h"
#include "mlx.h"
#include "camera.h"
#include "random.h"

void logic(t_vars *vars, t_camera camera, t_sphere s) {
	double u;
	double v;
	t_ray r;
	t_color pixel_color;
	int sample_per_pixel = 1;

	for(int j = HEIGHT - 1; j >= 0; --j) {
		for (int i = 0; i < WIDTH; ++i) {
			pixel_color = init_vec3(0, 0, 0);
			for (int t = 0; t < sample_per_pixel; ++t) {
				u = (i + random_double(0, 1)) / (WIDTH - 1);
				v = (j + random_double(0, 1)) / (HEIGHT - 1);

				r = camera_get_ray(camera, u, v);
				pixel_color = add_vec3(ray_normal_color(r, s), pixel_color);
			}
			pixel_color = div_vec3(pixel_color, sample_per_pixel);
			draw_pixel(vars, i, (HEIGHT - 1) - j, color2int(pixel_color));
		}
	}
}

void draw_part (t_vars *vars)
{
	t_camera camera = init_camera();
	t_sphere s;

	s.center = init_vec3(0, 0, -1);
	s.radius = 0.5;
	s.color = init_vec3(0.7, 0.3, 0.3);

	logic(vars, camera, s);
	mlx_put_image_to_window(vars->mlx, vars->win, vars->img.img, 0, 0);
}