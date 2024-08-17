#include "../include/fractol.h"

void	my_mlx_pixel_put(t_image *img, int x, int y, int color)
{
	int pixel_location;

	pixel_location = y * img->line_size + x * (img->bits_per_pixel / 8);
	*((unsigned int *) (pixel_location + img->pixel_start)) = color;
}

void render_mandelbrot(t_mlx *data, t_minmax minmax, int max_iter)
{
	t_complex c;
	int x, y;
	int color;
	int iter;

	// Define the range of the gradient
	double gradient_start = max_iter * 0.001;  // When to start the gradient
	double gradient_end = max_iter * 0.045;      // When to end the gradient

	// Define the start and end colors of the gradient
	int start_color = 0xFF000080;  // Dark blue
	int end_color = 0xFFFFFFFF;    // White

	for (y = 0; y < data->height; y++)
	{
		for (x = 0; x < data->width; x++)
		{
			c.real = real_complex(x, data->width, minmax.real_min, minmax.real_max);
			c.imag = imag_complex(y, data->height, minmax.imag_min, minmax.imag_max);
			iter = mandelbrot(c, max_iter);

			if (iter == max_iter)
			{
				color = 0x00000000;  // Black for points inside the Mandelbrot set
			}
			else
			{
				// Calculate the interpolation factor 't' between 0 and 1
				double t = (iter - gradient_start) / (gradient_end - gradient_start);
				if (t < 0) t = 0;
				if (t > 1) t = 1;

				// Interpolate between start_color and end_color
				int start_red = (start_color >> 16) & 0xFF;
				int start_green = (start_color >> 8) & 0xFF;
				int start_blue = start_color & 0xFF;

				int end_red = (end_color >> 16) & 0xFF;
				int end_green = (end_color >> 8) & 0xFF;
				int end_blue = end_color & 0xFF;

				int red = (int)((1 - t) * start_red + t * end_red);
				int green = (int)((1 - t) * start_green + t * end_green);
				int blue = (int)((1 - t) * start_blue + t * end_blue);

				color = (red << 16) | (green << 8) | blue;
			}

			my_mlx_pixel_put(&data->img, x, y, color);
		}
	}
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->img.img_ptr, 0, 0);
}


int		mandelbrot(t_complex c, int max_iter)
{
	t_complex z;
	z.real = 0;
	z.imag = 0;
	int iter = 0;

	while (z.real * z.real + z.imag * z.imag <= 4 && iter < max_iter)
	{
		double temp_real = z.real * z.real - z.imag * z.imag + c.real;
		z.imag = 2 * z.real * z.imag + c.imag;
		z.real = temp_real;
		iter++;
	}
	return (iter);
}


void	screen_color(t_mlx *data, const int color)
{
	int	x = 0;
	int	y = 0;
	while (y < data->height)
	{
		while (x < data->width)
		{
			my_mlx_pixel_put(&data->img, x, y, color);
			x++;
		}
		x = 0;
		y++;
	}
}

//int mouse_event(int button, int x, int y, t_mlx *data)
//{
//	if (button == SCROLL_UP) // Define SCROLL_UP based on your system
//	{
//		printf("up was clicked\n\n");
////		zoom(&data->bounds, 0.9, x, y, data->width, data->height); // Zoom in
//	}
//	else if (button == SCROLL_DOWN) // Define SCROLL_DOWN based on your system
//	{
//		printf("down was clicked\n\n");
////		zoom(&data->bounds, 1.1, x, y, data->width, data->height); // Zoom out
//	}
////	render_mandelbrot(data, data->bounds, 1000);
//	return (0);
//}

int		key_event(int keysym, t_mlx *data)
{
	if (keysym == XK_Escape)	///< Clear and Exit the window
	{
		printf("Esc was clicked\n\n");
		mlx_destroy_image(data->mlx_ptr, data->img.img_ptr);	///< Destroy image
		mlx_destroy_window(data->mlx_ptr, data->win_ptr);	///< Destroy window
		mlx_destroy_display(data->mlx_ptr);	/// Destroy connection
		free(data->mlx_ptr);
		free(data);
		exit(1);
	}
	if (keysym == XK_BackSpace)	///< Clear window on backspace
	{
		mlx_destroy_image(data->mlx_ptr, data->img.img_ptr);
		data->img.img_ptr = mlx_new_image(data->mlx_ptr, data->width, data->height);
		printf("Backspace was clicked\n\n");
	}
	else if (keysym == XK_r)	///< Change background color
	{
		screen_color(data, (int)0xFFFF0000);
		printf("R was clicked\n\n");

	}
	else if (keysym == XK_g)
	{
		screen_color(data, (int)0xFF00FF00);
		printf("G was clicked\n\n");
	}
	else if (keysym == XK_b)
	{
		screen_color(data, (int)0xFF0000FF);
		printf("B was clicked\n\n");
	}
	else
		printf("Keycode:%d\nKey was clicked\n\n", keysym);
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->img.img_ptr, 0, 0);
	return (0);
}
