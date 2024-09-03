/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpaul <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/03 16:54:09 by kpaul             #+#    #+#             */
/*   Updated: 2024/09/03 16:54:11 by kpaul            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

int	main(int argc, char **argv)
{
	t_mlx	*data;

	data = NULL;
	data = init_mlx_win_img(data, 500, 500, "Fractol");
	if (argc == 4 && my_strcmp(argv[1], "Julia") == 0)
	{
		data->name = "Julia";
		if (is_float(argv[2]) && is_float(argv[3]))
		{
			data->comp.real = my_atof(argv[2]);
			data->comp.imag = my_atof(argv[3]);
			render_julia(data, data->comp, data->minmax, 500);
		}
		else
			perror_exit("NOPE\n\tTry with two float numbers\n", data);
	}
	else if (argc > 1 && my_strcmp(argv[1], "Mandelbrot") == 0)
		render_mandelbrot(data, data->minmax, 500);
	else
		perror_exit("NOPE\n\tTry \"Mandelbrot\" or \"Julia 0.3 0.3\"\n", data);
	mlx_key_hook(data->win, key_event, data);
	mlx_mouse_hook(data->win, mouse_event, data);
	mlx_hook(data->win, 17, 0, clean_exit, data);
	mlx_loop(data->mlx);
	return (0);
}
///< TODO: write str function							<-- DONE
///< TODO: fix Julia reset on zoom						<-- DONE
///< TODO: write atof & check_if_float					<-- DONE
///< TODO: add my printf								<-- DONE
///< TODO: delete all forbidden libraries and functions	<-- DONE
///< TODO: close on x button							<-- DONE
///< TODO: norminette all files
