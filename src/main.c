#include "../include/fractol.h"

int main(int argc, char **argv)
{
	t_mlx *data = NULL;
	t_minmax minmax = {-1.8, 0.6, -1.12, 1.12};
	t_complex julia_const = {1.285, 1.01};  // Example Julia constant, can be passed via arguments

	data = init_mlx_win_img(data, 1000, 800, ".0001 x .045");  ///< Init mlx and window

	if (argc > 1 && strcmp(argv[1], "julia") == 0)
	{
		render_julia(data, julia_const, minmax, 500);
	}
	else
	{
		render_mandelbrot(data, minmax, 10);
	}

	mlx_key_hook(data->win_ptr, key_event, data);  ///< Key hook the events
	mlx_mouse_hook(data->win_ptr, mouse_event, data);
	mlx_loop(data->mlx_ptr);  ///< Loop the entire thing

	return (0);
}