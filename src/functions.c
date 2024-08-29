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

void render_julia(t_mlx *data, t_complex julia_const, t_minmax minmax, int max_iter)
{
	t_complex z;
	int x = 0;
	int	y = 0;
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
			z.real = real_complex(x, data->width, minmax.real_min, minmax.real_max);
			z.imag = imag_complex(y, data->height, minmax.imag_min, minmax.imag_max);
			iter = julia(z, julia_const, max_iter);

			if (iter == max_iter)
			{
				color = 0x00000000;  // Black for points inside the Julia set
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

int julia(t_complex z, t_complex julia_const, int max_iter)
{
	int iter = 0;

	while (z.real * z.real + z.imag * z.imag <= 4 && iter < max_iter)
	{
		double temp_real = z.real * z.real - z.imag * z.imag + julia_const.real;
		z.imag = 2 * z.real * z.imag + julia_const.imag;
		z.real = temp_real;
		iter++;
	}
	return iter;
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

int mouse_event(int button, int x, int y, t_mlx *data)
{
	printf("Mouse event: button=%d, x=%d, y=%d\n", button, x, y);
	double zoom_factor = 1.1;
	t_minmax *minmax = &data->minmax;
	double real_range = (minmax->real_max - minmax->real_min) / 2.0;
	double imag_range = (minmax->imag_max - minmax->imag_min) / 2.0;
	double real_center = minmax->real_min + real_range;
	double imag_center = minmax->imag_min + imag_range;

	if (button == 4)  // Scroll up (zoom in)
	{
		zoom_factor = 1.0 / zoom_factor;
	}
	else if (button == 5)  // Scroll down (zoom out)
	{
		zoom_factor = 1.1;
	}
	else
	{
		return (0);  // If it's not scroll up or down, do nothing
	}

	double real_mouse = real_complex(x, data->width, minmax->real_min, minmax->real_max);
	double imag_mouse = imag_complex(y, data->height, minmax->imag_min, minmax->imag_max);

	minmax->real_min = real_mouse + (minmax->real_min - real_mouse) * zoom_factor;
	minmax->real_max = real_mouse + (minmax->real_max - real_mouse) * zoom_factor;
	minmax->imag_min = imag_mouse + (minmax->imag_min - imag_mouse) * zoom_factor;
	minmax->imag_max = imag_mouse + (minmax->imag_max - imag_mouse) * zoom_factor;

	if (strcmp(data->name, "Mandelbrot") == 0)
		render_mandelbrot(data, *minmax, 1000);
	else if (strcmp(data->name, "Julia") == 0)
		render_julia(data, data->julia_const, *minmax, 1000);
	return (0);
}
