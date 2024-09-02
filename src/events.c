#include "../include/fractol.h"

int	key_event(int keysym, t_mlx *data)
{
	if (keysym == XK_Escape)
	{
		mlx_destroy_image(data->mlx, data->img.img);
		mlx_destroy_window(data->mlx, data->win);
		mlx_destroy_display(data->mlx);
		free(data->mlx);
		free(data);
		exit(1);
	}
	if (keysym == XK_BackSpace)
	{
		mlx_destroy_image(data->mlx, data->img.img);
		data->img.img = mlx_new_image(data->mlx, data->width, data->height);
	}
	else
		mlx_put_image_to_window(data->mlx, data->win, data->img.img, 0, 0);
	return (0);
}

int	mouse_event(int button, int x, int y, t_mlx *data)
{
	double		zoom_factor;
	double		r_mouse;
	double		i_mouse;
	t_minmax	*minmax;

	zoom_factor = 1.0;
	minmax = &data->minmax;
	if (button == 4)
		zoom_factor = 0.9;
	else if (button == 5)
		zoom_factor = 1.1;
	else
		return (0);
	r_mouse = r_comp(x, data->width, minmax->real_min, minmax->real_max);
	i_mouse = i_comp(y, data->height, minmax->imag_min, minmax->imag_max);
	minmax->real_min = r_mouse + (minmax->real_min - r_mouse) * zoom_factor;
	minmax->real_max = r_mouse + (minmax->real_max - r_mouse) * zoom_factor;
	minmax->imag_min = i_mouse + (minmax->imag_min - i_mouse) * zoom_factor;
	minmax->imag_max = i_mouse + (minmax->imag_max - i_mouse) * zoom_factor;
	if (my_strcmp(data->name, "Julia") == 0)
		render_julia(data, data->comp, *minmax, 500);
	else
		render_mandelbrot(data, *minmax, 500);
	return (0);
}
