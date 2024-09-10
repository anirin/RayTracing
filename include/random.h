#ifndef RANDOM_H
#define RANDOM_H

#include "vec3.h"

double random_double(double min, double max);
t_vec3 random_vec3(double min, double max);
t_vec3 random_in_unit_sphere();

#endif