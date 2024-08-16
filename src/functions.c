#include "../include/fractol.h"

void	my_mlx_pixel_put(t_image *img, int x, int y, int color)
{
	int pixel_location;

	pixel_location = y * img->line_size + x * (img->bits_per_pixel / 8);
	*((unsigned int *) (pixel_location + img->pixel_start)) = color;
}

void render_mandelbrot(t_mlx *data, double real_min, double real_max, double imag_min, double imag_max, int max_iter)
{
	t_complex c;
	int x, y;
	int color;
	int iter;
	double t;

	for (y = 0; y < data->height; y++)
	{
		for (x = 0; x < data->width; x++)
		{
			c.real = real_complex(x, data->width, real_min, real_max);
			c.imag = imag_complex(y, data->height, imag_min, imag_max);
			iter = mandelbrot(c, max_iter);

			if (iter < max_iter)
			{
				// Normalize the iteration count to a value between 0 and 1
				t = 1.0 - (double)iter / (double)max_iter; // Reversing the gradient

				// Create a reversed gradient with color depth
				color = (int)(9 * (1 - t) * t * t * t * 255) << 16 |  // Red component
						(int)(15 * (1 - t) * (1 - t) * t * t * 255) << 8 |  // Green component
						(int)(8.5 * (1 - t) * (1 - t) * (1 - t) * t * 255); // Blue component
			}
			else
			{
				color = 0x00000000;  // Black color for points inside the set
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
