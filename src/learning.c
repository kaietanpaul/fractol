#include "../include/init.h"

void	square_full(void *mlx_ptr, void *win_ptr)
{
	int i = 0; ///< Loop index for rows
	int j = 0; ///< Loop index for columns

	int x = 200;	///< X-coordinate
	int y = 200;	///< Y-coordinate
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

	int x = 400;	///< X-coordinate
	int y = 400;	///< Y-coordinate
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
void	spiral_square(void *mlx_ptr, void *win_ptr)
{
	int	i = 0;
	int	i_x = 0;
	int	i_y = 0;
	int	moved_right_up = 1;
	int	moved_left_down = 0;

	int x = 250;	///< X-coordinate
	int y = 250;	///< Y-coordinate
	int color = 0xFF69B4;

	while (i < 100)	///< Change i 100x
	{
		if (moved_right_up)
		{
			moved_right_up = 0;
			moved_left_down = 1;
			while (i_x < i)	///< Put pixel on Xy until @param i
			{
				x += i_x;
				mlx_pixel_put(mlx_ptr, win_ptr, x, y, color);
				i_x++;
			}
		}
		if (moved_left_down)
		{
			moved_left_down = 0;
			moved_right_up = 1;
			
		}

		i++;
	}
}