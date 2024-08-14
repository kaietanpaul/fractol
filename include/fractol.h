#ifndef INIT_H
# define INIT_H
# include "../minilibx-linux/mlx.h"
# include <math.h>
# include <X11/keysym.h>
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>

///< Struct to hold image-related data
typedef struct s_image
{
	void	*img_ptr;			///< Pointer to the image object
	char	*pixel_start;		///< Pointer to the first pixel (start of pixel data)
	int		bits_per_pixel;		///< Number of bits used for each pixel
	int		line_size;			///< Size in bytes of one row of the image
	int		pixel_order;		///< Endianness of pixel data, 0 for little endian, 1 for big endian
}							t_image;
///< Struct to hold overall program data
typedef struct s_mlx
{
	void	*mlx_ptr;			///< Pointer to MLX connection
	void	*win_ptr;			///< Pointer to a window
	char 	*name;
	int		width;
	int 	height;
	t_image	img;		///< Image data structure
}							t_mlx;
t_mlx		*init_mlx_win_img(t_mlx *data, int x, int y, char *title);
//void		init_image(t_mlx *data); TODO delete?;
int			key_event(int keysym, t_mlx *data);
//double		scale(double num, double old_min, double old_max, double new_min, double new_max);
//int 		square(int num);
#endif