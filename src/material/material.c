#include "material.h"
#include "random.h"

bool landertian(t_ray r, struct s_hit_record *rec, t_color *attenuation, t_ray *scatterd)
{
	t_vec3 scatter_direction = add_vec3(rec->normal, random_in_unit_sphere());
	*scatterd = init_ray(rec->p, scatter_direction, r.t_min, r.t_max);

	*attenuation = rec->material->albedo;
	return (true);
}

static t_vec3 reflect_vec3(t_vec3 v, t_vec3 n)
{
	return (sub_vec3(v, multipul_vec3(n, 2 * dot_vec3(v, n))));
}

bool reflect(t_ray r, struct s_hit_record *rec, t_color *attenuation, t_ray *scatterd)
{
	t_vec3 reflected = reflect_vec3(unit_vec3(r.direction), rec->normal);
	*scatterd = init_ray(rec->p, reflected, r.t_min, r.t_max);

	*attenuation = rec->material->albedo;
	// return (dot_vec3(scatterd->direction, rec->normal) > 0);
	return (true);
}