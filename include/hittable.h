#ifndef HITTABLE_H
#define HITTABLE_H

#include "vec3.h"
#include "ray.h"
#include <stdbool.h>

#define SPHERE 1

typedef struct s_hit_record
{
	t_point3 p;
	t_vec3 normal;
	double t;
	bool front_face;
}				t_hit_record;

typedef int t_object_type;
typedef bool (*t_hit_function)(void *object, t_ray r, t_hit_record *rec);

typedef struct s_object_list
{
	t_object_type type;
	t_hit_function hit;
	void *object;

	struct s_object_list *next;
}				t_object_list;

typedef struct s_world
{
	t_object_list *objects;
}				t_world;

bool hit(t_world world, t_ray r, t_hit_record *rec);

#endif