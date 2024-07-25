#include "../include/init.h"

/**
 * @brief The main function of the program.
 *
 * This function initializes the MLX library, creates a new window, and starts the MLX loop.
 * It serves as the entry point of the program.
 *
 * @return Exit status.
 */


//int main()
//{
//    t_data *data;
//
//	data = init_mlx();
//    if (!data)
//		return (1);	/// Initialization failed
//
//    make_line(data->mlx_ptr, data->win_ptr, 100, 200, 200, 0, 0xFF69B4);
//    mlx_loop(data->mlx_ptr);
//
//    return 0;
//}

typedef struct	s_image_data
{
	void	*img_ptr;        ///< Pointer to the image object
	char	*pixel_start;     ///< Pointer to the first pixel (start of pixel data)
	int		bits_per_pixel;    ///< Number of bits used for each pixel
	int		line_size;         ///< Size in bytes of one row of the image
	int		pixel_order;       ///< Endianness of pixel data, 0 for little endian, 1 for big endian
}						t_image_data;

typedef struct s_mlx_data	///< Contain basic pointer for the program
{
	void	*mlx_ptr;	///< Pointer to mlx connection
	void	*win_ptr;	///< Pointer to a window
	int		color;
	int		direction;
	int		size;	///< Both x and y sizes
	t_image_data img;	///< s_image_data struct
}						t_mlx_data;

void my_mlx_pixel_put(const t_image_data *img_data, const int x, const int y, const int color)
{
	int pixel_location;

	pixel_location = y * img_data->line_size + x * (img_data->bits_per_pixel / 8);
	*((unsigned int *) (pixel_location + img_data->pixel_start)) = color;
}

void	screen_color(t_mlx_data *data, const int color)
{
	int	x = 0;
	int	y = 0;
	data->color = color;
	while (y < data->size)
	{
		while (x < data->size)
		{
			my_mlx_pixel_put(&data->img, x, y, color);
			x++;
		}
		x = 0;
		y++;
	}
}
int	key_event(const int keysym, t_mlx_data *data)
{
	if (keysym == XK_Escape)	///< Clear and Exit the window
	{
		printf("Keycode:%d  Esc was clicked\n\n", keysym);
		mlx_destroy_image(data->mlx_ptr, data->img.img_ptr);	///< Destroy image
		mlx_destroy_window(data->mlx_ptr, data->win_ptr);	///< Destroy window
		mlx_destroy_display(data->mlx_ptr);	/// Destroy connection
		free(data->mlx_ptr);
		exit(1);
	}
	if (keysym == XK_space)	///< Draw a line of different color each time with different direction
	{
		data->direction++;
		if (data->direction == 4)
			data->direction = 0;
		printf("Keycode:%d\nSpace was clicked\n\n", keysym);
		if (data->color == 0xFF69B4)
			data->color = 0x98FF98;
		else if (data->color == 0x98FF98)
			data->color = 0x8A2BE2;
		else
			data->color = 0xFF69B4;
		make_line(data->mlx_ptr, data->win_ptr, 100, 250, 250, data->direction, data->color);	///< Made line
	}
	else if (keysym == XK_BackSpace)	///< Clear window on backspace
	{
		mlx_destroy_image(data->mlx_ptr, data->img.img_ptr);
		data->img.img_ptr = mlx_new_image(data->mlx_ptr, data->size, data->size);
		printf("Keycode:%d\nBackspace was clicked\n\n", keysym);
	}
	else if (keysym == XK_r)	///< Change background color
	{
		screen_color(data, 0xFFFF0000);
		printf("Keycode:%d\nR was clicked\n\n", keysym);

	}
	else if (keysym == XK_g)
	{
		screen_color(data, 0xFF00FF00);
		printf("Keycode:%d\nG was clicked\n\n", keysym);
	}
	else if (keysym == XK_b)
	{
		screen_color(data, 0xFF0000FF);
		printf("Keycode:%d\nB was clicked\n\n", keysym);
	}
	else
		printf("Keycode:%d\nKey was clicked\n\n", keysym);
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->img.img_ptr, 0, 0);
	return (0);
}

int main(void)
{
	t_mlx_data data;	///< Reference to data struct

	data.color = 0xFF69B4;
	data.direction = 0;
	data.size = 600;

	data.mlx_ptr = mlx_init();	///< Initiating connection
	data.win_ptr = mlx_new_window(data.mlx_ptr, data.size, data.size, "Win1");	///< Made window
	data.img.img_ptr = mlx_new_image(data.mlx_ptr, data.size, data.size);	///< Make new image
	data.img.pixel_start = mlx_get_data_addr(data.img.img_ptr, &data.img.bits_per_pixel, &data.img.line_size, &data.img.pixel_order);

	mlx_key_hook(data.win_ptr, key_event, &data);	///< Keep waiting for an event then run @fn
	mlx_loop(data.mlx_ptr);	///< Start the loop to keep the window(s) open

	return (0);
}
