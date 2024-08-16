#include "../include/fractol.h"
int main(void)
{
	t_mlx *data = NULL;

	data = init_mlx_win_img(data, 500, 300, "Fractol");	///< Init mlx and window
	render_mandelbrot(data, -2, 0.47, -1.12, 1.12, 2000);

	mlx_key_hook(data->win_ptr, key_event, data);	///< Key hook the events
	mlx_loop(data->mlx_ptr);	///< Loop the entire thing

	return (0);
}