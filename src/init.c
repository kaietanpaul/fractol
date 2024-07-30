#include "../include/fractol.h"

t_mlx	*init_mlx_and_window(t_mlx *data, int x, int y, char *title)
{
	data = malloc(sizeof(t_mlx));

	data->width = x;
	data->height = y;

	data->mlx_ptr = mlx_init();

	data->win_ptr = mlx_new_window(data->mlx_ptr, x, y, title);

	return (data);
}

void	init_image(t_mlx *data)
{
	data->img.img_ptr = mlx_new_image(data->mlx_ptr, data->width, data->height);
	data->img.pixel_start = mlx_get_data_addr(data->img.img_ptr, &data->img.bits_per_pixel, &data->img.line_size, &data->img.pixel_order);
}