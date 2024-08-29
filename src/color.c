#include "../include/fractol.h"

int	color_gradient(t_detail det, int iter)
{
	det.max_iter = 1000;
	det.grad_start = det.max_iter * 0.001;
	det.grad_end = det.max_iter * 0.045;
	det.start_color = 0xFF000080;
	det.end_color = 0xFFFFFFFF;
	det.t = (iter - det.grad_start) / (det.grad_end - det.grad_start);
	if (det.t < 0)
		det.t = 0;
	if (det.t > 1)
		det.t = 1;
	det.start_red = (det.start_color >> 16) & 0xFF;
	det.start_green = (det.start_color >> 8) & 0xFF;
	det.start_blue = det.start_color & 0xFF;
	det.end_red = (det.end_color >> 16) & 0xFF;
	det.end_green = (det.end_color >> 8) & 0xFF;
	det.end_blue = det.end_color & 0xFF;
	det.red = (int)((1 - det.t) * det.start_red + det.t * det.end_red);
	det.green = (int)((1 - det.t) * det.start_green + det.t * det.end_green);
	det.blue = (int)((1 - det.t) * det.start_blue + det.t * det.end_blue);
	return ((det.red << 16) | (det.green << 8) | det.blue);
}
