#include "camera.h"

t_camera init_camera()
{
	double aspect_ratio = 16.0 / 9.0;
	double viewport_height = 2.0;
	double viewport_width = aspect_ratio * viewport_height;
	double focal_length = 1.0;
	t_point3 origin = init_vec3(0, 0, 0);
	t_vec3 horizontal = init_vec3(viewport_width, 0, 0);
	t_vec3 vertical = init_vec3(0, viewport_height, 0);
	t_vec3 lower_left_corner = sub_vec3(sub_vec3(sub_vec3(origin, div_vec3(horizontal, 2)), div_vec3(vertical, 2)), init_vec3(0, 0, focal_length));

	t_camera camera;

	camera.aspect_ratio = aspect_ratio;
	camera.viewport_height = viewport_height;
	camera.viewport_width = viewport_width;
	camera.focal_length = focal_length;
	camera.origin = origin;
	camera.horizontal = horizontal;
	camera.vertical = vertical;
	camera.lower_left_corner = lower_left_corner;

	return camera;
}

t_ray camera_get_ray(t_camera camera, double u, double v)
{
	t_vec3 direction = sub_vec3(add_vec3(camera.lower_left_corner, add_vec3(multipul_vec3(camera.horizontal, u), multipul_vec3(camera.vertical, v))), camera.origin);
	t_ray r = init_ray(camera.origin, direction, 0.00, INFINITY);

	return r;
}