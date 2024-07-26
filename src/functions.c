#include "../include/init.h"

void	my_mlx_pixel_put(t_image_data *img, int x, int y, int color)
{
	int pixel_location;

	pixel_location = y * img->line_size + x * (img->bits_per_pixel / 8);
	*((unsigned int *) (pixel_location + img->pixel_start)) = color;
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
	if (keysym == XK_BackSpace)	///< Clear window on backspace
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


