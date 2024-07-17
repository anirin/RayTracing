#include "color.h"

unsigned int	color2int(t_color c)
{
	int	r;
	int	g;
	int	b;

	r = ((int)(255.999 * c.x));
	g = (int)(255.999 * c.y);
	b = (int)(255.999 * c.z);
	return (r << 16 | g << 8 | b);
}