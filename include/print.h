#ifndef PRINT_H
# define PRINT_H

# include "minirt.h"

void	my_mlx_pixel_put(t_data *data, int x, int y, unsigned int color);
void	draw_pixel(t_vars *vars, int x, int y, unsigned int color);

#endif