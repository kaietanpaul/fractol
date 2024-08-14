#include "../include/fractol.h"

double	scale(double num, double old_min, double old_max, double new_min, double new_max)
{
	return ((new_max - new_min) * (num - old_min) / (old_max - old_min) + new_min);
}
int 	square(int num)
{
	return (num * num);
}