
#include "fdf.h"

t_point	*get_points(int x, int y, int x1, int y1)
{
	t_point		*lines;
	lines = malloc(sizeof(t_point));
	if (!lines)
		return (0);
	lines->x0 = x;
	lines->y0 = y;
	lines->x1 = x1;
	lines->y1 = y1;
	return (lines);
}

// void f()
// {
// 	system("leaks fdf");
// }

int	main(int ac, char **av)
{
	t_map_data	*data;
	t_data	img;
    int	x;
	int	y;

	// atexit(f);
	if (ac == 2)
	{
		data = (t_map_data*)malloc(sizeof(t_map_data) + 20);
		if (!data)
			return (0);
		data->zoom = 20;
		data->mlx = mlx_init();
		data->mlx_win = mlx_new_window(data->mlx, 1500, 1500, "Hello lina!");
		img.img = mlx_new_image(data->mlx, 1500, 1500);
		img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length,
									&img.endian);
		read_map(av[1], data, -1, 0);
		y = 0;
		while (y < data->height)
		{
			x = 0;
			while(x < data->width)
			{
				if (x < data->width - 1)
					drawline(data, get_points(x, y, x + 1, y), &img);
				if (y < data->height - 1)
					drawline(data, get_points(x, y, x, y + 1), &img);
				x++;
			}
			y++;
		}
		mlx_loop(data->mlx);
	}
}
