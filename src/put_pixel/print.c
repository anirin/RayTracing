#include "print.h"

void	my_mlx_pixel_put(t_data *data, int x, int y, unsigned int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

void	draw_pixel(t_vars *vars, int x, int y, unsigned int color)
{
	if (x < 0 || x > WIDTH || y < 0 || y > HEIGHT)
		return ;
	vars->img.addr = mlx_get_data_addr(vars->img.img, &vars->img.bits_per_pixel,
			&vars->img.line_length, &vars->img.endian);
	my_mlx_pixel_put(&vars->img, x, y, color);
}
