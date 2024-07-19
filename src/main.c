#include "../include/init.h"

/**
 * @brief The main function of the program.
 *
 * This function initializes the MLX library, creates a new window, and starts the MLX loop.
 * It serves as the entry point of the program.
 *
 * @return Exit status.
 */

int	main()
{
    void	*mlx_ptr;	///< MLX instance ptr
    void	*win_ptr;	///< Window instance ptr

    mlx_ptr = init_mlx(&win_ptr);	///< Initialize MLX, create a new window

//	square_full(mlx_ptr, win_ptr);	///< Use @fn mlx_pixel_put() to draw a square
	square_outline(mlx_ptr, win_ptr);
    mlx_loop(mlx_ptr);	///< Start the MLX loop

    return (0);
}

