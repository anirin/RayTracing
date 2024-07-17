#include "minirt.h"

void logic(t_vars *vars) {
	for(int j = HEIGHT - 1; j >= 0; --j) {
		for (int i = 0; i < WIDTH; ++i) {
			//todo
		}
	}
}

void draw_part (t_vars *vars)
{
	logic(vars);
	mlx_put_image_to_window(vars->mlx, vars->win, vars->img.img, 0, 0);
}