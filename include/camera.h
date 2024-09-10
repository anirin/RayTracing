#ifndef CAMERA_H
#define CAMERA_H

#include "minirt.h"
#include "vec3.h"
#include "ray.h"

typedef struct s_camera
{
	double 		aspect_ratio;
	double 		viewport_height;
	double 		viewport_width;
	double 		focal_length;

	t_point3	origin;
	t_point3	lower_left_corner;
	t_vec3		horizontal;
	t_vec3		vertical;
}				t_camera;

t_camera init_camera();
t_ray camera_get_ray(t_camera camera, double u, double v);

#endif