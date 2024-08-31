#include "../include/fractol.h"

t_mlx	*init_mlx_win_img(t_mlx *data, int x, int y, char *title)
{
	data = malloc(sizeof(t_mlx));
	data->width = x;
	data->height = y;
	data->name = title;
	data->minmax = (t_minmax){-2.0, 2.0, -2.0, 2.0};
	data->comp = (t_complex){0.285, 0.01};
	data->mlx = mlx_init();
	data->win = mlx_new_window(data->mlx, x, y, title);
	data->img.img = mlx_new_image(data->mlx, data->width, data->height);
	data->img.pixel_start = mlx_get_data_addr(data->img.img,
			&data->img.bits_per_pixel,
			&data->img.line_size,
			&data->img.pixel_order);
	return (data);
}
