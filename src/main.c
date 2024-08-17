#include "../include/fractol.h"
int main(void)
{
	t_mlx *data = NULL;
	t_minmax minmax= {-1.8, 0.6, -1.12, 1.12};

	data = init_mlx_win_img(data, 500, 300, ".0001 x .045");	///< Init mlx and window
	render_mandelbrot(data, minmax, 500);

	mlx_key_hook(data->win_ptr, key_event, data);	///< Key hook the events
	mlx_mouse_hook(data->win_ptr, key_event, data);
	mlx_loop(data->mlx_ptr);	///< Loop the entire thing

	return (0);
}