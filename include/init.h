#ifndef INIT_H
#define INIT_H

# include "../minilibx-linux/mlx.h"
# include <math.h>
# include <X11/keysym.h>
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>

///< Struct to hold image-related data
typedef struct s_image_data
{
	void	*img_ptr;            ///< Pointer to the image object
	char	*pixel_start;        ///< Pointer to the first pixel (start of pixel data)
	int		bits_per_pixel;       ///< Number of bits used for each pixel
	int		line_size;            ///< Size in bytes of one row of the image
	int		pixel_order;          ///< Endianness of pixel data, 0 for little endian, 1 for big endian
}							t_image_data;

///< Struct to hold overall program data
typedef struct s_mlx_data
{
	void	*mlx_ptr;            ///< Pointer to MLX connection
	void	*win_ptr;            ///< Pointer to a window
	int		size;
	int		color;
	t_image_data	img;         ///< Image data structure
}							t_mlx_data;

	///< Main functions
t_mlx_data	*init_mlx_and_window(int width, int height, char *title);

void	my_mlx_pixel_put(t_image_data *img, int x, int y, int color);

	///< Additional functions
void	screen_color(t_mlx_data *data, int color);
int		key_event(int keysym, t_mlx_data *data);


#endif
