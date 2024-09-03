/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpaul <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/03 16:53:44 by kpaul             #+#    #+#             */
/*   Updated: 2024/09/03 16:53:46 by kpaul            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

int	color_gradient(t_detail det, int iter, int max_iter, int start_color)
{
	det.scaled_iter = (double)iter / max_iter;
	det.t = pow(det.scaled_iter, 0.3);
	det.end_color = 0xFFFFFFFF;
	det.start_red = (start_color >> 16) & 0xFF;
	det.start_green = (start_color >> 8) & 0xFF;
	det.start_blue = start_color & 0xFF;
	det.end_red = (det.end_color >> 16) & 0xFF;
	det.end_green = (det.end_color >> 8) & 0xFF;
	det.end_blue = det.end_color & 0xFF;
	det.red = (int)((1 - det.t) * det.start_red + det.t * det.end_red);
	det.green = (int)((1 - det.t) * det.start_green + det.t * det.end_green);
	det.blue = (int)((1 - det.t) * det.start_blue + det.t * det.end_blue);
	if (iter >= max_iter * 0.99)
	{
		det.red = det.red * (1 - det.scaled_iter) + 30 * det.scaled_iter;
		det.green = det.green * (1 - det.scaled_iter) + 30 * det.scaled_iter;
		det.blue = det.blue * (1 - det.scaled_iter) + 30 * det.scaled_iter;
		if (iter == max_iter)
		{
			det.red = 15;
			det.green = 15;
			det.blue = 15;
		}
	}
	return ((det.red << 16) | (det.green << 8) | det.blue);
}
