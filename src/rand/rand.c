#include "random.h"
#include <stdlib.h>


static double base_random_double()
{
	return rand() / ((long)RAND_MAX + 1);
}

double random_double(double min, double max)
{
	return min + (max - min) * base_random_double();
}

t_vec3 random_vec3(double min, double max)
{
	t_vec3 res;

	res.x = random_double(min, max);
	res.y = random_double(min, max);
	res.z = random_double(min, max);

	return (res);
}

t_vec3 random_in_unit_sphere()
{
	t_vec3 p;

	while (1)
	{
		p = random_vec3(-1, 1);
		if (length_vec3(p) < 1)
			break;
	}

	return (p);
}