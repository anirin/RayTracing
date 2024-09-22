#include "minirt.h"
#include "vec3.h"
#include "ray.h"
#include "color.h"
#include "print.h"
#include "hit_sphere.h"
#include "mlx.h"
#include "camera.h"
#include "random.h"

void logic(t_vars *vars, t_camera camera, t_world world) {
	double u;
	double v;
	t_ray r;
	t_color pixel_color;
	int sample_per_pixel = 10;
	int depth = 50;

	for(int j = HEIGHT - 1; j >= 0; --j) {
		for (int i = 0; i < WIDTH; ++i) {
			pixel_color = init_vec3(0, 0, 0);
			for (int t = 0; t < sample_per_pixel; ++t) {
				u = (i + random_double(0, 1)) / (WIDTH - 1);
				v = (j + random_double(0, 1)) / (HEIGHT - 1);

				r = camera_get_ray(camera, u, v);
				pixel_color = add_vec3(ray_color(r, world, depth), pixel_color);
			}
			draw_pixel(vars, i, (HEIGHT - 1) - j, color2int(pixel_color, sample_per_pixel));
		}
	}
}

void set_world(t_world *world) {
	t_object_list *objects = malloc(sizeof(t_object_list));
	t_sphere *s = malloc(sizeof(t_sphere));
	t_object_list *objects2 = malloc(sizeof(t_object_list));
	t_sphere *s2 = malloc(sizeof(t_sphere));

	// Sphere1
	s->center = init_vec3(0, 0, -1);
	s->radius = 0.5;
	s->color = init_vec3(0.7, 0.3, 0.3);

	objects->type = SPHERE;
	objects->hit = hit_sphere;
	objects->object = s;
	objects->next = objects2;

	// Sphere2

	s2->center = init_vec3(0, -100.5, -1);
	s2->radius = 100;
	s2->color = init_vec3(0.8, 0.8, 0.0);

	objects2->type = SPHERE;
	objects2->hit = hit_sphere;
	objects2->object = s2;
	objects2->next = NULL;

	world->objects = objects;
}

void draw_part (t_vars *vars)
{
	t_camera camera = init_camera();
	t_world world;

	set_world(&world);

	logic(vars, camera, world);
	mlx_put_image_to_window(vars->mlx, vars->win, vars->img.img, 0, 0);
}