#include "../include/init.h"

/**
 * @brief Initialize the MLX library and create a new window.
 *
 * This function initializes the MLX library and creates a new window.
 * It takes a pointer to a pointer of the window address from the main function.
 *
 * @param win_ptr A pointer to a pointer that will hold the address of the new window.
 * @return A pointer to the initialized MLX instance.
 */

void *init_mlx(void **win_ptr)	///< Initialize the MLX and pass pointer to pointer of the window address from main()
{
	void	*mlx_ptr;	///< Pointer to mlx

	mlx_ptr = mlx_init();	///< Initialization at the MLX pointer
	*win_ptr = mlx_new_window(mlx_ptr, 800, 800, "F");	/**< Dereferenced ** to change the actual
*	window address from main(). Made graphical window based on initialized connection with MLX */

	return (mlx_ptr);	///Return initialized MLX
}
