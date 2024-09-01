#include "../include/fractol.h"

int main(int argc, char **argv)
{
	t_mlx *data = NULL;

	data = init_mlx_win_img(data, 500, 500, "Fractol");  ///< Init mlx and window

	if (argc > 1 && my_strcmp(argv[1], "Julia") == 0)
	{
		data->name = "Julia";
		if (argc == 4)
		{
			if (is_float(argv[2]) && is_float(argv[3]))
			{
				data->comp.real = my_atof(argv[2]);
				data->comp.imag = my_atof(argv[3]);
			}
			// else
		}

		render_julia(data, data->comp, data->minmax, 2000);
	}
	else
	{
		data->name = "Mandelbrot";
		render_mandelbrot(data, data->minmax, 1000);
	}

	mlx_key_hook(data->win, key_event, data);  ///< Key hook the events
	mlx_mouse_hook(data->win, mouse_event, data);
	mlx_loop(data->mlx);  ///< Loop the entire thing

	return (0);
}
///< TODO: write str function		<-- DONE
///< TODO: fix Julia reset on zoom		<-- DONE
///< TODO: write atof & check_if_float	<-- DONE
///< TODO: add my printf
///< TODO: delete all forbidden libraries and functions
///< TODO: close on x button
