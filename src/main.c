#include "../include/init.h"

int main(void)
{
	t_mlx_data data;	///< Reference to data struct

	data.color = 0xFF69B4;
	data.size = 600;

	data.mlx_ptr = mlx_init();	///< Initiating connection
	data.win_ptr = mlx_new_window(data.mlx_ptr, data.size, data.size, "Win1");	///< Made window
	data.img.img_ptr = mlx_new_image(data.mlx_ptr, data.size, data.size);	///< Make new image
	data.img.pixel_start = mlx_get_data_addr(data.img.img_ptr, &data.img.bits_per_pixel, &data.img.line_size, &data.img.pixel_order);

	mlx_key_hook(data.win_ptr, key_event, &data);	///< Keep waiting for an event then run @fn
	mlx_loop(data.mlx_ptr);	///< Start the loop to keep the window(s) open

	return (0);
}
