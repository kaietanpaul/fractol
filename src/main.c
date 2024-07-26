#include "../include/init.h"

int main(void)
{
	t_mlx_data data;	///< Reference to data struct

	data.win.color = 0xFF69B4;
	data.win.direction = 0;
	data.win.width = 600;
	data.win.height = 600;

	data.mlx_ptr = mlx_init();	///< Initiating connection
	data.win_ptr = mlx_new_window(data.mlx_ptr, data.win.width, data.win.height, "Win1");	///< Made window
	data.img.img_ptr = mlx_new_image(data.mlx_ptr, data.win.width, data.win.height);	///< Make new image
	data.img.pixel_start = mlx_get_data_addr(data.img.img_ptr, &data.img.bits_per_pixel, &data.img.line_size, &data.img.pixel_order);

	mlx_key_hook(data.win_ptr, key_event, &data);	///< Keep waiting for an event then run @fn
	mlx_loop(data.mlx_ptr);	///< Start the loop to keep the window(s) open

	return (0);
}

void my_mlx_pixel_put(const t_image_data *img_data, const int x, const int y, const int color)
{
	int pixel_location;

	pixel_location = y * img_data->line_size + x * (img_data->bits_per_pixel / 8);
	*((unsigned int *) (pixel_location + img_data->pixel_start)) = color;
}

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
	int		color;
	int		direction;
	int		line_len;
	int		width;
	int		height;
}						t_window_data;

typedef struct s_mlx_data	///< Contain basic pointer for the program
{
	void	*mlx_ptr;	///< Pointer to mlx connection
	void	*win_ptr;	///< Pointer to a window
	t_image_data	img;	///< s_image_data struct
	t_window_data	win;	///< s_window_data struct
}						t_mlx_data;