#include "../include/init.h"

/**
 * @brief Initialize the MLX library and create a new window.
 *
 * This function initializes the MLX library and creates a new window.
 * It takes a pointer to a pointer of the window address from the main function.
 *
 * @param win_ptr A pointer to a pointer that will hold the address of the new window.
 * @return A pointer to the initialized MLX instance.
 */


//t_data *init_mlx()
//{
//    t_data *data = malloc(sizeof(t_data));
//    if (!data)
//		return (NULL);
//
//    data->mlx_ptr = mlx_init();
//    if (!data->mlx_ptr)
//	{
//		free(data);
//        return (NULL);
//    }
//
//    data->win_ptr = mlx_new_window(data->mlx_ptr, 500, 500, "Window");
//    if (!data->win_ptr)
//	{
//        free(data);
//        return (NULL);
//    }
//
//    return (data);
//}