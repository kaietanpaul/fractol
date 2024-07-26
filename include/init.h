#ifndef INIT_H
#define INIT_H

# include "../minilibx-linux/mlx.h"	///< MLX library
# include <math.h>	///< Will use it for mathematical functions
# include <X11/keysym.h>	///< Key code library

# include <stdio.h>	///< Will use it for bugs search
# include <unistd.h>	///< Will use it for bugs search
# include <stdlib.h>	///< Will use it for free function and valgrind check

	/// Structures
typedef struct	s_image_data
{
	void	*img_ptr;        ///< Pointer to the image object
	char	*pixel_start;     ///< Pointer to the first pixel (start of pixel data)
	int		bits_per_pixel;    ///< Number of bits used for each pixel
	int		line_size;         ///< Size in bytes of one row of the image
	int		pixel_order;       ///< Endianness of pixel data, 0 for little endian, 1 for big endian
}						t_image_data;

typedef struct s_window_data
{
	char	*title;
	int		width;
	int		height;
	int		color;
	int		direction;
	int		line_len;
}						t_window_data;

typedef struct s_mlx_data	///< Contain basic pointer for the program
{
	void	*mlx_ptr;	///< Pointer to mlx connection
	void	*win_ptr;	///< Pointer to a window
	t_image_data	img;	///< s_image_data struct
	t_window_data	win;	///< s_window_data struct
}						t_mlx_data;


	/// Main functions
t_mlx_data	*init_mlx_and_window();	///< Initialize the MLX library

	/// TODO Additional functions
void		my_mlx_pixel_put(t_image_data *img_data, int x, int y, int color);

int			key_event(int keysym, t_mlx_data *data);

	/// Learning functions

void		make_line(t_mlx_data *data, t_image_data *img, t_window_data *win);



#endif