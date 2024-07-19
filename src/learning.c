#include "../include/init.h"

void	square_full(void *mlx_ptr, void *win_ptr)
{
	int i = 0; ///< Loop index for rows
	int j = 0; ///< Loop index for columns

	int x = 400;	///< X-coordinate of the top-left corner of the square
	int y = 400;	///< Y-coordinate of the top-left corner of the square
	int color = 0xFF69B4;

	while (i < 100)	///< Move horizontal line drawing up
	{
		while (j < 100)	///< Draw horizontal line
		{
			mlx_pixel_put(mlx_ptr, win_ptr, x + j, y - i, color);	///< Draw a pixel
			j++;
		}
		j = 0;	///< Reset needed for next horizontal line
		i++;
	}
}

void	square_outline(void *mlx_ptr, void *win_ptr)
{
	int i = 0; ///< Loop index for both rows and columns

	int x = 400;	///< X-coordinate of the top-left corner of the square
	int y = 400;	///< Y-coordinate of the top-left corner of the square
	int color = 0xFF69B4;

	while (i < 100)
	{
		mlx_pixel_put(mlx_ptr, win_ptr, x, y - i, color);			///< Left line
		mlx_pixel_put(mlx_ptr, win_ptr, x + 99, y - i, color);	///< Right line
		mlx_pixel_put(mlx_ptr, win_ptr, x + i, y, color);			///< Bottom line
		mlx_pixel_put(mlx_ptr, win_ptr, x + i, y - 99, color);	///< Upper line
		i++;
	}
}