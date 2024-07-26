#include "../include/init.h"

t_mlx_data	*init_mlx_and_window(int width, int height, char *title)
{
	t_mlx_data *data = malloc(sizeof(t_mlx_data));
	if (!data)
		return (NULL);

	data->mlx_ptr = mlx_init();
	if (!data->mlx_ptr)
	{
		free(data);
		return (NULL);
	}

	data->win_ptr = mlx_new_window(data->mlx_ptr, width, height, title);
	if (!data->win_ptr)
	{
		free(data);
		return (NULL);
	}

	return (data);
}