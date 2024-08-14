#include "../include/fractol.h"
int main(void)
{
	t_mlx *data = NULL;

	data = init_mlx_win_img(data, 500, 500, "Fractol");	///< Init mlx and window


	mlx_key_hook(data->win_ptr, key_event, data);	///< Key hook the events
	mlx_loop(data->mlx_ptr);	///< Loop the entire thing

	return (0);
}