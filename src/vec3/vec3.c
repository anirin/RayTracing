#include "vec3.h"

t_vec3	init_vec3(double x, double y, double z)
{
	t_vec3	v;

	v.x = x;
	v.y = y;
	v.z = z;
	return (v);
}

t_vec3	add_vec3(t_vec3 v, t_vec3 u)
{
	t_vec3	res;

	res.x = v.x + u.x;
	res.y = v.y + u.y;
	res.z = v.z + u.z;
	return (res);
}

t_vec3	sub_vec3(t_vec3 v, t_vec3 u)
{
	t_vec3	res;

	res.x = v.x - u.x;
	res.y = v.y - u.y;
	res.z = v.z - u.z;
	return (res);
}

t_vec3	multipul_vec3(t_vec3 v, double t)
{
	t_vec3	res;

	res.x = v.x * t;
	res.y = v.y * t;
	res.z = v.z * t;
	return (res);
}

t_vec3	div_vec3(t_vec3 v, double t)
{
	t_vec3	res;

	res.x = v.x / t;
	res.y = v.y / t;
	res.z = v.z / t;
	return (res);
}

double	length_vec3(t_vec3 v)
{
	return (sqrt(v.x * v.x + v.y * v.y + v.z * v.z));
}

t_vec3	unit_vec3(t_vec3 v)
{
	return (div_vec3(v, length_vec3(v)));
}

t_color	multipul_attenuation_vec3(t_vec3 v, t_vec3 attenuation)
{
	t_color	c;

	c.x = v.x * attenuation.x;
	c.y = v.y * attenuation.y;
	c.z = v.z * attenuation.z;

	return (c);
}

double	dot_vec3(t_vec3 v, t_vec3 u)
{
	return (v.x * u.x + v.y * u.y + v.z * u.z);
}

t_vec3	cross_vec3(t_vec3 v, t_vec3 u)
{
	t_vec3	res;

	res.x = v.y * u.z - v.z * u.y;
	res.y = v.z * u.x - v.x * u.z;
	res.z = v.x * u.y - v.y * u.x;
	return (res);
}
