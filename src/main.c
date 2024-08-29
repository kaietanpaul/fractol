#include "../include/fractol.h"

int main(int argc, char **argv)
{
	t_mlx *data = NULL;
	t_minmax minmax = {-1.8, 0.6, -1.12, 1.12};
	t_complex julia_const = {1.285, 1.01};  // Example Julia constant, can be passed via arguments

	data = init_mlx_win_img(data, 500, 500, "Fractol");  ///< Init mlx and window

	if (argc > 1 && strcmp(argv[1], "julia") == 0)
	{
		data->name = "Julia";
		render_julia(data, julia_const, minmax, 1000);
	}
	else
	{
		data->name = "Mandelbrot";
		render_mandelbrot(data, minmax, 1000);
	}

	mlx_key_hook(data->win_ptr, key_event, data);  ///< Key hook the events
	mlx_mouse_hook(data->win_ptr, mouse_event, data);
	mlx_loop(data->mlx_ptr);  ///< Loop the entire thing

	return (0);
}