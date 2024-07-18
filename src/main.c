
#include "minirt.h"
#include "draw_part.h"
#include "mlx.h"
#include <stdio.h>
#include <stdlib.h>

int	window_close(t_vars *vars)
{
	printf("window close\n");
	mlx_destroy_image(vars->mlx, vars->img.img);
	mlx_destroy_window(vars->mlx, vars->win);
	exit(0);
	return (0);
}

int	main(void)
{
	t_vars	vars;

	vars.mlx = mlx_init();
	vars.win = mlx_new_window(vars.mlx, WIDTH, HEIGHT, "sample");
	vars.img.img = mlx_new_image(vars.mlx, WIDTH, HEIGHT);
	draw_part(&vars);
	mlx_hook(vars.win, ON_DESTROY, 0, window_close, &vars);
	mlx_loop(vars.mlx);
	return (0);
}
