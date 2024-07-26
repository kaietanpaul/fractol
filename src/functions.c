#include "../include/init.h"

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
	data->win.color = color;
	while (y < data->win.height)
	{
		while (x < data->win.width)
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
		data->win.direction++;
		if (data->win.direction == 4)
			data->win.direction = 0;
		printf("Keycode:%d\nSpace was clicked\n\n", keysym);
		if (data->win.color == 0xFF69B4)
			data->win.color = 0x98FF98;
		else if (data->win.color == 0x98FF98)
			data->win.color = 0x8A2BE2;
		else
			data->win.color = 0xFF69B4;
		make_line(data->mlx_ptr, data->win_ptr, 100, 250, 250, data->win.direction, data->win.color);	///< Made line
	}
	else if (keysym == XK_BackSpace)	///< Clear window on backspace
	{
		mlx_destroy_image(data->mlx_ptr, data->img.img_ptr);
		data->img.img_ptr = mlx_new_image(data->mlx_ptr, data->win.width, data->win.height);
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


