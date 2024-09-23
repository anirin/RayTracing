#ifndef MATERIAL_H
#define MATERIAL_H

#include "ray.h"
#include "hittable.h"
#include <stdbool.h>

// 循環参照を防ぐための前方宣言
struct s_hit_record;

typedef bool (*t_scatter_function )(t_ray r, struct s_hit_record *rec, t_color *attenuation, t_ray *scatterd);

typedef struct s_material
{
	t_scatter_function scatter;	
	t_color albedo;
}				t_material;

bool landertian(t_ray r, struct s_hit_record *rec, t_color *attenuation, t_ray *scatterd);
bool reflect(t_ray r, struct s_hit_record *rec, t_color *attenuation, t_ray *scatterd);

#endif