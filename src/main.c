#include "../include/init.h"

/**
 * @brief The main function of the program.
 *
 * This function initializes the MLX library, creates a new window, and starts the MLX loop.
 * It serves as the entry point of the program.
 *
 * @return Exit status.
 */

void	make_square(void *mlx_ptr, void *win_ptr)
{
	int	i = 0;
	int j = 0;

	int	x = 400;
	int	y = 400;
	int	color = 0xFF8001AA;

	while (i < 100)
	{
		mlx_pixel_put(mlx_ptr, win_ptr, x, y, color);
		y--;
		x++;
		i++;
	}
}

int	main()
{
	#if 0
		printf("lalalal");
	#endif

    void	*mlx_ptr;	///< Pointer to the MLX instance
    void	*win_ptr;	///< Pointer to the window instance

    mlx_ptr = init_mlx(&win_ptr);	///< Initialize MLX and create a new window

	make_square(mlx_ptr, win_ptr);

    mlx_loop(mlx_ptr);	///< Start the MLX loop


    return (0);
}

