#include "../include/init.h"

/**
 * @brief The main function of the program.
 *
 * This function initializes the MLX library, creates a new window, and starts the MLX loop.
 * It serves as the entry point of the program.
 *
 * @return Exit status.
 */

int	main() /// Will use struct s_data
{
	t_data	data;	///< Data structure
	t_image	image;	///< Image structure

	data.mlx_ptr = mlx_init();	///< Initialize the MLX
	data.win_ptr = mlx_new_window(data.mlx_ptr, 500, 500, "F");	///< Create a new window6

	image.img_ptr = mlx_new_image(data.mlx_ptr, 500, 500);	///< Create a new image
	image.addr = mlx_get_data_addr(image.img_ptr, &image.bits_per_pixel, &image.size_line, &image.endian);	///< Get the image address

	square_full(data.mlx_ptr, data.win_ptr);	///< Draw a filled square FIXME: Do not work standalone | FIXME: Combine with image not data structure
	square_outline(data.mlx_ptr, data.win_ptr);	///< Draw a square outline FIXME: Do not work standalone | FIXME: Combine with image not data structure
	spiral_squary(data.mlx_ptr, data.win_ptr);	///< Draw square pixels into a spiral FIXME: Without this function, other functions do not work | FIXME: Combine with image not data structure

	mlx_put_image_to_window(data.mlx_ptr, data.win_ptr, image.img_ptr, 0, 0);	///< Put the image to the window FIXME: Image is not visible after few seconds
	mlx_loop(data.mlx_ptr);	///< Start the MLX loop

	return (0);	///< Exit status
}

