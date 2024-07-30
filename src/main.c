#include "../include/fractol.h"

//int main(void)
//{
//	printf("\n\n%f\n\n", sqrt(2));
//	return (0);
//}
int main(void)
{
	t_mlx *data = NULL;

	data = init_mlx_and_window(data, 500, 500, "Fractol");	///< Init mlx and window

	init_image(data);	///< Init the image

	mlx_key_hook(data->win_ptr, key_event, data);	///< Key hook the events
	mlx_loop(data->mlx_ptr);	///< Loop the entire thing

	return (0);
}