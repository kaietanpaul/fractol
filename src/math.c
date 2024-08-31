#include "../include/fractol.h"

double	scale(double num, double old_max, double new_min, double new_max)
{
	return ((new_max - new_min) * (num - 0) / (old_max - 0) + new_min);
}

double	r_comp(int x, int width, double real_min, double real_max)
{
	return (scale(x, 0, width, real_min, real_max));
}

double	i_comp(int y, int height, double imag_min, double imag_max)
{
	return (scale(y, 0, height, imag_min, imag_max));
}
