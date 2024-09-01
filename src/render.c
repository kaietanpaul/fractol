#include "../include/fractol.h"

void	my_mlx_pixel_put(t_image *img, int x, int y, int color)
{
	int	pixel_location;

	pixel_location = y * img->line_size + x * (img->bits_per_pixel / 8);
	*((unsigned int *)(pixel_location + img->pixel_start)) = color;
}

void	render_mandelbrot(t_mlx *data, t_minmax minmax, int max_iter)
{
	t_complex	c;
	int			x;
	int			y;
	int			color;
	int			iter;

	y = 0;
	while (y < data->height)
	{
		x = 0;
		while (x < data->width)
		{
			c.real = r_comp(x, data->width, minmax.real_min, minmax.real_max);
			c.imag = i_comp(y, data->height, minmax.imag_min, minmax.imag_max);
			iter = mandelbrot(c, max_iter);
			if (iter == max_iter)
				color = 0xFFFF00;
			else
				color = color_gradient(data->detail, iter, max_iter, 0xFF000080);
			my_mlx_pixel_put(&data->img, x, y, color);
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(data->mlx, data->win, data->img.img, 0, 0);
}

int	mandelbrot(t_complex c, int max_iter)
{
	t_complex	z;
	int			iter;
	double		temp_real;

	iter = 0;
	z.real = 0;
	z.imag = 0;
	while (z.real * z.real + z.imag * z.imag <= 4 && iter < max_iter)
	{
		temp_real = z.real * z.real - z.imag * z.imag + c.real;
		z.imag = 2 * z.real * z.imag + c.imag;
		z.real = temp_real;
		iter++;
	}
	return (iter);
}

void	render_julia(t_mlx *data, t_complex comp, t_minmax minmax, int max_iter)
{
	t_complex	z;
	int			x;
	int			y;
	int			color;
	int			iter;

	y = 0;
	while (y < data->height)
	{
		x = 0;
		while (x < data->width)
		{
			z.real = r_comp(x, data->width, minmax.real_min, minmax.real_max);
			z.imag = i_comp(y, data->height, minmax.imag_min, minmax.imag_max);
			iter = julia(z, comp, max_iter);
			if (iter == max_iter)
				color = 0xFFFF00;
			else
				color = color_gradient(data->detail, iter, max_iter, 0xFF000080);
			my_mlx_pixel_put(&data->img, x, y, color);
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(data->mlx, data->win, data->img.img, 0, 0);
}

int	julia(t_complex z, t_complex comp, int max_iter)
{
	int		iter;
	double	temp_real;

	iter = 0;
	while (z.real * z.real + z.imag * z.imag <= 4 && iter < max_iter)
	{
		temp_real = z.real * z.real - z.imag * z.imag + comp.real;
		z.imag = 2 * z.real * z.imag + comp.imag;
		z.real = temp_real;
		iter++;
	}
	return (iter);
}
