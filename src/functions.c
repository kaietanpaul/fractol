#include "../include/fractol.h"

int		key_event(int keysym, t_mlx *data)
{
	if (keysym == XK_Escape)	///< Clear and Exit the window
	{
		printf("Esc was clicked\n\n");
		mlx_destroy_image(data->mlx, data->img.img);	///< Destroy image
		mlx_destroy_window(data->mlx, data->win);	///< Destroy window
		mlx_destroy_display(data->mlx);	/// Destroy connection
		free(data->mlx);
		free(data);
		exit(1);
	}
	if (keysym == XK_BackSpace)	///< Clear window on backspace
	{
		mlx_destroy_image(data->mlx, data->img.img);
		data->img.img = mlx_new_image(data->mlx, data->width, data->height);
		printf("Backspace was clicked\n\n");
	}
	else
		printf("Keycode:%d\nKey was clicked\n\n", keysym);
	mlx_put_image_to_window(data->mlx, data->win, data->img.img, 0, 0);
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

	double real_mouse = r_comp(x, data->width, minmax->real_min, minmax->real_max);
	double imag_mouse = i_comp(y, data->height, minmax->imag_min, minmax->imag_max);

	minmax->real_min = real_mouse + (minmax->real_min - real_mouse) * zoom_factor;
	minmax->real_max = real_mouse + (minmax->real_max - real_mouse) * zoom_factor;
	minmax->imag_min = imag_mouse + (minmax->imag_min - imag_mouse) * zoom_factor;
	minmax->imag_max = imag_mouse + (minmax->imag_max - imag_mouse) * zoom_factor;

	if (strcmp(data->name, "Mandelbrot") == 0)
		render_mandelbrot(data, *minmax, 1000);
	else if (strcmp(data->name, "Julia") == 0)
		render_julia(data, data->comp, *minmax, 1000);
	return (0);
}
