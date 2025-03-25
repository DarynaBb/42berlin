#include "fractol.h"
#include <stdlib.h>
#include <stdio.h>

// int main()
// {
// 	void	*mlx_connection;
// 	void	*mlx_window;

// 	mlx_connection = mlx_init();
// 	mlx_window = mlx_new_window(mlx_connection, 
// 								WIDTH, HEIGHT, 
// 								"My *1 window");

	
// 	for (int y = HEIGHT * 0.1; y < HEIGHT * 0.9; ++y)
// 	{
// 		for (int x = WIDTH * 0.1; x < WIDTH * 0.9; ++x)
// 		{
// 			mlx_pixel_put(mlx_connection, mlx_window, x, y, rand() % 0x1000000);
// 		}
// 	}
// 	mlx_string_put(mlx_connection, mlx_window, WIDTH * 0.8, HEIGHT * 0.95, rand() % 0x1000000, "My polloc");
// 	mlx_loop(mlx_connection);
// 	return(0);
// }


// int	main(void)
// {
// 	void	*mlx_connection;
// 	void	*mlx_window;

// 	mlx_connection = mlx_init();
// 	if (mlx_connection == NULL)
// 		return (1);
// 	mlx_window = mlx_new_window(mlx_connection, WIDTH, HEIGHT, "Fractol");
// 	if (mlx_window == NULL)
// 	{
// 		mlx_destroy_display(mlx_connection);
// 		free(mlx_connection);
// 		return(1);
// 	}
// 	mlx_loop(mlx_connection);
// 	mlx_destroy_display(mlx_connection); // to exit in a clean way
// 	free(mlx_connection);

// }

int	handle_input(int keysum, t_mlx_data *data)
{
	if (keysum == XK_Escape)
	{
		printf("The %d key (ESC) has been pressed\n\n", keysum);
		mlx_destroy_window(data->mlx_ptr, data->win_ptr);
		mlx_destroy_display(data->mlx_ptr);
		free(data->mlx_ptr);
		exit(1);
	}
	printf("The %d key has been pressed\n\n", keysum);
	return(0);
}

int	main(void)
{
	t_mlx_data data;
	data.mlx_ptr = mlx_init();
	if (data.mlx_ptr == NULL)
		return(1);
	data.win_ptr = mlx_new_window(data.mlx_ptr, WIDTH, HEIGHT, "Fractol");
	if (data.win_ptr == NULL)
	{
		mlx_destroy_display(data.mlx_ptr);
		free(data.mlx_ptr);
		return(1);
	}
	mlx_key_hook(data.win_ptr, handle_input, &data);
	mlx_hook(data.win_ptr, ButtonPress,)
	mlx_loop(data.mlx_ptr);
}