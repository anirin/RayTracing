#ifndef HITTABLE_H
#define HITTABLE_H

#include "vec3.h"
#include "ray.h"
#include "material.h"
#include <stdbool.h>

#define SPHERE 1
#define PLANE 2

// 循環参照を防ぐための前方宣言
struct s_material;
typedef struct s_hit_record
{
	t_point3 p;
	t_vec3 normal;
	double t;
	bool front_face;
	struct s_material *material;
	// t_material material;
}				t_hit_record;

typedef int t_object_type;
typedef bool (*t_hit_function)(void *object, struct s_material *material, t_ray r, t_hit_record *rec);

typedef struct s_object_list
{
	t_object_type type;
	t_hit_function hit;
	void *object;
	struct s_material *material;

	struct s_object_list *next;
}				t_object_list;

typedef struct s_world
{
	t_object_list *objects;
}				t_world;

bool hit(t_world world, t_ray r, t_hit_record *rec);

#endif