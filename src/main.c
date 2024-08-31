#include "../include/fractol.h"
#include <stdlib.h>  // For atof

int main(int argc, char **argv)
{
	t_mlx *data = NULL;

	data = init_mlx_win_img(data, 500, 500, "Fractol");  ///< Init mlx and window

	if (argc > 1 && strcmp(argv[1], "Julia") == 0)
	{
		data->name = "Julia";

		// Check if additional arguments are provided for Julia set
		if (argc == 4)
		{
			data->comp.real = atof(argv[2]);
			data->comp.imag = atof(argv[3]);
		}

		render_julia(data, data->comp, data->minmax, 1000);
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
///< TODO: write str function
///< TODO: delete all forbidden libraries and functions
///< TODO: close on x button
///< TODO: fix Julia reset on zoom		<-- DONE
///< TODO: write atof & check_if_float