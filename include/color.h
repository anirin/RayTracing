#ifndef COLOR_H
#define COLOR_H

#include "vec3.h"
#include "ray.h"
#include "hit_sphere.h"

unsigned int	color2int(t_color c);
t_color ray_color(t_ray r, t_world world, int depth);
t_color ray_normal_color(t_ray r, t_sphere s);

#endif