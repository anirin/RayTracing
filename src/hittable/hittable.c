#include "hittable.h"
#include "hit_sphere.h"

bool hit(t_world world, t_ray r, t_hit_record *rec)
{
	t_hit_record tmp;
	bool has_hit = false;
	t_object_list *objects = world.objects;

	while (objects)
	{
		if (objects->hit(objects->object, objects->material, r, &tmp))
		{
			has_hit = true;
			r.t_max = tmp.t;
			*rec = tmp;
		}
		objects = objects->next;
	}

	return (has_hit);
}