#ifndef COLOR_H
#define COLOR_H

#include "vec3.h"
#include "ray.h"

unsigned int	color2int(t_color c);
t_color ray_color(t_ray r);

#endif