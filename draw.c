
#include "fdf.h"

t_point	*get_points(int x, int y)
{
	t_point		*lines;

	lines = malloc(sizeof(t_point));
	if (!lines)
		return (0);
	lines->x = x;
	lines->y = y;
	return (lines);
}

void	draw(t_fdf_data	*data)
{
	int	x;
	int	y;

	y = 0;
	while (y < data->height)
	{
		x = 0;
		while (x < data->width)
		{
			if (x < data->width - 1)
				drawline(data, get_points(x, y), get_points(x + 1, y));
			if (y < data->height - 1)
				drawline(data, get_points(x, y), get_points(x, y + 1));
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(data->mlx, data->mlx_win, data->img, 0,0);
}
